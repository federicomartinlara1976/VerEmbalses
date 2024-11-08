#include <spdlog/spdlog.h>
#include <yaml-cpp/yaml.h>
#include <fmt/format.h>

#include <QObject>
#include <QFileDialog>

#include <KLocalizedString>

#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/stream/document.hpp>

#include <DataFrame/DataFrame.h> 
#include <DataFrame/DataFrameStatsVisitors.h>

#include "funciones_ui.hpp"
#include "constants.hpp"

using namespace data;
using namespace std;

using namespace mongocxx;
using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_array;
using bsoncxx::builder::basic::make_document;
using bsoncxx::builder::stream::document;

using namespace FuncionesUi;
using namespace hmdf;

std::unique_ptr<AppContext> AppContext::_instance = nullptr;

AppContext& AppContext::getInstance() {
    if (_instance == nullptr) {
        _instance.reset(new AppContext()); // Create new instance, assign to unique_ptr.
    }
    return *_instance;
}

void AppContext::destroy(AppContext* instance) {
    if (instance != nullptr) {
        spdlog::debug("Deleting...");
        delete instance;
        instance = nullptr;
    }
}

void AppContext::destroyInstance() {
    if (_instance != nullptr) {
        spdlog::debug("Destroying AppContext");
        _instance.reset(nullptr); // Replaces stored pointer with nullptr, calls deleter on pointed-to instance.
    }
}

AppContext::AppContext() {}

AppContext::~AppContext() {
    DataEngine& instance = DataEngine::getInstance(applicationName);
    instance.destroyInstance();
}

DataEngine& AppContext::getDataEngine() {
    DataEngine& dataEngine = DataEngine::getInstance(applicationName);
    return dataEngine;
}

void AppContext::setDefaultZona(string zona, QComboBox* cmbZona, QComboBox* cmbEmbalse) {
    int index = qtHelper.getCmbIndexByCode(cmbZona, zona);
    cmbZona->setCurrentIndex(index);
    
    populateEmbalsesIn(zona, cmbEmbalse);
}

void AppContext::setDefaultEmbalse(string embalse, QComboBox* cmbEmbalse) {
    int index = qtHelper.getCmbIndexByCode(cmbEmbalse, embalse);
    cmbEmbalse->setCurrentIndex(index);
}

void AppContext::populateZonasIn(QComboBox* combo) {
    try {
        tuple<QString, QVariant> emptyOption = qtHelper.buildComboEmptyOption("Seleccione una zona");
        combo->addItem(get<0>(emptyOption), get<1>(emptyOption));

        unique_ptr<vector<InfoZona>> zonas = getZonas();
        
        for (InfoZona& zona : *zonas) {
            string item = string(zona.codZona + " - " + zona.nombre); 
            const QString label = qtHelper.asQString(item, true);
            const QVariant value = QVariant(qtHelper.asQString(zona.codZona, true));
            
            combo->addItem(label, value);
        }
    } catch (const exception& e) {
        spdlog::error("ERROR populateZonasIn: {}", e.what());
        throw e;
    }
}

unique_ptr<vector<InfoZona>> AppContext::getZonas() {
    try {
        unique_ptr<vector<InfoZona>> zonas = unique_ptr<vector<InfoZona>>{new vector<InfoZona>()};
        
        DataEngine& dataEngine = getDataEngine();
        
        collection collection = dataEngine.getCollection("zonas");
        
        cursor cursor_zonas = collection.find({});

        for (bsoncxx::v_noabi::document::view zona : cursor_zonas) {
            string codZona = string(zona["codigo"].get_string().value);
            string nombre = string(zona["descripcion"].get_string().value);
            
            InfoZona info{};
            info.codZona = codZona;
            info.nombre = nombre;
            zonas->push_back(info);
        }
        
        return zonas;
    } catch (const exception& e) {
        spdlog::error("ERROR getZonas: {}", e.what());
        throw e;
    }
}

