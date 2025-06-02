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
    
    ~GraficoEnNubePuntos();
};

class GraficoEnNubePuntosNivelVolumen : public GraficoEnNubePuntos {
private:
public:
    GraficoEnNubePuntosNivelVolumen(Dataframe &df);
    ~GraficoEnNubePuntosNivelVolumen();
};

class GraficoEnNubePuntosNivelPorcentaje : public GraficoEnNubePuntos {
private:
public:
    GraficoEnNubePuntosNivelPorcentaje(Dataframe &df);
    ~GraficoEnNubePuntosNivelPorcentaje();
};

class GraficoEnNubePuntosVolumenPorcentaje : public GraficoEnNubePuntos {
private:
public:
    GraficoEnNubePuntosVolumenPorcentaje(Dataframe &df);
    ~GraficoEnNubePuntosVolumenPorcentaje();
};

#endif
