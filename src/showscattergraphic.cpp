#include "showscattergraphic.hpp"
#include "scattergraphic.hpp"

using namespace std;

DlgShowScatterGraphic::DlgShowScatterGraphic(QWidget* parent) : QtDialogWindow(parent) {
    this->initWindow();
}

void DlgShowScatterGraphic::setup() {
    setupUi(this);
}

void DlgShowScatterGraphic::connectEvents() {}

void DlgShowScatterGraphic::delayedInitialization() {}

void DlgShowScatterGraphic::onClose() {}

void DlgShowScatterGraphic::onAccept() {}

void DlgShowScatterGraphic::setData(const FuncionesUi::StringDataframe& df) {
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


