#include <spdlog/spdlog.h>
#include <iostream>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QDateTimeAxis>

#include "showgraphic.hpp"
#include "constants.hpp"

using namespace std;

DlgShowGraphic::DlgShowGraphic(QWidget* parent) : QtDialogWindow(parent) {
    this->initWindow();
}

void DlgShowGraphic::setup() {
    setupUi(this);
}

void DlgShowGraphic::connectEvents() {
    connect(cmbDatoX, QOverload<int>::of(&QComboBox::activated), this, &DlgShowGraphic::cmbDatoXIndexChanged);
    connect(cmbDatoY, QOverload<int>::of(&QComboBox::activated), this, &DlgShowGraphic::cmbDatoYIndexChanged);
}

void DlgShowGraphic::delayedInitialization() {}

void DlgShowGraphic::setData(const FuncionesUi::Dataframe& dataframe) {
    this->dataframe = dataframe;
    
    auto columns = this->dataframe.get_columns_info<double, string>();

    for (auto citer: columns)  {
        if (std::get<0>(citer) == "Fecha") {
            string nombre = std::get<0>(citer).c_str();
        
            const QString label = qtHelper.asQString(nombre, true);
            const QVariant value = QVariant(qtHelper.asQString(nombre, true));
            
            cmbDatoX->addItem(label, value);
        }
    }
    
    selectedXValue = qtHelper.getStringValue(cmbDatoX);
    populateDatoY(selectedXValue);
    
    selectedYValue = qtHelper.getStringValue(cmbDatoY);
    drawGraphic(selectedXValue, selectedYValue);
}

void DlgShowGraphic::cmbDatoXIndexChanged(int index) {
    selectedXValue = qtHelper.getStringValue(cmbDatoX, index);
    populateDatoY(selectedXValue);
    drawGraphic(selectedXValue, selectedYValue);
}

void DlgShowGraphic::cmbDatoYIndexChanged(int index) {
    string selectedValue = qtHelper.getStringValue(cmbDatoY, index);
    drawGraphic(selectedXValue, selectedValue);
}

void DlgShowGraphic::populateDatoY(string exclude) {
    auto columns = dataframe.get_columns_info<double, string>();

    cmbDatoY->clear();
    for (auto citer: columns)  {
        string nombre = std::get<0>(citer).c_str();
        
        if (nombre.compare(exclude) != 0) {
            const QString label = qtHelper.asQString(nombre, true);
            const QVariant value = QVariant(qtHelper.asQString(nombre, true));
        
            cmbDatoY->addItem(label, value);
        }
    }
}

void DlgShowGraphic::drawGraphic(string selectedXValue, string selectedYValue) {
    if (chartView->chart() != nullptr) {
        chartView->chart()->removeAllSeries();
    }
    
    QLineSeries *series = new QLineSeries();
    
    QValueAxis *axisY = new QValueAxis();
    axisY->setTickCount(5);
    axisY->setMinorTickCount(1);
    axisY->setLabelFormat("%.2f");
    axisY->setTitleText(qtHelper.asQString(selectedYValue));

    QDateTimeAxis *axisX = new QDateTimeAxis(); // Using QValueAxis here instead makes the problem disappear.
    axisX->setFormat("dd-MM-yyyy");
    axisX->setLabelsAngle(-90);
    axisX->setTickCount(10);
     
    vector<string> fechas = dataframe.get_column<string>(appHelper.asCharArray(selectedXValue));
    vector<double> values = dataframe.get_column<double>(appHelper.asCharArray(selectedYValue));
     
    int i = 0;
    for (string fecha : fechas) {
        QString qFecha = qtHelper.asQString(fecha);
        QString qFormat = qtHelper.asQString(Constants::DATE_FORMAT);
        
        QDateTime momentInTime;
        momentInTime.setDate(QDate::fromString(qFecha, qFormat));
        double val = values[i];
        series->append(momentInTime.toMSecsSinceEpoch(), val);
    
        i++;
    }
    
    QChart* currentChart = new QChart();
    currentChart->addSeries(series);
    
    currentChart->addAxis(axisX, Qt::AlignBottom);
    currentChart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);  
    currentChart->legend()->hide();
    
    chartView->setChart(currentChart);
    chartView->repaint();
}

DlgShowGraphic::~DlgShowGraphic() {}
