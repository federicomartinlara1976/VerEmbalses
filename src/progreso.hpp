#ifndef _DLG_PROGRESO_HPP_
#define _DLG_PROGRESO_HPP_

#include "dlg_progreso.h"
#include "funciones_ui.hpp"
#include "VerEmbalsesAppHelper.hpp"

#include "qtdialogwindow.hpp"
#include <QObject>

using namespace std;
using namespace FuncionesUi;

class DlgProgreso : public QtDialogWindow, public Ui::DialogProgreso {
    Q_OBJECT
    
private:
    AppHelper helper;
    
private slots:
    void percentChanged(int percent, QString message);
    void started();
    void finished();
    
protected:
    void setup() override;
    void connectEvents() override;
    void delayedInitialization() override;
    
public:
    DlgProgreso(QWidget* parent = nullptr);
    void show();
    
    virtual ~DlgProgreso();
};

#endif

