#include "stackedbargraphic.hpp"

#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

#include <spdlog/spdlog.h>

GraficoEnBarrasApiladas::GraficoEnBarrasApiladas(Dataframe &df) {
    this->df = df;


    QStackedBarSeries *series = new QStackedBarSeries();
    QStringList categories;

    vector<string> embalses = df.get_column<string>("Embalse");
    vector<double> volumenes = df.get_column<double>("Volumen");
    vector<double> capacidades = df.get_column<double>("Capacidad");

    QBarSet *setVolumen = new QBarSet("Volumen");
    QBarSet *setResto = new QBarSet("Resto");
    QBarSet *setDesbordamiento = new QBarSet("Desbordamiento");

    int i = 0;
    for (string embalse : embalses) {
        QString s_embalse = qtHelper.asQString(embalse);
        categories << s_embalse;

        *setVolumen << volumenes[i];
        if (volumenes[i] >= capacidades[i]) {
            *setDesbordamiento << volumenes[i] - capacidades[i];
            *setResto << 0.0;
        }
        else {
            *setResto << capacidades[i] - volumenes[i];
            *setDesbordamiento << 0.0;
        }
        i++;
    }

    series->append(setVolumen);
    series->append(setResto);
    series->append(setDesbordamiento);

    graphic = new QChart();
    graphic->addSeries(series);
    graphic->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    graphic->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    QValueAxis *axisY = new QValueAxis();
    graphic->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    graphic->legend()->setVisible(true);
    graphic->legend()->setAlignment(Qt::AlignBottom);

    graphic->setDropShadowEnabled(false);
}

GraficoEnBarrasApiladas::~GraficoEnBarrasApiladas() {
    spdlog::debug("Delete GraficoEnBarrasApiladas");
}