InfoZona AppContext::getZona(string codZona) {
    try {
        unique_ptr<vector<InfoZona>> zonas = unique_ptr<vector<InfoZona>>{new vector<InfoZona>()};

        DataEngine& dataEngine = getDataEngine();

        collection collection = dataEngine.getCollection("zonas");

        InfoZona info{};

        bsoncxx::stdx::optional<bsoncxx::document::value> oElement = collection.find_one(make_document(kvp("codigo", make_document(kvp("$eq", codZona)))));
        if(oElement) {
            auto doc = oElement.get();

            info.codZona = string(doc["codigo"].get_string().value);
            info.nombre = string(doc["descripcion"].get_string().value);
        }

        return info;
    } catch (const exception& e) {
        spdlog::error("ERROR getZona: {}", e.what());
        throw e;
    }
}

void AppContext::populateEmbalsesIn(string codZona, QComboBox *combo) {
    try {
        unique_ptr<vector<InfoEmbalse>> embalses = getEmbalsesPorZona("Embalses", codZona);
        
        // Clear the combo
        combo->clear();

        tuple<QString, QVariant> emptyOption = qtHelper.buildComboEmptyOption("Seleccione un embalse");
        combo->addItem(get<0>(emptyOption), get<1>(emptyOption));
        
        for (InfoEmbalse& info : *embalses) {
            const QString label = qtHelper.asQString(info.embalse, true);
            const QVariant value = QVariant(qtHelper.asQString(info.codEmbalse, true));
            
            combo->addItem(label, value);
        }
    } catch (const exception& e) {
        spdlog::error("ERROR populateEmbalsesIn: {}", e.what());
        throw e;
    }
}

FuncionesUi::Dataframe AppContext::getDataframeZonaAndDate(string codZona, string date) {
    try {
        //spdlog::info("Dataframe para la zona {} con fecha {}", codZona, date);
        unique_ptr<vector<InfoEmbalse>> embalses = getEmbalsesPorZona("Embalses", codZona);
        
        data::ColumnData<unsigned long> cIndex("Index");
        vector<unsigned long> indices;
        data::ColumnData<double> cNivel("Nivel");
        vector<double> niveles;
        data::ColumnData<double> cVolumen("Volumen");
        vector<double> volumenes;
        
        unsigned long index = 0;
        for (InfoEmbalse& embalse : *embalses) {
            string codEmbalse = embalse.codEmbalse;
            InfoEmbalse info = getEmbalseInfoByDate(codEmbalse, date);
            indices.push_back(index);
            niveles.push_back(info.nivel);
            volumenes.push_back(info.volumen);
            index++;
        }
        
        cIndex.setData(indices);
        cNivel.setData(niveles);
        cVolumen.setData(volumenes);
        
        FuncionesUi::Dataframe ul_df2;
        
        ul_df2.load_data(std::move(cIndex.getData()),
                     std::make_pair(appHelper.asCharArray(cNivel.getName()), cNivel.getData()),
                     std::make_pair(appHelper.asCharArray(cVolumen.getName()), cVolumen.getData()));
        
        return ul_df2;
    } catch (const exception& e) {
        spdlog::error("ERROR getDataframeZonaAndDate: {}", e.what());
        throw e;
    }
}

