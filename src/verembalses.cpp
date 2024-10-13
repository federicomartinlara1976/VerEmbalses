#include <spdlog/spdlog.h>
#include <iostream>
#include <QTimer>

#include <common/config.hpp>

#include "verembalses.hpp"
#include "constants.hpp"
#include <QMessageBox>

using namespace std;
using namespace FuncionesUi;

VerEmbalses::VerEmbalses(QWidget *parent) : QtWindow(parent) {
    this->initWindow();
}

void VerEmbalses::setup() {
    setupUi(this);
}

void VerEmbalses::connectEvents() {
    connect(cmbZona, QOverload<int>::of(&QComboBox::activated), this, &VerEmbalses::cmbZonasIndexChanged);
    connect(cmbEmbalse, QOverload<int>::of(&QComboBox::activated), this, &VerEmbalses::cmbEmbalsesIndexChanged);
    connect(btnVerGrafico , &QAbstractButton::clicked, this, &VerEmbalses::showGraphicClicked);
    connect(btnExportarCSV , &QAbstractButton::clicked, this, &VerEmbalses::showExcelClicked);
    connect(actionPor_fecha, &QAction::triggered, this, &VerEmbalses::buscarPorFechas);
    connect(actionDiaria, &QAction::triggered, this, &VerEmbalses::estadisticasDiarias);
    connect(actionMes, &QAction::triggered, this, &VerEmbalses::estadisticasMensuales);
}

