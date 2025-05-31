#include "scattergraphic.hpp"

GraficoEnNubePuntos::GraficoEnNubePuntos(Dataframe &df) {
    this->df = df;

    series = new QScatterSeries();
    series->setName("nubePuntos");
    series->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series->setMarkerSize(10.0);
    
    graphic = new QChart();
    graphic->setAnimationOptions(QChart::SeriesAnimations);
    
    axisX = new QValueAxis();
    axisX->setLabelFormat("%f");
    graphic->addAxis(axisX, Qt::AlignBottom);
    
    axisY = new QValueAxis();
    axisY->setLabelFormat("%f");
    graphic->addAxis(axisY, Qt::AlignLeft);
}

QChart* GraficoEnNubePuntos::getGraphic() { 
    
    graphic->setDropShadowEnabled(false);
    graphic->legend()->setVisible(true);
    graphic->legend()->setAlignment(Qt::AlignRight);
    
    return graphic; 

}

GraficoEnNubePuntosNivelVolumen::GraficoEnNubePuntosNivelVolumen(Dataframe &df) : GraficoEnNubePuntos(df) {
    vector<double> niveles = df.get_column<double>("Nivel");
    vector<double> volumenes = df.get_column<double>("Volumen");
    
    int i = 0;
    for (double nivel : niveles) {
        double volumen = volumenes[i];
        series->append(nivel, volumen);
        i++;
    }
    
    graphic->addSeries(series);
    
    axisX->setTitleText("Nivel");
    series->attachAxis(axisX);
    
    axisY->setTitleText("Volumen");
    series->attachAxis(axisY);
}

GraficoEnNubePuntosNivelPorcentaje::GraficoEnNubePuntosNivelPorcentaje(Dataframe &df) : GraficoEnNubePuntos(df) {
    vector<double> niveles = df.get_column<double>("Nivel");
    vector<double> porcentajes = df.get_column<double>("Porcentaje");
    
    int i = 0;
    for (double nivel : niveles) {
        double porcentaje = porcentajes[i];
        series->append(nivel, porcentaje);
        i++;
    }
    
    graphic->addSeries(series);
    
    axisX->setTitleText("Nivel");
    series->attachAxis(axisX);
    
    axisY->setTitleText("Porcentaje");
    series->attachAxis(axisY);
}

GraficoEnNubePuntosVolumenPorcentaje::GraficoEnNubePuntosVolumenPorcentaje(Dataframe &df) : GraficoEnNubePuntos(df) {
    vector<double> volumenes = df.get_column<double>("Volumen");
    vector<double> porcentajes = df.get_column<double>("Porcentaje");
    
    int i = 0;
    for (double volumen : volumenes) {
        double porcentaje = porcentajes[i];
        series->append(volumen, porcentaje);
        i++;
    }
    
    graphic->addSeries(series);
    axisX->setTitleText("Volumen");
    series->attachAxis(axisX);
    
    axisY->setTitleText("Porcentaje");
    series->attachAxis(axisY);
}


