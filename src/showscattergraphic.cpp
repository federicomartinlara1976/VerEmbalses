#include "showscattergraphic.hpp"
#include "scattergraphic.hpp"

#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QtGui/QPainter>

using namespace std;

DlgShowScatterGraphic::DlgShowScatterGraphic(QWidget* parent) : QtDialogWindow(parent) {
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

    auto columns = this->df.get_columns_info<double, string>();

    drawGraphic();
}

void DlgShowScatterGraphic::drawGraphic() {
    if (chartView->chart() != nullptr) {
        chartView->chart()->removeAllSeries();
    }

    GraphicContext graphicContext(std::make_unique<GraficoEnNubePuntos>(df));
    chartView->setChart(graphicContext.getGraphic());
    chartView->repaint();
}

DlgShowScatterGraphic::~DlgShowScatterGraphic() {}


