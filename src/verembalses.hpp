#ifndef _VEREMBALSES_HPP_
#define _VEREMBALSES_HPP_

#include "ui_ver_embalses.h"
#include "selectfecha.hpp"
#include "showlinegraphic.hpp"
#include "showtable.hpp"
#include "progreso.hpp"
#include "qloadjob.hpp"
#include "funciones_ui.hpp"
#include "VerEmbalsesAppHelper.hpp"

#include "qtwindow.hpp"

#include "ui_settings.h"
#include "VerEmbalsesSettings.h"

#include <QObject>
#include <qttools/qthelper.hpp>
#include <qttools/qtdatehelper.hpp>

#include <memory>

using namespace FuncionesUi;

class VerEmbalsesView : public QtWidget {
    Q_OBJECT
    
private:
    Ui::MainWindow m_ui;
    
    QtHelper qtHelper;
    QtDateHelper qtDateHelper;
    
    string applicationName = "verembalses";
    
    Ui::Settings m_settings;

    VerEmbalsesAppHelper helper;
    
    QLoadJob* j1;

    string zona;
    string embalse;
    
    string plvZona;
    
    unique_ptr<DlgSelectFecha> getDlgFecha(bool isSelectedZone = true);
    
    void showInfoEmbalse(InfoEmbalse& info);
    void showStatsPorZona(string codZona, string date);
    void setStatus(string date);
    
private slots:
    void cmbZonasIndexChanged(int index);
    void cmbPlvZonasIndexChanged(int index);
    void cmbEmbalsesIndexChanged(int index);
    void cmbPuntosControlIndexChanged(int index);
    void showGraphicClicked();
    void showExcelClicked();
    void showEmbalsesClicked();
    void buscarPorFechas();
    void settingsConfigure();
    
protected:
    void setup() override;
    void connectEvents() override;
    void delayedInitialization() override;
    
public:
    VerEmbalses();
    
    virtual ~VerEmbalses();
};

#endif
