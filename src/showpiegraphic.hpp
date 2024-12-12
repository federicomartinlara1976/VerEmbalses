#ifndef _DLG_SHOWPIEGRAPHIC_HPP_
#define _DLG_SHOWPIEGRAPHIC_HPP_

#include "dlg_showembalsesgraphic.h"
#include "funciones_ui.hpp"
#include "VerEmbalsesAppHelper.hpp"

#include "qtdialogwindow.hpp"
#include <QObject>
#include <QDate>
#include <iostream>


using namespace std;

class DlgShowPieGraphic : public QtDialogWindow, public Ui::DialogShowEmbalsesGraphic {
    Q_OBJECT

private:
    QtHelper qtHelper;
    AppHelper appHelper;

    FuncionesUi::StringDataframe df;

private slots:
    void drawGraphic();

protected:
    void setup() override;
    void connectEvents() override;
    void delayedInitialization() override;
    void onClose() override;
    void onAccept() override;

public:
    DlgShowPieGraphic(QWidget* parent = nullptr);

    void setData(const FuncionesUi::StringDataframe& df);

    virtual ~DlgShowPieGraphic();
};

#endif

