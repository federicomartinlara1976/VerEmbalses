#include "showpiegraphic.hpp"
#include "sectorgraphic.hpp"
#include "stackedbargraphic.hpp"

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
}

void DlgShowPieGraphic::delayedInitialization() {}

void DlgShowPieGraphic::onClose() {}

void DlgShowPieGraphic::onAccept() {}

void DlgShowPieGraphic::setData(const FuncionesUi::StringDataframe& df) {
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

