#ifndef __LINEGRAPHIC_HPP__
#define __LINEGRAPHIC_HPP__

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

    StringDataframe df;

    QChart* graphic;

public:
    GraficoEnSectores(StringDataframe &df);
    QChart* getGraphic() const override { return graphic; }
};

#endif
