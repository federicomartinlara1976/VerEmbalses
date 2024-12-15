#include "showpiegraphic.hpp"
#include "sectorgraphic.hpp"
#include "stackedbargraphic.hpp"

#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QtGui/QPainter>

using namespace std;

DlgShowPieGraphic::DlgShowPieGraphic(QWidget* parent) : QtDialogWindow(parent) {
    this->initWindow();
}

void DlgShowPieGraphic::setup() {
    setupUi(this);
}

void DlgShowPieGraphic::connectEvents() {
    connect(rbtGlobal, &QAbstractButton::clicked, this, &DlgShowPieGraphic::drawGraphic);
    connect(rbtDetalles, &QAbstractButton::clicked, this, &DlgShowPieGraphic::drawGraphic);
    connect(btnClose, &QAbstractButton::clicked, this, &DlgShowPieGraphic::accept);
    connect(btnPrint, &QAbstractButton::clicked, this, &DlgShowPieGraphic::print);
}

void DlgShowPieGraphic::delayedInitialization() {}

void DlgShowPieGraphic::onClose() {}

void DlgShowPieGraphic::onAccept() {}

void DlgShowPieGraphic::print() {
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

void DlgShowPieGraphic::setData(const FuncionesUi::Dataframe& df) {
    this->df = df;

    auto columns = this->df.get_columns_info<double, string>();

    drawGraphic();
}

void DlgShowPieGraphic::drawGraphic() {
    if (chartView->chart() != nullptr) {
        chartView->chart()->removeAllSeries();
    }

    GraphicContext graphicContext(nullptr);

    if (rbtGlobal->isChecked()) {
        graphicContext.set_strategy(std::make_unique<GraficoEnSectores>(df));
    }
    else {
        graphicContext.set_strategy(std::make_unique<GraficoEnBarrasApiladas>(df));
    }

    chartView->setChart(graphicContext.getGraphic());
    chartView->repaint();
}

DlgShowPieGraphic::~DlgShowPieGraphic() {}

