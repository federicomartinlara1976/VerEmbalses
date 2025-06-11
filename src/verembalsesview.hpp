#ifndef __VEREMBALSESVIEW_HPP__
#define __VEREMBALSESVIEW_HPP__

#include "ui_ver_embalses.h"
#include "view.hpp"
#include "observer.hpp"

#include "selectfecha.hpp"
#include "showlinegraphic.hpp"
#include "showtable.hpp"
#include "progreso.hpp"
#include "qloadjob.hpp"
#include "funciones_ui.hpp"
#include "VerEmbalsesAppHelper.hpp"

#include <QObject>
#include <qthelper.hpp>
#include <qtdatehelper.hpp>

#include <memory>


/**
 * This class serves as the main window for testkdecompleto.  It handles the
 * menus, toolbars and status bars.
 *
 * @short Main window class
 * @author %{AUTHOR} <%{EMAIL}>
 * @version %{VERSION}
 */
class VerEmbalsesView : public View, public Subject
{
    Q_OBJECT
public:
    /**
     * Default Constructor
     */
    explicit VerEmbalsesView(QWidget *parent);

    /**
     * Default Destructor
     */
    ~VerEmbalsesView() override;
    
protected:
    void setup() override;
    void connectEvents() override;
    void delayedInitialization() override;

private Q_SLOTS:
    void cmbZonasIndexChanged(int index);
    void cmbPlvZonasIndexChanged(int index);
    void cmbEmbalsesIndexChanged(int index);
    void cmbPuntosControlIndexChanged(int index);
    void showGraphicClicked();
    void showExcelClicked();
    void showEmbalsesClicked();

private:
    // this is the name of the root widget inside our Ui file
    // you can rename it in designer and then change it here
    Ui::VerEmbalses m_ui;
    
    QtHelper qtHelper;
    QtDateHelper qtDateHelper;
    
    string applicationName = "verembalses";
    
    VerEmbalsesAppHelper helper;
    
    QLoadJob* j1;

    string zona;
    string embalse;
    
    string plvZona;
    
    unique_ptr<DlgSelectFecha> getDlgFecha();
    
    void showInfoEmbalse(InfoEmbalse& info);
    void showStatsPorZona(string codZona, string date);
    void setStatus(string date);
};


#endif
