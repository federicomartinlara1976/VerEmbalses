#ifndef _DLG_SHOWLINEGRAPHIC_HPP_
#define _DLG_SHOWLINEGRAPHIC_HPP_

#include "dlg_showlinegraphic.h"
#include "funciones_ui.hpp"
#include "VerEmbalsesAppHelper.hpp"

#include "qtdialogwindow.hpp"
#include <QObject>
#include <QDate>
#include <iostream>


using namespace std;

class DlgShowLineGraphic : public QtDialogWindow, public Ui::DialogShowLineGraphic {
    Q_OBJECT
    
private:
    QtHelper qtHelper;
    AppHelper appHelper;
    
    FuncionesUi::StringDataframe df;
    
    string selectedYValue;
    
    void populateDatoY();
    void drawGraphic(string selectedYValue);
    
private slots:
    void cmbDatoYIndexChanged(int index);
    
protected:
    void setup() override;
    void connectEvents() override;
    void delayedInitialization() override;
    
public:
    DlgShowLineGraphic(QWidget* parent = nullptr);
    
    void setData(const FuncionesUi::StringDataframe& df);
    
    virtual ~DlgShowLineGraphic();
};

#endif