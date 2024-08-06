#ifndef _DLG_SELECTFECHA_HPP_
#define _DLG_SELECTFECHA_HPP_

#include "dlg_selectfecha.h"
#include "funciones_ui.hpp"
#include "VerEmbalsesAppHelper.hpp"

#include <qttools/qtdialogwindow.hpp>
#include <QObject>
#include <QDate>
#include <iostream>

#include <memory>

using namespace std;
using namespace FuncionesUi;

class DlgSelectFecha : public QtDialogWindow, public Ui::DialogSelectFecha {
    Q_OBJECT
    
private:
    AppHelper helper;
    
    string codZona = {};
    string codEmbalse = {};
    
private slots:
    void cmbZonasIndexChanged(int index);
    void cmbEmbalsesIndexChanged(int index);
    
protected:
    void setup() override;
    void connectEvents() override;
    void delayedInitialization() override;
    
public:
    DlgSelectFecha(QWidget* parent = nullptr);
    DlgSelectFecha(string codZona, string codEmbalse, QWidget *parent = nullptr);
    
    void setCodZona(string codZona) { this->codZona = codZona; }
    void setCodEmbalse(string codEmbalse) { this->codEmbalse = codEmbalse; }
    
    tuple<QDate, QDate> getFechas(); 
    tuple<string, string> getDatosEmbalse();
    
    virtual ~DlgSelectFecha();
};

#endif
