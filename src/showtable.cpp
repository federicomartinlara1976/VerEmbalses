#include <spdlog/spdlog.h>
#include <iostream>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QDateTimeAxis>
#include <QFileDialog>

#include <KLocalizedString>

#include <DataFrame/DataFrame.h>
#include <fmt/format.h>

#include "showtable.hpp"

using namespace std;
using namespace hmdf;

DlgShowTable::DlgShowTable(const FuncionesUi::StringDataframe& dataframe, const string& code, enum Constants::TableType tableType, QWidget* parent) : QtDialogWindow(parent) {
    this->initWindow();
    this->dataframe = dataframe;
    this->tableType = tableType;

    if (tableType == Constants::EMBALSE) {
        setCodEmbalse(code);
    }

    if (tableType == Constants::ZONA) {
        setCodZona(code);
    }

    setData();
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

void DlgShowTable::setData() {
    TableModel *tableModel = nullptr;

    // Se carga el modelo en función del tipo
    if (tableType == Constants::EMBALSE) {
        tableModel = new TableModelEmbalse(this->dataframe);
    }

    if (tableType == Constants::ZONA) {
        tableModel = new TableModelZona(this->dataframe);
    }

    // El dataframe modificado
    this->dataframe = tableModel->getDataframe();
    this->tblResultados->setModel(tableModel);

    QHeaderView *headerView = new QHeaderView(Qt::Horizontal);
    this->tblResultados->setHorizontalHeader(headerView);
}
  
void DlgShowTable::setCodEmbalse(const string& codEmbalse) {
    AppContext& context = AppContext::getInstance();
    
    this->codEmbalse = codEmbalse;
    InfoEmbalse info = context.getEmbalseInfo(codEmbalse);
    //spdlog::info("{} - {}", info.codEmbalse, info.embalse);

    // Recoger la primera fila, los datos MEN y capacidad para informar las etiquetas de la cabecera
    std::vector<const char *> columns = {"MEN", "Capacidad"};
    auto row = dataframe.get_row<double>(0, columns);

    std::string sMen = fmt::format("{:.3f}", row.at<double>(0)); // s == "3.14"
    lblMen->setText(helper.asQString(sMen));
    std::string sCapacidad = fmt::format("{:.3f}", row.at<double>(1)); // s == "3.14"
    lblCapacidad->setText(helper.asQString(sCapacidad));

    this->lblTituloTabla->setText(helper.asQString(info.embalse));
    this->menContainer->setVisible(true);
}

void DlgShowTable::setCodZona(const string& codZona) {
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
    //context.saveDataframe(dataframe, this);

    const string& filetype = Constants::CSV_FILE_TYPE;
    const QString filename = QFileDialog::getSaveFileName(this, i18n("Save File As"), QDir::currentPath(), helper.asQString(filetype));
    context.saveDataframeToDisk(filename, this->dataframe);
}

DlgShowTable::~DlgShowTable() {}
