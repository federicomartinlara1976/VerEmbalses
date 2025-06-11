#include "linegraphic.hpp"

#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QDateTimeAxis>

#include <spdlog/spdlog.h>

GraficoEnLinea::GraficoEnLinea(Dataframe &df, string yValue) {
    this->df = df;

    QLineSeries *series = new QLineSeries();

    QValueAxis *axisY = new QValueAxis();
    axisY->setTickCount(5);
    axisY->setMinorTickCount(1);
    axisY->setLabelFormat("%.2f");
    axisY->setTitleText(qtHelper.asQString(yValue));

    QDateTimeAxis *axisX = new QDateTimeAxis(); // Using QValueAxis here instead makes the problem disappear.
    axisX->setFormat("dd-MM-yyyy");
    axisX->setLabelsAngle(-90);
    axisX->setTickCount(10);

    vector<string> fechas = df.get_column<string>("Fecha");
    vector<double> values = df.get_column<double>(appHelper.asCharArray(yValue));

    int i = 0;
    for (string fecha : fechas) {
        QString qFecha = qtHelper.asQString(fecha);
        QString qFormat = qtHelper.asQString(Constants::DATE_FORMAT);

        QDateTime momentInTime;
        momentInTime.setDate(QDate::fromString(qFecha, qFormat));
        double val = values[i];
        series->append(momentInTime.toMSecsSinceEpoch(), val);

        i++;
    }

    graphic = new QChart();
    graphic->addSeries(series);
    graphic->setAnimationOptions(QChart::SeriesAnimations);

    graphic->addAxis(axisX, Qt::AlignBottom);
    graphic->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);
    graphic->legend()->hide();
}

GraficoEnLinea::~GraficoEnLinea() {
    spdlog::debug("Delete GraficoEnLinea");
}
