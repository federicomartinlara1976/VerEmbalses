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
    DlgShowGraphic(QWidget* parent = nullptr);
    
    void setData(const FuncionesUi::StringDataframe& df);
    
    virtual ~DlgShowGraphic();
};

#endif
