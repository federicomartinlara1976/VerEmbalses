#include "stackedbargraphic.hpp"

#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

GraficoEnBarrasApiladas::GraficoEnBarrasApiladas(Dataframe &df) {
    this->df = df;


    QStackedBarSeries *series = new QStackedBarSeries();
    QStringList categories;

    vector<string> embalses = df.get_column<string>("Embalse");
    vector<double> volumenes = df.get_column<double>("Volumen");
    vector<double> capacidades = df.get_column<double>("Capacidad");

    QBarSet *setVolumen = new QBarSet("Volumen");
    QBarSet *setResto = new QBarSet("Resto");

    int i = 0;
    for (string embalse : embalses) {
        QString s_embalse = qtHelper.asQString(embalse);
        categories << s_embalse;

        *setVolumen << volumenes[i];
        *setResto << capacidades[i] - volumenes[i];
        i++;
    }

    series->append(setVolumen);
    series->append(setResto);

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
