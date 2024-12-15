#include <iostream>

#include "showlinegraphic.hpp"
#include "constants.hpp"
#include "linegraphic.hpp"

using namespace std;

DlgShowLineGraphic::DlgShowLineGraphic(QWidget* parent) : QtDialogWindow(parent) {
    this->initWindow();
}

void DlgShowLineGraphic::setup() {
    setupUi(this);
}

void DlgShowLineGraphic::connectEvents() {
    connect(cmbDatoY, QOverload<int>::of(&QComboBox::activated), this, &DlgShowLineGraphic::cmbDatoYIndexChanged);
    connect(btnClose, &QAbstractButton::clicked, this, &DlgShowLineGraphic::accept);
}

void DlgShowLineGraphic::delayedInitialization() {}

void DlgShowLineGraphic::onClose() {}

void DlgShowLineGraphic::onAccept() {}

void DlgShowLineGraphic::setData(const FuncionesUi::Dataframe& df) {
    this->df = df;
    
    auto columns = this->df.get_columns_info<double, string>();
    
    populateDatoY("Fecha");
    
    selectedYValue = qtHelper.getStringValue(cmbDatoY);
    drawGraphic(selectedYValue);
}

void DlgShowLineGraphic::cmbDatoYIndexChanged(int index) {
    string selectedValue = qtHelper.getStringValue(cmbDatoY, index);
    drawGraphic(selectedValue);
}

void DlgShowLineGraphic::populateDatoY(std::string exclude) {
    auto columns = df.get_columns_info<double, string>();

    cmbDatoY->clear();
    for (auto citer: columns)  {
        string nombre = std::get<0>(citer).c_str();
        
        if (nombre != exclude) {
            const QString label = qtHelper.asQString(nombre, true);
            const QVariant value = QVariant(qtHelper.asQString(nombre, true));

            cmbDatoY->addItem(label, value);
        }
    }
}

void DlgShowLineGraphic::drawGraphic(string selectedYValue) {
    if (chartView->chart() != nullptr) {
        chartView->chart()->removeAllSeries();
    }
    
    GraphicContext graphicContext(std::make_unique<GraficoEnLinea>(df, selectedYValue));
    chartView->setChart(graphicContext.getGraphic());
    chartView->repaint();
}

DlgShowLineGraphic::~DlgShowLineGraphic() {}
