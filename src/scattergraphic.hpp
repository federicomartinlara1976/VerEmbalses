#ifndef __SCATTERGRAPHIC_HPP__
#define __SCATTERGRAPHIC_HPP__

#include "graphic.hpp"
#include "funciones_ui.hpp"
#include "VerEmbalsesAppHelper.hpp"

#include <QtCharts/QChartView>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QValueAxis>

using namespace QtCharts;
using namespace FuncionesUi;

class GraficoEnNubePuntos : public GraphicStrategy {
private:
    QtHelper qtHelper;
    AppHelper appHelper;

protected:
    Dataframe df;
    QChart* graphic;
    
    QScatterSeries* series;
    
    QValueAxis *axisX;
    QValueAxis *axisY;

public:
    GraficoEnNubePuntos(Dataframe &df);
    QChart* getGraphic() override;
};

class GraficoEnNubePuntosNivelVolumen : public GraficoEnNubePuntos {
private:
public:
    GraficoEnNubePuntosNivelVolumen(Dataframe &df);
};

class GraficoEnNubePuntosVolumenPorcentaje : public GraficoEnNubePuntos {
private:
public:
    GraficoEnNubePuntosVolumenPorcentaje(Dataframe &df);
};

#endif
