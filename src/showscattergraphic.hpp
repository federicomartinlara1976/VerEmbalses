#ifndef _DLG_SHOWSCATTERGRAPHIC_HPP_
#define _DLG_SHOWSCATTERGRAPHIC_HPP_

#include "dlg_showsimplegraphic.h"
#include "funciones_ui.hpp"
#include "VerEmbalsesAppHelper.hpp"

#include "qtdialogwindow.hpp"
#include <QObject>
#include <QDate>
#include <iostream>


using namespace std;

class DlgShowScatterGraphic : public QtDialogWindow, public Ui::DialogShowSimpleGraphic {
    Q_OBJECT

private:
    QtHelper qtHelper;
    AppHelper appHelper;

    FuncionesUi::Dataframe df;

    void drawGraphic();

private slots:
    void print();

protected:
    void setup() override;
    void connectEvents() override;
    void delayedInitialization() override;
    void onClose() override;
    void onAccept() override;

public:
    DlgShowScatterGraphic(QWidget* parent = nullptr);

    void setData(const FuncionesUi::Dataframe& df);

    virtual ~DlgShowScatterGraphic();
};

#endif


