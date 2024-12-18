#include <iostream>

#include "showlinegraphic.hpp"
#include "constants.hpp"
#include "linegraphic.hpp"

#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QtGui/QPainter>

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
    connect(btnPrint, &QAbstractButton::clicked, this, &DlgShowLineGraphic::print);
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

void DlgShowLineGraphic::print() {
    // Crear un objeto QPrinter
    QPrinter printer(QPrinter::HighResolution);

    // Mostrar el cuadro de diálogo de impresión
    QPrintDialog printDialog(&printer);
    if (printDialog.exec() == QDialog::Rejected) {
        return;
    }

    // Renderizar el gráfico en el dispositivo de impresión
    QPainter painter(&printer);
    chartView->render(&painter);
    painter.end();
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
