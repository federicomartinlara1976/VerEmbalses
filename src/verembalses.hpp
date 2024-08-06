#ifndef _VEREMBALSES_HPP_
#define _VEREMBALSES_HPP_

#include "view_embalse.h"
#include "selectfecha.hpp"
#include "showgraphic.hpp"
#include "showtable.hpp"
#include "funciones_ui.hpp"
#include "VerEmbalsesAppHelper.hpp"

#include <qttools/qtwindow.hpp>

#include <QObject>

#include <memory>

using namespace FuncionesUi;

class VerEmbalses : public QtWindow, public Ui::MainWindow {
    Q_OBJECT
    
private:
    VerEmbalsesAppHelper helper;
    
    unique_ptr<DlgSelectFecha> getDlgFecha(bool isSelectedZone = true);
    
    void showInfoEmbalse(InfoEmbalse& info);
    void showStatsPorZona(string codZona);
    void setStatus();
    
private slots:
    void cmbZonasIndexChanged(int index);
    void cmbEmbalsesIndexChanged(int index);
    void showGraphicClicked();
    void showExcelClicked();
    void buscarPorFechas();
    
protected:
    void setup() override;
    void connectEvents() override;
    void delayedInitialization() override;
    
public:
    VerEmbalses(QWidget *parent = nullptr);
    
    virtual ~VerEmbalses();
};

#endif
