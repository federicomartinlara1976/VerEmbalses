#include "scattergraphic.hpp"

#include <QtCharts/QScatterSeries>
#include <QtCharts/QValueAxis>

GraficoEnNubePuntos::GraficoEnNubePuntos(StringDataframe &df) {
    this->df = df;

    QScatterSeries *series = new QScatterSeries();
    series->setName("scatter1");
    series->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series->setMarkerSize(10.0);

    vector<double> niveles = df.get_column<double>("Nivel");
    vector<double> volumenes = df.get_column<double>("Volumen");

    int i = 0;
    for (double nivel : niveles) {
        double volumen = volumenes[i];
        series->append(nivel, volumen);
        i++;
    }

    graphic = new QChart();
    graphic->addSeries(series);
    graphic->setAnimationOptions(QChart::SeriesAnimations);

    QValueAxis *axisX = new QValueAxis();
    axisX->setTitleText("Nivel");
    axisX->setLabelFormat("%f");
    graphic->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Volumen");
    axisY->setLabelFormat("%f");
    graphic->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    graphic->setDropShadowEnabled(false);
    graphic->legend()->setVisible(true);
    graphic->legend()->setAlignment(Qt::AlignRight);

}


