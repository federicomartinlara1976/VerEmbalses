#ifndef __SCATTERGRAPHIC_HPP__
#define __SCATTERGRAPHIC_HPP__

#include "graphic.hpp"
#include "funciones_ui.hpp"
#include "VerEmbalsesAppHelper.hpp"

#include <QtCharts/QChartView>

using namespace QtCharts;
using namespace FuncionesUi;

class GraficoEnNubePuntos : public GraphicStrategy {
private:
    QtHelper qtHelper;
    AppHelper appHelper;

    StringDataframe df;

    QChart* graphic;

public:
    GraficoEnNubePuntos(StringDataframe &df);
    QChart* getGraphic() const override { return graphic; }
};

#endif
