#ifndef _DLG_SELECTFECHA_HPP_
#define _DLG_SELECTFECHA_HPP_

#include "ui_dlg-select-fecha.h"
#include "funciones_ui.hpp"
#include "VerEmbalsesAppHelper.hpp"

#include "qtdialogwindow.hpp"
#include <QObject>
#include <QDate>
#include <iostream>

#include <memory>

using namespace std;
using namespace FuncionesUi;

class DlgSelectFecha : public QtDialogWindow, public Ui::DialogSelectFecha {
    Q_OBJECT
    
private:
    QtHelper helper;
    
    QString codZona;
    QString codEmbalse;
    
private slots:
    void cmbZonasIndexChanged(int index);
    void cmbEmbalsesIndexChanged(int index);
    
protected:
    void setup() override;
    void connectEvents() override;
    void delayedInitialization() override;
    void onClose() override;
    void onAccept() override;
    
public:
    DlgSelectFecha(QWidget* parent = nullptr);
    DlgSelectFecha(const QString& codZona, const QString& codEmbalse, QWidget *parent = nullptr);
    
    void setCodZona(const QString& codZona) { this->codZona = codZona; }
    void setCodEmbalse(const QString& codEmbalse) { this->codEmbalse = codEmbalse; }
    
    tuple<QDate, QDate> getFechas(); 
    tuple<QString, QString> getDatosEmbalse();
    
    virtual ~DlgSelectFecha();
};

#endif