FuncionesUi::StringDataframe AppContext::getDataframeEmbalsesZonaAndDate(string codZona, string date) {
    try {
        unique_ptr<vector<InfoEmbalse>> embalses = getEmbalsesPorZona("Embalses", codZona);

        data::ColumnData<string> cIndex("Codigo");
        vector<string> v_codigos;
        data::ColumnData<string> cEmbalse("Embalse");
        vector<string> v_embalses;
        data::ColumnData<double> cNivel("Nivel");
        vector<double> v_niveles;
        data::ColumnData<double> cVolumen("Volumen");
        vector<double> v_volumenes;

        for (InfoEmbalse& embalse : *embalses) {
            string codEmbalse = embalse.codEmbalse;
            InfoEmbalse info = getEmbalseInfoByDate(codEmbalse, date);
            v_codigos.push_back(codEmbalse);
            v_embalses.push_back(info.embalse);
            v_niveles.push_back(info.nivel);
            v_volumenes.push_back(info.volumen);
        }

        cIndex.setData(v_codigos);
        cEmbalse.setData(v_embalses);
        cNivel.setData(v_niveles);
        cVolumen.setData(v_volumenes);

        FuncionesUi::StringDataframe ul_df2;

        ul_df2.load_data(std::move(cIndex.getData()),
                     std::make_pair(appHelper.asCharArray(cEmbalse.getName()), cEmbalse.getData()),
                     std::make_pair(appHelper.asCharArray(cNivel.getName()), cNivel.getData()),
                     std::make_pair(appHelper.asCharArray(cVolumen.getName()), cVolumen.getData()));

        return ul_df2;
    } catch (const exception& e) {
        spdlog::error("ERROR getDataframeEmbalsesZonaAndDate: {}", e.what());
        throw e;
    }
}

FuncionesUi::Dataframe AppContext::getDataframeZona(string codZona) {
    try {
        //spdlog::info("Dataframe para la zona {}", codZona);
        unique_ptr<vector<InfoEmbalse>> embalses = getEmbalsesPorZona("Embalses", codZona);

        data::ColumnData<unsigned long> cIndex("Index");
        vector<unsigned long> indices;
        data::ColumnData<double> cNivel("Nivel");
        vector<double> niveles;
        data::ColumnData<double> cVolumen("Volumen");
        vector<double> volumenes;
        data::ColumnData<double> cCapacidad("Capacidad");
        vector<double> capacidades;

        unsigned long index = 0;
        for (InfoEmbalse& embalse : *embalses) {
            string codEmbalse = embalse.codEmbalse;
            InfoEmbalse info = getEmbalseInfoByDate(codEmbalse, getLastExecution());
            indices.push_back(index);
            niveles.push_back(info.nivel);
            volumenes.push_back(info.volumen);
            capacidades.push_back(info.capacidad);
            index++;
        }

        cIndex.setData(indices);
        cNivel.setData(niveles);
        cVolumen.setData(volumenes);
        cCapacidad.setData(capacidades);

        FuncionesUi::Dataframe ul_df2;

        ul_df2.load_data(std::move(cIndex.getData()),
                     std::make_pair(appHelper.asCharArray(cNivel.getName()), cNivel.getData()),
                     std::make_pair(appHelper.asCharArray(cVolumen.getName()), cVolumen.getData()),
                     std::make_pair(appHelper.asCharArray(cCapacidad.getName()), cCapacidad.getData()));

        return ul_df2;
    } catch (const exception& e) {
        spdlog::error("ERROR getDataframeZona: {}", e.what());
        throw e;
    }
}

unique_ptr<vector<InfoEmbalse>> AppContext::getEmbalsesPorZona(string collectionName, string codZona) {
    try {
        unique_ptr<vector<InfoEmbalse>> v = unique_ptr<vector<InfoEmbalse>>{new vector<InfoEmbalse>()};
        
        DataEngine& dbInstance = getDataEngine();
        
        collection collection = dbInstance.getCollection(collectionName);
        cursor cursor_embalses = collection.find(make_document(kvp("_id", make_document(kvp("$regex", codZona)))));
        
        for (bsoncxx::v_noabi::document::view embalse : cursor_embalses) {
            InfoEmbalse info = getIdEmbalse(embalse);
            v->push_back(info);
        }
        
        return v;
    } catch (const exception& e) {
        spdlog::error("ERROR getEmbalsesPorZona: {}", e.what());
        throw e;
    }
}

