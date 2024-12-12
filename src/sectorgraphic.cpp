#include "sectorgraphic.hpp"

#include <QtCharts/QPieSeries>

GraficoEnSectores::GraficoEnSectores(StringDataframe &df) {
    this->df = df;

    QPieSeries *series = new QPieSeries();

    vector<string> embalses = df.get_column<string>("Embalse");
    vector<double> values = df.get_column<double>("Volumen");

    int i = 0;
    for (string embalse : embalses) {
        QString qEmbalse = qtHelper.asQString(embalse);
        double val = values[i];
        series->append(qEmbalse, val);
        i++;
    }

    series->setLabelsVisible();

    graphic = new QChart();
    graphic->addSeries(series);
    graphic->setAnimationOptions(QChart::SeriesAnimations);

    graphic->legend()->setVisible(true);
    graphic->legend()->setAlignment(Qt::AlignRight);

}

