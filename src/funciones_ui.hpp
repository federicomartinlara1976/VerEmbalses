#ifndef _FUNCIONES_UI_HPP_
#define _FUNCIONES_UI_HPP_

#include <QSaveFile>

#include <DataFrame/DataFrame.h>  

#include <qdatetime.h>
#include <mongo.hpp>
#include <memory>
#include <qttools/AppHelper.hpp>
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
    
    typedef struct {
        string fecha, codEmbalse, embalse;
        float porcentaje, capacidad, volumen, men, nivel;
    } InfoEmbalse;
    
    typedef struct {
        string codZona, nombre;
    } InfoZona;
    
    class AppContext {
    private:
        static std::unique_ptr<AppContext> _instance;
        
        AppHelper helper;
        
        DataEngine& getDataEngine();
        
        unique_ptr<vector<InfoEmbalse>> getEmbalsesPorZona(string collectionName, string codZona);
        vector<InfoEmbalse> getPorFechas(string collectionName, QDate& desde, QDate& hasta);
        unique_ptr<vector<InfoZona>> getZonas();
        
        Dataframe getDataframePorFecha(string codEmbalse, QDate& desde, QDate& hasta);
        InfoEmbalse createInfoEmbalse(string codEmbalse, bsoncxx::v_noabi::document::view doc);
        InfoEmbalse getIdEmbalse(bsoncxx::v_noabi::document::view doc);
        string buildCsvHeader(Dataframe& dataFrame, const string& fieldSeparator);
        void saveDataframeToDisk(const QString &outputFileName, Dataframe& dataframe);
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
        
        InfoEmbalse getLastEmbalseInfo(string collectionName);
        Dataframe getDataframeZona(string codZona);
        string getLastExecution();
        Dataframe getDataframe(string codEmbalse, QDate& desde, QDate& hasta);
        void saveDataframe(Dataframe& dataframe, QWidget *parent, const string& filetype = Constants::CSV_FILE_TYPE);
        
        virtual ~AppContext();
    };
}

#endif