FuncionesUi::StringDataframe AppContext::getDataframePorEmbalseYRangoFechas(string codEmbalse, QDate& desde, QDate& hasta) {
    vector<InfoEmbalse> registros = getPorFechas(codEmbalse, desde, hasta);
    
    data::ColumnData<string> cFecha("Fecha");
    vector<string> fechas;
    data::ColumnData<double> cNivel("Nivel");
    vector<double> niveles;
    data::ColumnData<double> cVolumen("Volumen");
    vector<double> volumenes;
    data::ColumnData<double> cPorcentaje("Porcentaje");
    vector<double> porcentajes;
    data::ColumnData<double> cMen("MEN");
    vector<double> v_men;
    data::ColumnData<double> cCapacidad("Capacidad");
    vector<double> v_capacidad;
        
    for (InfoEmbalse& registro : registros) {
        fechas.push_back(registro.fecha);

        niveles.push_back(registro.nivel);
        volumenes.push_back(registro.volumen);
        porcentajes.push_back(registro.porcentaje);
        v_men.push_back(registro.men);
        v_capacidad.push_back(registro.capacidad);
    }
        
    cFecha.setData(fechas);
    cNivel.setData(niveles);
    cVolumen.setData(volumenes);
    cPorcentaje.setData(porcentajes);
    cMen.setData(v_men);
    cCapacidad.setData(v_capacidad);
        
    FuncionesUi::StringDataframe df;
        
    df.load_data(std::move(cFecha.getData()),
                    std::make_pair(appHelper.asCharArray(cNivel.getName()), cNivel.getData()),
                    std::make_pair(appHelper.asCharArray(cVolumen.getName()), cVolumen.getData()),
                    std::make_pair(appHelper.asCharArray(cPorcentaje.getName()), cPorcentaje.getData()),
                    std::make_pair(appHelper.asCharArray(cMen.getName()), cMen.getData()),
                    std::make_pair(appHelper.asCharArray(cCapacidad.getName()), cCapacidad.getData()));
        
    return df;
}

FuncionesUi::StringDataframe AppContext::getDataframePorZonaYRangoFechas(string codZona, QDate& desde, QDate& hasta) {
    // Obtener las ejecuciones entre las fechas
    vector<string> ejecuciones = getExecutions(desde, hasta);

    data::ColumnData<string> cFecha("Fecha");
    vector<string> fechas;

    data::ColumnData<double> cNivelMedia("MediaNivel");
    vector<double> mediaNiveles;
    data::ColumnData<double> cNivelMinimo("MinimoNivel");
    vector<double> minimoNiveles;
    data::ColumnData<double> cNivelMaximo("MaximoNivel");
    vector<double> maximoNiveles;

    data::ColumnData<double> cVolumenMedia("MediaVolumen");
    vector<double> mediaVolumenes;
    data::ColumnData<double> cVolumenMinimo("MinimoVolumen");
    vector<double> minimoVolumenes;
    data::ColumnData<double> cVolumenMaximo("MaximoVolumen");
    vector<double> maximoVolumenes;
    data::ColumnData<double> cVolumenSuma("SumaVolumen");
    vector<double> sumaVolumenes;


    // Para cada ejecución, obtener el dataframe de las estadísticas de la zona
    for (string fecha : ejecuciones) {
        std::tuple<double*, double*> stats = getStatsPorZonaYFecha(codZona, fecha);
        double* statsNivel = std::get<0>(stats);
        double* statsVolumen = std::get<1>(stats);

        fechas.push_back(fecha);

        mediaNiveles.push_back(statsNivel[0]);
        minimoNiveles.push_back(statsNivel[1]);
        maximoNiveles.push_back(statsNivel[2]);

        mediaVolumenes.push_back(statsVolumen[0]);
        minimoVolumenes.push_back(statsVolumen[1]);
        maximoVolumenes.push_back(statsVolumen[2]);
        sumaVolumenes.push_back(statsVolumen[3]);
    }

    cFecha.setData(fechas);

    cNivelMedia.setData(mediaNiveles);
    cNivelMinimo.setData(minimoNiveles);
    cNivelMaximo.setData(maximoNiveles);

    cVolumenMedia.setData(mediaVolumenes);
    cVolumenMinimo.setData(minimoVolumenes);
    cVolumenMaximo.setData(maximoVolumenes);
    cVolumenSuma.setData(sumaVolumenes);

    FuncionesUi::StringDataframe df;

    df.load_data(std::move(cFecha.getData()),
                    std::make_pair(appHelper.asCharArray(cNivelMedia.getName()), cNivelMedia.getData()),
                    std::make_pair(appHelper.asCharArray(cNivelMinimo.getName()), cNivelMinimo.getData()),
                    std::make_pair(appHelper.asCharArray(cNivelMaximo.getName()), cNivelMaximo.getData()),
                    std::make_pair(appHelper.asCharArray(cVolumenMedia.getName()), cVolumenMedia.getData()),
                    std::make_pair(appHelper.asCharArray(cVolumenMinimo.getName()), cVolumenMinimo.getData()),
                    std::make_pair(appHelper.asCharArray(cVolumenMaximo.getName()), cVolumenMaximo.getData()),
                    std::make_pair(appHelper.asCharArray(cVolumenSuma.getName()), cVolumenSuma.getData()));

    return df;
}

