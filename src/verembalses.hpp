#ifndef _VEREMBALSES_HPP_
#define _VEREMBALSES_HPP_

#include "view_embalse.h"
#include "selectfecha.hpp"
#include "selectmes.hpp"
#include "showgraphic.hpp"
#include "showtable.hpp"
#include "progreso.hpp"
#include "qloadjob.hpp"
#include "funciones_ui.hpp"
#include "VerEmbalsesAppHelper.hpp"

#include "qtwindow.hpp"

#include <QObject>

#include <memory>

using namespace FuncionesUi;

class VerEmbalses : public QtWindow, public Ui::MainWindow {
    Q_OBJECT
    
private:
    string applicationName = "verembalses";

    VerEmbalsesAppHelper helper;
    
    QLoadJob* j1;
    
    unique_ptr<DlgSelectFecha> getDlgFecha(bool isSelectedZone = true);
    unique_ptr<DlgSelectMes> getDlgMes();
    
    void showInfoEmbalse(InfoEmbalse& info);
    void showStatsPorZona(string codZona);
    void progresoTerminado();
    void setStatus();
    
private slots:
    void cmbZonasIndexChanged(int index);
    void cmbEmbalsesIndexChanged(int index);
    void showGraphicClicked();
    void showExcelClicked();
    void buscarPorFechas();
    void estadisticasDiarias();
    void estadisticasMensuales();
    
protected:
    void setup() override;
    void connectEvents() override;
    void delayedInitialization() override;
    
public:
    VerEmbalses(QWidget *parent = nullptr);
    
    virtual ~VerEmbalses();
};

#endif
