#include <spdlog/spdlog.h>
#include <iostream>
#include <QTimer>

#include <qttools/config.hpp>

#include "verembalses.hpp"
#include "constants.hpp"

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
    AppContext& context = AppContext::getInstance();
    
    Configuration& config_instance = Configuration::getInstance(); 
    YAML::Node config = config_instance.getConfiguration();
    string zona = config["zona.selected"].as<string>();
    string embalse = config["embalse.selected"].as<string>();
    
    context.populateZonas(cmbZona);
    
    context.setZonaDefecto(zona, cmbZona, cmbEmbalse);
    showStatsPorZona(zona);
    
    context.setEmbalseDefecto(embalse, cmbEmbalse);
    
    InfoEmbalse info = context.getLastEmbalseInfo(embalse);
    showInfoEmbalse(info);
    
    setStatus();
    
    spdlog::info("VerEmbalses cargado en memoria");
}

void VerEmbalses::cmbZonasIndexChanged(int index) {
    AppContext& context = AppContext::getInstance();
    
    showStatsPorZona(helper.getStringValue(cmbZona, index));
    context.populateEmbalses(helper.getStringValue(cmbZona, index), this->cmbEmbalse);
    
    string codigoEmbalse = helper.getStringValue(cmbEmbalse, 0);
    
    InfoEmbalse info = context.getLastEmbalseInfo(codigoEmbalse);
    showInfoEmbalse(info);
}

void VerEmbalses::cmbEmbalsesIndexChanged(int index) {
    AppContext& context = AppContext::getInstance();
    
    string codigoEmbalse = helper.getStringValue(cmbEmbalse, index);
    
    InfoEmbalse info = context.getLastEmbalseInfo(codigoEmbalse);
    showInfoEmbalse(info);
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
        string codEmbalse = get<1>(datosEmbalse);
        
        if (codZona.empty() || codEmbalse.empty())
            return;
        
        unique_ptr<DlgShowTable> dlgShowTable = unique_ptr<DlgShowTable>{new DlgShowTable(this)};
        dlgShowTable->setCodEmbalse(codEmbalse);
        dlgShowTable->setFechas(get<0>(fechas), get<1>(fechas));
        dlgShowTable->setData(context.getDataframe(codEmbalse, get<0>(fechas), get<1>(fechas)));
        dlgShowTable->mostrar(true);
    }
}

void VerEmbalses::estadisticasDiarias() {
    DlgProgreso* dlg = new DlgProgreso(this);
    dlg->show();
    
    QLoadJob* j1 = new QLoadJob();
    
    // Queue the Job using the default Queue stream:
    stream() << j1;
}

void VerEmbalses::estadisticasMensuales() {
    unique_ptr<DlgSelectMes> dlg = getDlgMes();
    int result = dlg->mostrar(true);
    
    if (result == 1) {
        tuple<int, string> mes = dlg->getMes();
    }
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

void VerEmbalses::showStatsPorZona(string codZona) {
    try {
        AppContext& context = AppContext::getInstance();
        
        Dataframe df = context.getDataframeZona(codZona);
        
        MeanVisitor<double, unsigned long> mean_v;
        MinVisitor<double, unsigned long> min_v;
        MaxVisitor<double, unsigned long> max_v;

        df.visit<double>("Nivel", mean_v);
        std::string sMedia = fmt::format(Constants::NUMBER_FORMAT, mean_v.get_result());
        lblNivelMedia->setText(helper.asQString(sMedia));
        
        df.visit<double>("Volumen", mean_v);
        sMedia = fmt::format(Constants::NUMBER_FORMAT, mean_v.get_result());
        lblVolumenMedia->setText(helper.asQString(sMedia));
        
        df.visit<double>("Nivel", min_v);
        std::string sMinimo = fmt::format(Constants::NUMBER_FORMAT, min_v.get_result());
        lblNivelMinimo->setText(helper.asQString(sMinimo));
        
        df.visit<double>("Volumen", min_v);
        sMinimo = fmt::format(Constants::NUMBER_FORMAT, min_v.get_result());
        lblVolumenMinimo->setText(helper.asQString(sMinimo));
        
        df.visit<double>("Nivel", max_v);
        std::string sMax = fmt::format(Constants::NUMBER_FORMAT, max_v.get_result());
        lblNivelMaximo->setText(helper.asQString(sMax));
        
        df.visit<double>("Volumen", max_v);
        sMax = fmt::format(Constants::NUMBER_FORMAT, max_v.get_result());
        lblVolumenMaximo->setText(helper.asQString(sMax));
    } catch (const exception& e) {
        spdlog::error("ERROR getStatsPorZona: {}", e.what());
        throw e;
    }
}

void VerEmbalses::setStatus() {
    try {
        AppContext& context = AppContext::getInstance();
        
        string last = context.getLastExecution();
        
        string label = "Datos a fecha: " + last;
        statusbar->showMessage(helper.asCharArray(label));
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