vector<string> AppContext::getExecutions(QDate& desde, QDate& hasta) {
    try {
        vector<string> v;

        DataEngine& dbInstance = getDataEngine();

        const QString format = qtHelper.asQString(Constants::DATE_FORMAT);

        string sDesde = qtHelper.asString(desde.toString(format));
        string sHasta = qtHelper.asString(hasta.toString(format));

        collection collection = dbInstance.getCollection("Executions");
        cursor cursor_ejecuciones = collection.find(make_document(kvp("_id", make_document(kvp("$gte", sDesde), kvp("$lte", sHasta)))));

        for (bsoncxx::v_noabi::document::view ejecucion : cursor_ejecuciones) {
            v.push_back(string(ejecucion["_id"].get_string().value));
        }

        return v;
    } catch (const exception& e) {
        spdlog::error("ERROR getExecutions: {}", e.what());
        throw e;
    }
}

InfoEmbalse AppContext::getEmbalseInfoByDate(string collectionName, string date) {
    try {
        InfoEmbalse info{};
        DataEngine& dbInstance = getDataEngine();
        
        auto collection = dbInstance.getCollection(collectionName);
        
        bsoncxx::stdx::optional<bsoncxx::document::value> oElement = collection.find_one(make_document(kvp("_id", make_document(kvp("$eq", date)))));
        if(oElement) {
            auto doc = oElement.get();
            info = createInfoEmbalse(collectionName, doc);
        }
        
        return info;
    } catch (const exception& e) {
        throw (e);
    }
}

InfoEmbalse AppContext::getEmbalseInfo(string codEmbalse) {
    try {
        InfoEmbalse info{};
        DataEngine& dbInstance = getDataEngine();

        auto collection = dbInstance.getCollection("Embalses");

        bsoncxx::stdx::optional<bsoncxx::document::value> oElement = collection.find_one(make_document(kvp("_id", make_document(kvp("$eq", codEmbalse)))));
        if(oElement) {
            auto doc = oElement.get();
            info = getIdEmbalse(doc);
        }

        return info;
    } catch (const exception& e) {
        throw (e);
    }
}

string AppContext::getLastExecution() {
    try {
        string last = {};
        DataEngine& dbInstance = getDataEngine();
        
        auto collection = dbInstance.getCollection("Executions");
        
        bsoncxx::builder::stream::document sort_doc{};
        sort_doc << string("_id") << -1 ;

        mongocxx::options::find opts;
        opts.sort(sort_doc.view()).limit(1);
        
        bsoncxx::stdx::optional<bsoncxx::document::value> oElement = collection.find_one({}, opts);
        if (oElement) {
            auto element = oElement.get();
            last = string(element["_id"].get_string().value);
        }
        else {
            spdlog::warn("No element found!");
        }
        
        return last;
    } catch (const exception& e) {
        spdlog::error(e.what());
        throw (e);
    }
}

