#ifndef __STACKEDBARGRAPHIC_HPP__
#define __STACKEDBARGRAPHIC_HPP__

#include "graphic.hpp"
#include "funciones_ui.hpp"
#include "VerEmbalsesAppHelper.hpp"

#include <QtCharts/QChartView>

using namespace QtCharts;
using namespace FuncionesUi;

class GraficoEnBarrasApiladas : public GraphicStrategy {
private:
    QtHelper qtHelper;
    AppHelper appHelper;

    StringDataframe df;

    QChart* graphic;

public:
    GraficoEnBarrasApiladas(StringDataframe &df);
    QChart* getGraphic() const override { return graphic; }
};

#endif
