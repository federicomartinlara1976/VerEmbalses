#ifndef _DLG_SHOWGRAPHIC_HPP_
#define _DLG_SHOWGRAPHIC_HPP_

#include "dlg_showgraphic.h"
#include "funciones_ui.hpp"
#include "VerEmbalsesAppHelper.hpp"

#include "qtdialogwindow.hpp"
#include <QObject>
#include <QDate>
#include <iostream>


using namespace std;

class DlgShowGraphic : public QtDialogWindow, public Ui::DialogShowGraphic {
    Q_OBJECT
    
private:
    AppHelper helper;
    
    FuncionesUi::Dataframe dataframe;
    
    string selectedXValue;
    string selectedYValue;
    
    void populateDatoY(string exclude);
    void drawGraphic(string selectedXValue, string selectedYValue);
    
private slots:
    void cmbDatoXIndexChanged(int index);
    void cmbDatoYIndexChanged(int index);
    
protected:
    void setup() override;
    void connectEvents() override;
    void delayedInitialization() override;
    
public:
    DlgShowGraphic(QWidget* parent = nullptr);
    
    void setData(const FuncionesUi::Dataframe& dataframe);
    
    virtual ~DlgShowGraphic();
};

#endif