vector<InfoEmbalse> AppContext::getPorFechas(string collectionName, QDate& desde, QDate& hasta) {
    vector<InfoEmbalse> v;
    
    const QString format = qtHelper.asQString(Constants::DATE_FORMAT);
    
    string sDesde = qtHelper.asString(desde.toString(format));
    string sHasta = qtHelper.asString(hasta.toString(format));
    
    DataEngine& dataEngine = getDataEngine();
        
    collection collection = dataEngine.getCollection(collectionName);
    cursor cursor_embalses = collection.find(make_document(kvp("_id", make_document(kvp("$gte", sDesde), kvp("$lte", sHasta)))));
        
    for (bsoncxx::v_noabi::document::view doc : cursor_embalses) {
        InfoEmbalse info = createInfoEmbalse(collectionName, doc);
        v.push_back(info);
    }
    
    return v;
}

InfoEmbalse AppContext::createInfoEmbalse(string codEmbalse, bsoncxx::v_noabi::document::view doc) {
    InfoEmbalse info{};
    
    info.codEmbalse = codEmbalse;
    info.fecha = string(doc["_id"].get_string().value);
    info.embalse = string(doc["Embalse"].get_string().value);
    info.porcentaje = doc["porcentaje"].get_double();
    info.capacidad = doc["Capacidad"].get_double();
    info.volumen = doc["Volumen"].get_double();
    info.nivel = doc["Nivel"].get_double();
    info.men = doc["MEN"].get_double();
    
    return info;
}

InfoEmbalse AppContext::getIdEmbalse(bsoncxx::v_noabi::document::view doc) {
    InfoEmbalse info{};
    
    info.codEmbalse = string(doc["_id"].get_string().value);
    info.embalse = string(doc["nombre"].get_string().value);
    
    return info;
}

string AppContext::buildCsvHeader(FuncionesUi::StringDataframe& dataFrame, const string& fieldSeparator) {
    string header = {};
    auto columns = getFields(dataFrame);

    // Pone la columna fecha
    header.append("Indice").append(fieldSeparator);

    for (auto citer: columns)  {
        string nombre = std::get<0>(citer).c_str();
        
        header.append(nombre).append(fieldSeparator);
    }
    
    return header.substr(0, header.length() - 1) + "\r\n";
}

vector<std::tuple<String64, std::size_t, std::type_index>> AppContext::getFields(FuncionesUi::Dataframe& dataframe) {
    return dataframe.get_columns_info<double, string>();
}

vector<std::tuple<String64, std::size_t, std::type_index>> AppContext::getFields(FuncionesUi::StringDataframe& dataframe) {
    return dataframe.get_columns_info<double, string>();
}

vector<const char*> AppContext::getFieldNames(FuncionesUi::Dataframe& dataFrame) {
    vector<const char*> v;
    
    auto fields = getFields(dataFrame);
    
    for(auto field : fields) {
        string name = std::get<0>(field).c_str();
        v.push_back(name.c_str());
    }
    
    return v;
}

vector<const char*> AppContext::getFieldNames(FuncionesUi::StringDataframe& dataFrame) {
    vector<const char*> v;

    auto fields = getFields(dataFrame);

    for(auto field : fields) {
        string name = std::get<0>(field).c_str();
        v.push_back(name.c_str());
    }

    return v;
}

