#ifndef _FUNCIONES_UI_HPP_
#define _FUNCIONES_UI_HPP_

#include <QSaveFile>

#include <DataFrame/DataFrame.h>  

#include <qdatetime.h>
#include <mongo.hpp>
#include <memory>
#include <qttools/QtHelper.hpp>
#include <common/types.hpp>
#include <fmt/core.h>

#include "view_embalse.h"
#include "dlg_selectfecha.h"
#include "constants.hpp"

using namespace std;
using namespace types;
using namespace data::nosql::mongo;

// DataFrame library is entirely under hmdf name-space
//
using namespace hmdf;
    
namespace FuncionesUi {
    
    typedef StdDataFrame<ulong> Dataframe;

    typedef StdDataFrame<string> StringDataframe;
    
    typedef struct {
        string fecha, codEmbalse, embalse;
        float porcentaje, capacidad, volumen, men, nivel;
    } InfoEmbalse;
    
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
        vector<InfoEmbalse> getPorFechas(string collectionName, QDate& desde, QDate& hasta);
        unique_ptr<vector<InfoZona>> getZonas();
        vector<string> getExecutions(QDate& desde, QDate& hasta);
        
        InfoEmbalse createInfoEmbalse(string codEmbalse, bsoncxx::v_noabi::document::view doc);
        InfoEmbalse getIdEmbalse(bsoncxx::v_noabi::document::view doc);
        string buildCsvHeader(StringDataframe& dataFrame, const string& fieldSeparator);
        void saveDataframeToDisk(const QString &outputFileName, StringDataframe& dataframe);
        void writeHeader(QSaveFile& file, StringDataframe& dataFrame);
        void writeContent(QSaveFile& file, StringDataframe& dataFrame);

        int getDataframeSize(Dataframe& dataframe);
        int getDataframeSize(StringDataframe& dataframe);

        vector<std::tuple<String64, std::size_t, std::type_index>> getFields(Dataframe& dataframe);
        vector<std::tuple<String64, std::size_t, std::type_index>> getFields(StringDataframe& dataframe);

        vector<const char*> getFieldNames(Dataframe& dataFrame);
        vector<const char*> getFieldNames(StringDataframe& dataFrame);
        
        AppContext();
        static void destroy(AppContext* instance);
        
    public:
        static AppContext& getInstance();
        static void destroyInstance();
        
        void setDefaultZona(string zona, QComboBox* cmbZona, QComboBox* cmbEmbalse);
        void setDefaultEmbalse(string embalse, QComboBox* cmbEmbalse);
        
        void populateZonasIn(QComboBox *combo);
        void populateEmbalsesIn(string codZona, QComboBox *combo);
        
        InfoEmbalse getEmbalseInfoByDate(string collectionName, string date);
        InfoEmbalse getEmbalseInfo(string codEmbalse);

        InfoZona getZona(string codZona);
        Dataframe getDataframeZona(string codZona);
        Dataframe getDataframeZonaAndDate(string codZona, string date);

        string getLastExecution();

        StringDataframe getDataframePorEmbalseYRangoFechas(string codEmbalse, QDate& desde, QDate& hasta);
        StringDataframe getDataframePorZonaYRangoFechas(string codZona, QDate& desde, QDate& hasta);

        void saveDataframe(StringDataframe& dataframe, QWidget *parent, const string& filetype = Constants::CSV_FILE_TYPE);

        std::tuple<double*, double*> getStatsPorZonaYFecha(string codZona, string date);

        double getTotalCapacidadZona(string codZona);
        
        virtual ~AppContext();
    };
}

#endif
