/*
Copyright (C) %{CURRENT_YEAR} by %{AUTHOR} <%{EMAIL}>

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of
the License or (at your option) version 3 or any later version
accepted by the membership of KDE e.V. (or its successor approved
by the membership of KDE e.V.), which shall act as a proxy 
defined in Section 14 of version 3 of the license.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// application headers
#include "verembalsesview.hpp"

#include "VerEmbalsesSettings.h"
#include "verembalsesdebug.h"

#include "constants.hpp"
#include "tablemodel.hpp"
#include <QMessageBox>
#include <QTimer>
#include <QFileDialog>

#include <KLocalizedString>

#include <spdlog/spdlog.h>

#include "configuracion.hpp"

using namespace std;
using namespace FuncionesUi;

VerEmbalsesView::VerEmbalsesView(QWidget* parent) : View(parent)
{
    initView();
}

void VerEmbalsesView::setup() {
    m_ui.setupUi(this);
}

void VerEmbalsesView::connectEvents() {
    connect(m_ui.cmbZona, QOverload<int>::of(&QComboBox::activated), this, &VerEmbalsesView::cmbZonasIndexChanged);
    connect(m_ui.cmbPlvZona, QOverload<int>::of(&QComboBox::activated), this, &VerEmbalsesView::cmbPlvZonasIndexChanged);
    connect(m_ui.cmbEmbalse, QOverload<int>::of(&QComboBox::activated), this, &VerEmbalsesView::cmbEmbalsesIndexChanged);
    connect(m_ui.cmbPuntoControl, QOverload<int>::of(&QComboBox::activated), this, &VerEmbalsesView::cmbPuntosControlIndexChanged);
    connect(m_ui.btnVerGrafico , &QAbstractButton::clicked, this, &VerEmbalsesView::showGraphicClicked);
    connect(m_ui.btnVerEmbalses , &QAbstractButton::clicked, this, &VerEmbalsesView::showEmbalsesClicked);
    connect(m_ui.btnExportarCSV , &QAbstractButton::clicked, this, &VerEmbalsesView::showExcelClicked);
}

void VerEmbalsesView::delayedInitialization() {
        try {
        AppContext& context = AppContext::getInstance();
        string lastExecution = context.getLastExecution();

        Configuracion& configuracion = Configuracion::getInstance();
        std::map<std::string, std::string> properties = configuracion.getProperties();
        zona = properties["zonaSelected"];
        embalse = properties["embalseSelected"];

        context.populateZonasIn(m_ui.cmbZona);
        context.populateZonasIn(m_ui.cmbPlvZona);

        context.setDefaultZona(zona, m_ui.cmbZona, m_ui.cmbEmbalse);
        InfoZona infoZona = context.getZona(zona);
        m_ui.lblZona->setText(qtHelper.asQString(infoZona.nombre));
        showStatsPorZona(zona, lastExecution);

        context.setDefaultEmbalse(embalse, m_ui.cmbEmbalse);

        InfoEmbalse infoEmbalse = context.getEmbalseInfoByDate(embalse, lastExecution);
        showInfoEmbalse(infoEmbalse);

        setStatus(lastExecution);
    } catch (const std::exception &e) {
        spdlog::error(e.what());
    }
}

void VerEmbalsesView::cmbZonasIndexChanged(int index) {
    AppContext& context = AppContext::getInstance();
    string lastExecution = context.getLastExecution();
    
    zona = qtHelper.getStringValue(m_ui.cmbZona, index);

    if (!zona.empty()) {
        InfoZona info = context.getZona(zona);

        m_ui.lblZona->setText(qtHelper.asQString(info.nombre));
        showStatsPorZona(zona, lastExecution);
        context.populateEmbalsesIn(zona, m_ui.cmbEmbalse);

        string codigoEmbalse = qtHelper.getStringValue(m_ui.cmbEmbalse, 0);
        if (!codigoEmbalse.empty()) {
            InfoEmbalse info = context.getEmbalseInfoByDate(codigoEmbalse, context.getLastExecution());
            showInfoEmbalse(info);
        }
    }
    else {
        QMessageBox msgBox;
        msgBox.setText("Debe seleccionar una zona");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
    }
}

void VerEmbalsesView::cmbPlvZonasIndexChanged(int index) {
    AppContext& context = AppContext::getInstance();
    
    plvZona = qtHelper.getStringValue(m_ui.cmbPlvZona, index);

    if (!plvZona.empty()) {
        context.populatePuntosControlIn(plvZona, m_ui.cmbPuntoControl);
    }
    else {
        QMessageBox msgBox;
        msgBox.setText("Debe seleccionar una zona");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
    }
}

void VerEmbalsesView::cmbEmbalsesIndexChanged(int index) {
    AppContext& context = AppContext::getInstance();
    string lastExecution = context.getLastExecution();
    
    string codigoEmbalse = qtHelper.getStringValue(m_ui.cmbEmbalse, index);
    if (!codigoEmbalse.empty()) {
        InfoEmbalse info = context.getEmbalseInfoByDate(codigoEmbalse, lastExecution);
        showInfoEmbalse(info);
    }
}

void VerEmbalsesView::cmbPuntosControlIndexChanged(int index) {
    try {
        AppContext& context = AppContext::getInstance();
        
        string codigoPuntoControl = qtHelper.getStringValue(m_ui.cmbPuntoControl, index);
        
        if (!plvZona.empty()) {
            // Componer colección de consulta
            string puntoControl = "PL-" + plvZona + "-" + codigoPuntoControl;
            
            // Consultar los últmos 5 días
            QDateTime now = qtDateHelper.now();
            tuple<QDate, QDate> fechas = qtDateHelper.intervalBeforeInDays(now.date(), 5);
            QDate fechaHasta = get<0>(fechas);
            QDate fechaDesde = get<1>(fechas);
            Dataframe df = context.getDataframePuntoControl(puntoControl, fechaDesde, fechaHasta);
            
            // Mostrar en tabla
            if (!df.empty()) {
                TableModel *tableModel = new TableModelRegistrosPluviometricos(df);
                spdlog::info("Change model");
                m_ui.tableView->setModel(tableModel);
            }
        }
    } catch (const exception& e) {
        QMessageBox msgBox;
        msgBox.setText(e.what());
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
    }
}

void VerEmbalsesView::showGraphicClicked() {
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
            Dataframe df = context.getDataframePorEmbalseYRangoFechas(codEmbalse, fechaDesde, fechaHasta);
            
            // Remove the columns MEN and Capacidad
            df.remove_column<double>("MEN");
            df.remove_column<double>("Capacidad");
            
            unique_ptr<DlgShowLineGraphic> dlgShowGraphic = unique_ptr<DlgShowLineGraphic>{new DlgShowLineGraphic(this)};
            dlgShowGraphic->setData(df);
            dlgShowGraphic->mostrar(true);
        }
    }
}

void VerEmbalsesView::showEmbalsesClicked() {
    AppContext& context = AppContext::getInstance();
    string lastExecution = context.getLastExecution();
    Dataframe df = context.getDataframeEmbalsesZonaAndDate(zona, lastExecution);

    unique_ptr<DlgShowTable> dlgShowTable = unique_ptr<DlgShowTable>{new DlgShowTable(df, zona, Constants::EMBALSES, this)};
    dlgShowTable->mostrar(true);
}

void VerEmbalsesView::showExcelClicked() {
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
            Dataframe df = context.getDataframePorEmbalseYRangoFechas(codEmbalse, fechaDesde, fechaHasta);
        
            const string& filetype = Constants::CSV_FILE_TYPE;
            const QString filename = QFileDialog::getSaveFileName(this, i18n("Save File As"), QDir::currentPath(), qtHelper.asQString(filetype));
            context.saveDataframeToDisk(filename, df);
        }
    }
}

unique_ptr<DlgSelectFecha> VerEmbalsesView::getDlgFecha() {
    string codigoZona = qtHelper.getStringValue(m_ui.cmbZona);
    string codigoEmbalse = qtHelper.getStringValue(m_ui.cmbEmbalse);
        
    unique_ptr<DlgSelectFecha> dlg = unique_ptr<DlgSelectFecha>{new DlgSelectFecha(codigoZona, codigoEmbalse, this)};
    
    return dlg;
}

void VerEmbalsesView::showInfoEmbalse(InfoEmbalse& info) {
    
    m_ui.lblNombreEmbalse->setText(qtHelper.asQString(info.embalse));
    
    std::string sPercent = formatter.formatNumber(info.porcentaje);
    m_ui.lblPercent->setText(qtHelper.asQString(sPercent));
    helper.setLabelStyleValue(m_ui.lblPercent, info.porcentaje);
    
    std::string sCapacidad = formatter.formatNumber(info.capacidad);
    m_ui.lblCapacidad->setText(qtHelper.asQString(sCapacidad));
    
    std::string sVolumen = formatter.formatNumber(info.volumen); // s == "3.14"
    m_ui.lblVolumen->setText(qtHelper.asQString(sVolumen));
}

void VerEmbalsesView::showStatsPorZona(string codZona, string date) {
    try {
        AppContext& context = AppContext::getInstance();
        
        std::tuple<double*, double*> stats = context.getStatsPorZonaYFecha(codZona, date);
        
        std::string sMedia = formatter.formatNumber(get<0>(stats)[0]);
        m_ui.lblNivelMedia->setText(qtHelper.asQString(sMedia));
        
        sMedia = formatter.formatNumber(get<1>(stats)[0]);
        m_ui.lblVolumenMedia->setText(qtHelper.asQString(sMedia));
        
        std::string sMinimo = formatter.formatNumber(get<0>(stats)[1]);
        m_ui.lblNivelMinimo->setText(qtHelper.asQString(sMinimo));
        
        sMinimo = formatter.formatNumber(get<1>(stats)[1]);
        m_ui.lblVolumenMinimo->setText(qtHelper.asQString(sMinimo));
        
        std::string sMax = formatter.formatNumber(get<0>(stats)[2]);
        m_ui.lblNivelMaximo->setText(qtHelper.asQString(sMax));
        
        sMax = formatter.formatNumber(get<1>(stats)[2]);
        m_ui.lblVolumenMaximo->setText(qtHelper.asQString(sMax));

        double volumenTotal = get<1>(stats)[3];
        std::string sSum = formatter.formatNumber(volumenTotal);
        m_ui.lblVolumenTotal->setText(qtHelper.asQString(sSum));

        double totalCapacidad = context.getTotalCapacidadZona(codZona);
        std::string sTotalCapacidad = formatter.formatNumber(totalCapacidad);
        m_ui.lblTotalCapacidadZona->setText(qtHelper.asQString(sTotalCapacidad));

        double porcentajeVolumen = (volumenTotal*100)/totalCapacidad;
        std::string sPorcentajeVolumen = formatter.formatNumber(porcentajeVolumen);
        m_ui.lblPorcentajeVolumenTotal->setText(qtHelper.asQString(sPorcentajeVolumen));
        helper.setLabelStyleValue(m_ui.lblPorcentajeVolumenTotal, porcentajeVolumen);
    } catch (const exception& e) {
        spdlog::error("ERROR getStatsPorZona: {}", e.what());
        throw e;
    }
}

void VerEmbalsesView::setStatus(string date) {
    try {
        string label = "Datos a fecha: " + date;
        updateToObservers(label);
    } catch (const exception& e) {
        spdlog::error(e.what());
        throw (e);
    }
}

VerEmbalsesView::~VerEmbalsesView()
{
}