void AppContext::saveDataframeToDisk(const QString &outputFileName, FuncionesUi::StringDataframe& dataFrame) {
    if (!outputFileName.isNull()) {
        // It creates the file
        QSaveFile file(outputFileName);
        file.open(QIODevice::WriteOnly);
        
        writeHeader(file, dataFrame);
        writeContent(file, dataFrame);
        
        file.commit();
    }
    else {
        spdlog::info("Save cancelled");
    }
}

void AppContext::writeHeader(QSaveFile& file, FuncionesUi::StringDataframe& dataframe) {
    string header = buildCsvHeader(dataframe, Constants::CSV_FIELD_SEPARATOR);
    QByteArray outputByteArray;
    outputByteArray.append(appHelper.asCharArray(header));
    file.write(outputByteArray);
}

void AppContext::writeContent(QSaveFile& file, FuncionesUi::StringDataframe& dataframe) {
    auto fields = getFields(dataframe);
    vector<const char*> fieldNames = getFieldNames(dataframe);
    
    for (int i=0;i<getDataframeSize(dataframe);i++) {
        string values = {};

        values.append(dataframe.get_index()[i]).append(",");
        
        int j = 0;
        for (auto field : fields) {
            if (std::get<2>(field) == std::type_index(typeid(double)))  {
                double val = dataframe.get_column<double>(j)[i];
                std::string sVal = fmt::format("{:.2f}", val);
                values.append(sVal).append(",");
            }
            if (std::get<2>(field) == std::type_index(typeid(std::string)))  {
                string val = dataframe.get_column<string>(j)[i];
                values.append(val).append(",");
            }
            
            j++;
        }
        
        values = values.substr(0, values.length() - 1) + "\r\n";
        
        QByteArray outputByteArray = {};
        outputByteArray.append(appHelper.asCharArray(values));
        file.write(outputByteArray);
    }
}

int AppContext::getDataframeSize(FuncionesUi::Dataframe& dataframe) {
    return dataframe.get_index().size();
}

int AppContext::getDataframeSize(FuncionesUi::StringDataframe& dataframe) {
    return dataframe.get_index().size();
}

std::tuple<double*, double*> AppContext::getStatsPorZonaYFecha(string codZona, string date) {
    try {
        Dataframe df = getDataframeZonaAndDate(codZona, date);

        double* statsNivel = new double[4];
        double* statsVolumen = new double[4];

        MeanVisitor<double, unsigned long> mean_v;
        MinVisitor<double, unsigned long> min_v;
        MaxVisitor<double, unsigned long> max_v;
        SumVisitor<double, unsigned long> sum_v;

        df.visit<double>("Nivel", mean_v);
        statsNivel[0] = mean_v.get_result();

        df.visit<double>("Volumen", mean_v);
        statsVolumen[0] = mean_v.get_result();

        df.visit<double>("Nivel", min_v);
        statsNivel[1] = min_v.get_result();

        df.visit<double>("Volumen", min_v);
        statsVolumen[1] = min_v.get_result();

        df.visit<double>("Nivel", max_v);
        statsNivel[2] = max_v.get_result();

        df.visit<double>("Volumen", max_v);
        statsVolumen[2] = max_v.get_result();

        df.visit<double>("Nivel", sum_v);
        statsNivel[3] = sum_v.get_result();

        df.visit<double>("Volumen", sum_v);
        statsVolumen[3] = sum_v.get_result();

        return make_tuple(statsNivel, statsVolumen);
    } catch (const exception& e) {
        spdlog::error("ERROR getStatsPorZonaYFecha: {}", e.what());
        throw e;
    }
}

double AppContext::getTotalCapacidadZona(string codZona) {
    try {
        double totalCapacidad = 0.0;
        Dataframe df = getDataframeZona(codZona);

        SumVisitor<double, unsigned long> sum_v;

        df.visit<double>("Capacidad", sum_v);
        totalCapacidad = sum_v.get_result();

        return totalCapacidad;
    } catch (const exception& e) {
        spdlog::error("ERROR getTotalCapacidadZona: {}", e.what());
        throw e;
    }
}
