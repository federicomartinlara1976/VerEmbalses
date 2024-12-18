#ifndef __SECTORGRAPHIC_HPP__
#define __SECTORGRAPHIC_HPP__

#include "graphic.hpp"
#include "funciones_ui.hpp"
#include "VerEmbalsesAppHelper.hpp"

#include <QtCharts/QChartView>

using namespace QtCharts;
using namespace FuncionesUi;

class GraficoEnSectores : public GraphicStrategy {
private:
    QtHelper qtHelper;
    AppHelper appHelper;

    Dataframe df;

    QChart* graphic;

public:
    GraficoEnSectores(Dataframe &df);
    QChart* getGraphic() const override { return graphic; }
};

#endif
