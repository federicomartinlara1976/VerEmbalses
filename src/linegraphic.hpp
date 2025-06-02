#ifndef __LINEGRAPHIC_HPP__
#define __LINEGRAPHIC_HPP__

#include "graphic.hpp"
#include "funciones_ui.hpp"
#include "VerEmbalsesAppHelper.hpp"

#include <QtCharts/QChartView>

using namespace QtCharts;
using namespace FuncionesUi;

class GraficoEnLinea : public GraphicStrategy {
private:
    QtHelper qtHelper;
    AppHelper appHelper;

    Dataframe df;

    QChart* graphic;

public:
    GraficoEnLinea(Dataframe &df, string yValue);
    QChart* getGraphic() override { return graphic; }
    
    ~GraficoEnLinea();
};

#endif
