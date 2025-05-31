#include "showscattergraphic.hpp"
#include "scattergraphic.hpp"

#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QtGui/QPainter>
#include <iostream>

using namespace std;

DlgShowScatterGraphic::DlgShowScatterGraphic(Constants::GraphType &graphType, QWidget* parent) : QtDialogWindow(parent) {
    this->graphType = graphType;
    this->initWindow();
}

void DlgShowScatterGraphic::setup() {
    setupUi(this);
}

void DlgShowScatterGraphic::connectEvents() {
    connect(btnClose, &QAbstractButton::clicked, this, &DlgShowScatterGraphic::accept);
    connect(btnPrint, &QAbstractButton::clicked, this, &DlgShowScatterGraphic::print);
}

void DlgShowScatterGraphic::delayedInitialization() {}

void DlgShowScatterGraphic::onClose() {}

void DlgShowScatterGraphic::onAccept() {}

void DlgShowScatterGraphic::print() {
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

void DlgShowScatterGraphic::setData(const FuncionesUi::Dataframe& df) {
    this->df = df;

    //auto columns = this->df.get_columns_info<double, string>();

    drawGraphic();
}

void DlgShowScatterGraphic::drawGraphic() {
    if (chartView->chart() != nullptr) {
        chartView->chart()->removeAllSeries();
    }

    if (graphType == Constants::GraphType::RELACION_NIVEL_VOLUMEN) {
        GraphicContext graphicContext1(std::make_unique<GraficoEnNubePuntosNivelVolumen>(df));
        chartView->setChart(graphicContext1.getGraphic());
    }
    if (graphType == Constants::GraphType::RELACION_NIVEL_PORCENTAJE) {
        GraphicContext graphicContext1(std::make_unique<GraficoEnNubePuntosNivelPorcentaje>(df));
        chartView->setChart(graphicContext1.getGraphic());
    }
    if (graphType == Constants::GraphType::RELACION_VOLUMEN_PORCENTAJE) {
        GraphicContext graphicContext2(std::make_unique<GraficoEnNubePuntosVolumenPorcentaje>(df));
        chartView->setChart(graphicContext2.getGraphic());
    }
    
    chartView->repaint();
}

DlgShowScatterGraphic::~DlgShowScatterGraphic() {}


