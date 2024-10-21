#ifndef _DLG_SHOWTABLE_HPP_
#define _DLG_SHOWTABLE_HPP_

#include "dlg_showtable.h"
#include "funciones_ui.hpp"
#include "VerEmbalsesAppHelper.hpp"
#include "tablemodel.hpp"
#include "showgraphic.hpp"
#include "constants.hpp"

#include "qtdialogwindow.hpp"
#include <QObject>
#include <QDate>
#include <iostream>

#include <DataFrame/DataFrame.h>
#include <memory>

using namespace std;
using namespace hmdf;

class DlgShowTable : public QtDialogWindow, public Ui::DialogShowTable {
    Q_OBJECT
    
private:
    QtHelper helper;
    
    string codEmbalse;
    string codZona;
    QDate fechaDesde;
    QDate fechaHasta;
    
    FuncionesUi::StringDataframe dataframe;

    enum Constants::TableType tableType;

    void setCodEmbalse(const string& codEmbalse);
    void setCodZona(const string& codZona);
    void setData();

private slots:
    void showGraphicClicked();
    void showExcelClicked();

protected:
    void setup() override;
    void connectEvents() override;
    void delayedInitialization() override;    

public:
    DlgShowTable(const FuncionesUi::StringDataframe& dataframe, const string& code, enum Constants::TableType tableType, QWidget* parent = nullptr);
    
    void setFechas(const QDate fechaDesde, const QDate fechaHasta);
    
    virtual ~DlgShowTable();

};

#endif
