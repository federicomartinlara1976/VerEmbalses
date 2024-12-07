#include "showpiegraphic.hpp"
#include "sectorgraphic.hpp"

using namespace std;

DlgShowPieGraphic::DlgShowPieGraphic(QWidget* parent) : QtDialogWindow(parent) {
    this->initWindow();
}

void DlgShowPieGraphic::setup() {
    setupUi(this);
}

void DlgShowPieGraphic::connectEvents() {}

void DlgShowPieGraphic::delayedInitialization() {}

void DlgShowPieGraphic::setData(const FuncionesUi::StringDataframe& df) {
    this->df = df;

    auto columns = this->df.get_columns_info<double, string>();

    drawGraphic();
}

void DlgShowPieGraphic::drawGraphic() {
    if (chartView->chart() != nullptr) {
        chartView->chart()->removeAllSeries();
    }

    GraphicContext graphicContext(std::make_unique<GraficoEnSectores>(df));
    chartView->setChart(graphicContext.getGraphic());
    chartView->repaint();
}

DlgShowPieGraphic::~DlgShowPieGraphic() {}

