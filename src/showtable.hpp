#ifndef _DLG_SHOWTABLE_HPP_
#define _DLG_SHOWTABLE_HPP_

#include "dlg_showtable.h"
#include "funciones_ui.hpp"
#include "VerEmbalsesAppHelper.hpp"
#include "tablemodel.hpp"
#include "showgraphic.hpp"

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
    QDate fechaDesde;
    QDate fechaHasta;
    
    TableModel *model = nullptr; 
    
    FuncionesUi::Dataframe dataframe;

private slots:
    void showGraphicClicked();
    void showExcelClicked();

protected:
    void setup() override;
    void connectEvents() override;
    void delayedInitialization() override;    

public:
    DlgShowTable(QWidget* parent = nullptr);
    
    void setCodEmbalse(const string codEmbalse);
    void setFechas(const QDate fechaDesde, const QDate fechaHasta);
    
    void setData(const FuncionesUi::Dataframe& dataframe);
    
    virtual ~DlgShowTable();

};

#endif
