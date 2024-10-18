#include <spdlog/spdlog.h>
#include <iostream>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QDateTimeAxis>

#include <DataFrame/DataFrame.h>
#include <fmt/format.h>

#include "showtable.hpp"
#include "constants.hpp"

using namespace std;
using namespace hmdf;

DlgShowTable::DlgShowTable(QWidget* parent) : QtDialogWindow(parent) {
    this->initWindow();
}

void DlgShowTable::setup() {
    setupUi(this);
}

void DlgShowTable::connectEvents() {
    connect(btnVerGrafico , &QAbstractButton::clicked, this, &DlgShowTable::showGraphicClicked);
    connect(btnExportarCSV , &QAbstractButton::clicked, this, &DlgShowTable::showExcelClicked);
}

void DlgShowTable::delayedInitialization() {
    QIcon icon;
    icon.addFile(QString::fromUtf8("/usr/share/icons/gnome/22x22/apps/ksysguard.png"), QSize(), QIcon::Normal, QIcon::Off);
    btnExportarCSV->setIcon(icon);

    QIcon icon1;
    icon1.addFile(QString::fromUtf8("/usr/share/icons/Humanity/categories/22/redhat-office.svg"), QSize(), QIcon::Normal, QIcon::Off);
    btnVerGrafico->setIcon(icon1);
}

void DlgShowTable::setData(const FuncionesUi::Dataframe& dataframe) {
    this->dataframe = dataframe;

    // Se carga el dataframe en función si está informado codEmbalse
    if (!codEmbalse.empty()) {
        // Recoger la primera fila, los datos MEN y capacidad
        std::vector<const char *> columns = {"MEN", "Capacidad"};
        auto row = dataframe.get_row<double>(0, columns);

        // Remove the columns MEN and Capacidad
        this->dataframe.remove_column<double>("MEN");
        this->dataframe.remove_column<double>("Capacidad");

        std::string sMen = fmt::format("{:.3f}", row.at<double>(0)); // s == "3.14"
        lblMen->setText(helper.asQString(sMen));
        std::string sCapacidad = fmt::format("{:.3f}", row.at<double>(1)); // s == "3.14"
        lblCapacidad->setText(helper.asQString(sCapacidad));
    }
    else {
        // La función que se usa para eliminar las filas
        auto lambda = [](const unsigned long &, const double &val1, const double &val2, const double &val3)-> bool {
            return (val1 <= 0.0 && val2 <= 0.0 && val3 <= 0.0);
        };

        this->dataframe.remove_data_by_sel<double, double, double, decltype(lambda), double, std::string>("MediaNivel", "MinimoNivel", "MaximoNivel", lambda);
    }

    this->model = new TableModel(this->dataframe);
    this->tblResultados->setModel(model);

    QHeaderView *headerView = new QHeaderView(Qt::Horizontal);
    this->tblResultados->setHorizontalHeader(headerView);
}
  
void DlgShowTable::setCodEmbalse(const string codEmbalse) {
    AppContext& context = AppContext::getInstance();
    
    this->codEmbalse = codEmbalse;
    InfoEmbalse info = context.getEmbalseInfo(codEmbalse);
    spdlog::info("{} - {}", info.codEmbalse, info.embalse);

    this->lblTituloTabla->setText(helper.asQString(info.embalse));
}

void DlgShowTable::setCodZona(const string codZona) {
    AppContext& context = AppContext::getInstance();

    this->codZona = codZona;
    InfoZona info = context.getZona(codZona);
    //spdlog::info("{} - {}", info.codZona, info.nombre);

    double totalCapacidad = context.getTotalCapacidadZona(codZona);
    std::string sTotalCapacidad = fmt::format(Constants::NUMBER_FORMAT, totalCapacidad);
    lblCapacidad->setText(helper.asQString(sTotalCapacidad));

    this->lblTituloTabla->setText(helper.asQString(info.nombre));
    this->menContainer->setVisible(false);
}
    
void DlgShowTable::setFechas(const QDate fechaDesde, const QDate fechaHasta) {
    this->fechaDesde = fechaDesde;
    this->fechaHasta = fechaHasta;
    
    const QString format = helper.asQString(Constants::DATE_FORMAT);
    
    string sDesde = helper.asString(fechaDesde.toString(format));
    string sHasta = helper.asString(fechaHasta.toString(format));
    //spdlog::info("[{} - {}]", sDesde, sHasta);
    
    this->lblDesde->setText(helper.asQString(sDesde));
    this->lblHasta->setText(helper.asQString(sHasta));
}

void DlgShowTable::showGraphicClicked() {
    unique_ptr<DlgShowGraphic> dlgShowGraphic = unique_ptr<DlgShowGraphic>{new DlgShowGraphic(this)};
    dlgShowGraphic->setData(dataframe);
    dlgShowGraphic->mostrar(true);
}

void DlgShowTable::showExcelClicked() {
    AppContext& context = AppContext::getInstance();
    context.saveDataframe(dataframe, this);
}

DlgShowTable::~DlgShowTable() {
    delete model;
}
