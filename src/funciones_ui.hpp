#ifndef _FUNCIONES_UI_HPP_
#define _FUNCIONES_UI_HPP_

#include <QSaveFile>

#include <DataFrame/DataFrame.h>  

#include <qdatetime.h>
#include <mongo/mongo.hpp>
#include <memory>
#include <common/apphelper.hpp>
#include <qttools/qthelper.hpp>
#include <common/types.hpp>
#include <fmt/core.h>

#include "constants.hpp"
    
namespace FuncionesUi {
    
    using namespace std;
    using namespace types;
    using namespace data::nosql::mongo;

    // DataFrame library is entirely under hmdf name-space
    //
    using namespace hmdf;
    
    typedef StdDataFrame<ulong> Dataframe;

    typedef StdDataFrame<string> StringDataframe;
    
    typedef struct {
        string fecha, codEmbalse, embalse;
        float porcentaje, capacidad, volumen, men, nivel;
    } InfoEmbalse;
    
    typedef struct {
        string codPunto, nombre;
    } InfoPuntoControl;
    
    typedef struct {
        string codZona, nombre;
    } InfoZona;
    
    class AppContext {
    private:
        string applicationName = "verembalses";

        static std::unique_ptr<AppContext> _instance;
        
        QtHelper qtHelper;
        AppHelper appHelper;
        
        DataEngine& getDataEngine();
        
        unique_ptr<vector<InfoEmbalse>> getEmbalsesPorZona(string collectionName, string codZona);
        unique_ptr<vector<InfoPuntoControl>> getPuntosControlPorZona(string collectionName, string codPlvZona);
        vector<InfoEmbalse> getPorFechas(string collectionName, QDate& desde, QDate& hasta);
        unique_ptr<vector<InfoZona>> getZonas();
        vector<string> getExecutions(QDate& desde, QDate& hasta);
        
        InfoEmbalse createInfoEmbalse(string codEmbalse, bsoncxx::v_noabi::document::view doc);
        InfoEmbalse getIdEmbalse(bsoncxx::v_noabi::document::view doc);
        InfoPuntoControl getIdPuntoControl(bsoncxx::v_noabi::document::view doc);
        string buildCsvHeader(Dataframe& dataFrame, const string& fieldSeparator);

        void writeHeader(QSaveFile& file, Dataframe& dataFrame);
        void writeContent(QSaveFile& file, Dataframe& dataFrame);

        int getDataframeSize(Dataframe& dataframe);
        vector<std::tuple<String64, std::size_t, std::type_index>> getFields(Dataframe& dataframe);
        vector<const char*> getFieldNames(Dataframe& dataFrame);
        
        AppContext();
        static void destroy(AppContext* instance);
        
    public:
        static AppContext& getInstance();
        static void destroyInstance();
        
        void setDefaultZona(string zona, QComboBox* cmbZona, QComboBox* cmbEmbalse);
        void setDefaultEmbalse(string embalse, QComboBox* cmbEmbalse);
        
        void populateZonasIn(QComboBox *combo);
        void populateEmbalsesIn(string codZona, QComboBox *combo);
        void populatePuntosControlIn(string codPlvZona, QComboBox *combo);
        
        InfoEmbalse getEmbalseInfoByDate(string collectionName, string date);
        InfoEmbalse getEmbalseInfo(string codEmbalse);

        InfoZona getZona(string codZona);
        Dataframe getDataframeZona(string codZona);
        Dataframe getDataframeEmbalsesZonaAndDate(string codZona, string date);

        string getLastExecution();

        Dataframe getDataframePorEmbalseYRangoFechas(string codEmbalse, QDate& desde, QDate& hasta);
        Dataframe getDataframePorZonaYRangoFechas(string codZona, QDate& desde, QDate& hasta);

        void saveDataframeToDisk(const QString &outputFileName, Dataframe& dataframe);

        std::tuple<double*, double*> getStatsPorZonaYFecha(string codZona, string date);

        double getTotalCapacidadZona(string codZona);
        
        virtual ~AppContext();
    };
}

#endif