void VerEmbalses::delayedInitialization() {
    try {
        QIcon icon;
        icon.addFile(QString::fromUtf8("/usr/share/icons/gnome/22x22/apps/ksysguard.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnExportarCSV->setIcon(icon);

        btnVerGrafico->setObjectName(QString::fromUtf8("btnVerGrafico"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("/usr/share/icons/Humanity/categories/22/redhat-office.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnVerGrafico->setIcon(icon1);

        btnExportarCSV->setToolTip(QApplication::translate("Dialog", "Exportar a CSV", nullptr));
        btnVerGrafico->setToolTip(QApplication::translate("Dialog", "Ver gr\303\241fico", nullptr));

        AppContext& context = AppContext::getInstance();
        string lastExecution = context.getLastExecution();

        Configuration& config_instance = Configuration::getInstance(applicationName);
        string zona = config_instance.getPropertyAsString("zona.selected");
        string embalse = config_instance.getPropertyAsString("embalse.selected");

        context.populateZonasIn(cmbZona);

        context.setDefaultZona(zona, cmbZona, cmbEmbalse);
        InfoZona infoZona = context.getZona(zona);
        lblZona->setText(helper.asQString(infoZona.nombre));
        showStatsPorZona(zona, lastExecution);

        context.setDefaultEmbalse(embalse, cmbEmbalse);

        InfoEmbalse infoEmbalse = context.getEmbalseInfoByDate(embalse, lastExecution);
        showInfoEmbalse(infoEmbalse);

        setStatus(lastExecution);

        spdlog::info("VerEmbalses cargado en memoria");
    } catch (const std::exception &e) {
        spdlog::error(e.what());
    }
}

void VerEmbalses::cmbZonasIndexChanged(int index) {
    AppContext& context = AppContext::getInstance();
    string lastExecution = context.getLastExecution();
    
    string value = helper.getStringValue(cmbZona, index);

    if (!value.empty()) {
        InfoZona info = context.getZona(value);

        lblZona->setText(helper.asQString(info.nombre));
        showStatsPorZona(value, lastExecution);
        context.populateEmbalsesIn(helper.getStringValue(cmbZona, index), this->cmbEmbalse);

        string codigoEmbalse = helper.getStringValue(cmbEmbalse, 0);
        if (!codigoEmbalse.empty()) {
            InfoEmbalse info = context.getEmbalseInfoByDate(codigoEmbalse, context.getLastExecution());
            showInfoEmbalse(info);
        }
        else {
            spdlog::info("Debe seleccionar un embalse");
        }
    }
    else {
        spdlog::info("Debe seleccionar una zona");
        QMessageBox msgBox;
        msgBox.setText("Debe seleccionar una zona");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
    }
}

void VerEmbalses::cmbEmbalsesIndexChanged(int index) {
    AppContext& context = AppContext::getInstance();
    string lastExecution = context.getLastExecution();
    
    string codigoEmbalse = helper.getStringValue(cmbEmbalse, index);
    if (!codigoEmbalse.empty()) {
        InfoEmbalse info = context.getEmbalseInfoByDate(codigoEmbalse, lastExecution);
        showInfoEmbalse(info);
    }
    else {
        spdlog::info("Debe seleccionar un embalse");
    }
}

void VerEmbalses::showGraphicClicked() {
    AppContext& context = AppContext::getInstance();
    
    unique_ptr<DlgSelectFecha> dlg = getDlgFecha();
    int result = dlg->mostrar(true);
    
    if (result == 1) {
        tuple<QDate, QDate> fechas = dlg->getFechas();
        tuple<string, string> datosEmbalse = dlg->getDatosEmbalse();
        QDate fechaDesde = get<0>(fechas);
        QDate fechaHasta = get<1>(fechas);
        string codZona = get<0>(datosEmbalse);
        string codEmbalse = get<1>(datosEmbalse);
        
        if (codZona.empty() || codEmbalse.empty())
            return;
    
        if (fechaDesde < fechaHasta) {
            Dataframe df = context.getDataframe(codEmbalse, fechaDesde, fechaHasta);
            
            // Remove the columns MEN and Capacidad
            df.remove_column("MEN");
            df.remove_column("Capacidad");
            
            unique_ptr<DlgShowGraphic> dlgShowGraphic = unique_ptr<DlgShowGraphic>{new DlgShowGraphic(this)};
            dlgShowGraphic->setData(df);
            dlgShowGraphic->mostrar(true);
        }
    }
}

void VerEmbalses::showExcelClicked() {
    AppContext& context = AppContext::getInstance();
    
    unique_ptr<DlgSelectFecha> dlg = getDlgFecha();
    int result = dlg->mostrar(true);
    
    if (result == 1) {
        tuple<QDate, QDate> fechas = dlg->getFechas();
        tuple<string, string> datosEmbalse = dlg->getDatosEmbalse();
        QDate fechaDesde = get<0>(fechas);
        QDate fechaHasta = get<1>(fechas);
        string codZona = get<0>(datosEmbalse);
        string codEmbalse = get<1>(datosEmbalse);
        
        if (codZona.empty() || codEmbalse.empty())
            return;
        
        if (fechaDesde < fechaHasta) {
            StdDataFrame<unsigned long> dataframe = context.getDataframe(codEmbalse, fechaDesde, fechaHasta);
        
            context.saveDataframe(dataframe, this);
        }
    }
}

void VerEmbalses::buscarPorFechas() {
    AppContext& context = AppContext::getInstance();
    
    unique_ptr<DlgSelectFecha> dlg = getDlgFecha(false);
    int result = dlg->mostrar(true);
    
    if (result == 1) {
        tuple<QDate, QDate> fechas = dlg->getFechas();
        tuple<string, string> datosEmbalse = dlg->getDatosEmbalse();
        string codZona = get<0>(datosEmbalse);

        if (!codZona.empty()) {
            string codEmbalse = get<1>(datosEmbalse);

            if (codZona.empty() || codEmbalse.empty())
                return;

            unique_ptr<DlgShowTable> dlgShowTable = unique_ptr<DlgShowTable>{new DlgShowTable(this)};
            dlgShowTable->setCodEmbalse(codEmbalse);
            dlgShowTable->setFechas(get<0>(fechas), get<1>(fechas));
            dlgShowTable->setData(context.getDataframe(codEmbalse, get<0>(fechas), get<1>(fechas)));
            dlgShowTable->mostrar(true);
        }
        else {
            QMessageBox msgBox;
            msgBox.setText("Debe seleccionar una zona");
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.exec();
        }
    }
}

void VerEmbalses::estadisticasDiarias() {
    DlgProgreso* dlg = new DlgProgreso(this);
    dlg->show();
    
    connect(dlg, &DlgProgreso::unblockingDialogDispatched, this, &VerEmbalses::progresoTerminado);
    
    j1 = new QLoadJob();
    
    // Queue the Job using the default Queue stream:
    stream() << j1;
}

void VerEmbalses::estadisticasMensuales() {
    unique_ptr<DlgSelectMes> dlg = getDlgMes();
    int result = dlg->mostrar(true);
    
    if (result == 1) {
        tuple<int, string> mes = dlg->getMes();
        spdlog::info("{}, {}", get<0>(mes), get<1>(mes));
    }
}

void VerEmbalses::progresoTerminado() {
    spdlog::info("Mostrar tabla");
}

unique_ptr<DlgSelectFecha> VerEmbalses::getDlgFecha(bool isSelectedZone) {
    unique_ptr<DlgSelectFecha> dlg;
    
    if (isSelectedZone) {
        string codigoZona = helper.getStringValue(cmbZona);
        string codigoEmbalse = helper.getStringValue(cmbEmbalse);
        
        dlg = unique_ptr<DlgSelectFecha>{new DlgSelectFecha(codigoZona, codigoEmbalse, this)};
    }
    else {
        dlg = unique_ptr<DlgSelectFecha>{new DlgSelectFecha(this)};
    }
    
    return dlg;
}

unique_ptr<DlgSelectMes> VerEmbalses::getDlgMes() {
    return unique_ptr<DlgSelectMes>{new DlgSelectMes(this)};
}

void VerEmbalses::showInfoEmbalse(InfoEmbalse& info) {
    
    lblNombreEmbalse->setText(helper.asQString(info.embalse));
    
    std::string sPercent = fmt::format(Constants::PERCENT_FORMAT, info.porcentaje);
    lblPercent->setText(helper.asQString(sPercent));
    helper.setLabelStyleValue(lblPercent, info.porcentaje);
    
    std::string sCapacidad = fmt::format(Constants::NUMBER_FORMAT, info.capacidad);
    lblCapacidad->setText(helper.asQString(sCapacidad));
    
    std::string sVolumen = fmt::format(Constants::NUMBER_FORMAT, info.volumen); // s == "3.14"
    lblVolumen->setText(helper.asQString(sVolumen));
}

void VerEmbalses::showStatsPorZona(string codZona, string date) {
    try {
        AppContext& context = AppContext::getInstance();
        
        std::tuple<double*, double*> stats = context.getStatsPorZonaYFecha(codZona, date);
        
        std::string sMedia = fmt::format(Constants::NUMBER_FORMAT, get<0>(stats)[0]);
        lblNivelMedia->setText(helper.asQString(sMedia));
        
        sMedia = fmt::format(Constants::NUMBER_FORMAT, get<1>(stats)[0]);
        lblVolumenMedia->setText(helper.asQString(sMedia));
        
        std::string sMinimo = fmt::format(Constants::NUMBER_FORMAT, get<0>(stats)[1]);
        lblNivelMinimo->setText(helper.asQString(sMinimo));
        
        sMinimo = fmt::format(Constants::NUMBER_FORMAT, get<1>(stats)[1]);
        lblVolumenMinimo->setText(helper.asQString(sMinimo));
        
        std::string sMax = fmt::format(Constants::NUMBER_FORMAT, get<0>(stats)[2]);
        lblNivelMaximo->setText(helper.asQString(sMax));
        
        sMax = fmt::format(Constants::NUMBER_FORMAT, get<1>(stats)[2]);
        lblVolumenMaximo->setText(helper.asQString(sMax));

        std::string sSum = fmt::format(Constants::NUMBER_FORMAT, get<0>(stats)[3]);
        lblNivelTotal->setText(helper.asQString(sSum));

        sSum = fmt::format(Constants::NUMBER_FORMAT, get<1>(stats)[3]);
        lblVolumenTotal->setText(helper.asQString(sSum));
    } catch (const exception& e) {
        spdlog::error("ERROR getStatsPorZona: {}", e.what());
        throw e;
    }
}

void VerEmbalses::setStatus(string date) {
    try {
        string label = "Datos a fecha: " + date;
        statusbar->showMessage(helper.asQString(label));
    } catch (const exception& e) {
        spdlog::error(e.what());
        throw (e);
    }
}

VerEmbalses::~VerEmbalses() {
    AppContext& instance = AppContext::getInstance();
    instance.destroyInstance();
    spdlog::info("VerEmbalses liberado de la memoria");
}
