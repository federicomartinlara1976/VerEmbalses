#ifndef _DLG_SELECTTIPOGRAFICO_HPP_
#define _DLG_SELECTTIPOGRAFICO_HPP_

#include "dlg_selecttipografico.h"

#include "qtdialogwindow.hpp"
#include "constants.hpp"
#include <QObject>
#include <QDate>
#include <iostream>

#include <memory>

using namespace std;

class DlgSelectTipoGrafico : public QtDialogWindow, public Ui::DialogSelectGrafico {
    Q_OBJECT

private:
    enum Constants::GraphType graphType;

protected:
    void setup() override;
    void connectEvents() override;
    void delayedInitialization() override;
    void onClose() override;
    void onAccept() override;

public:
    DlgSelectTipoGrafico(QWidget* parent = nullptr);

    enum Constants::GraphType getTipoGrafico() { return graphType; }

    virtual ~DlgSelectTipoGrafico();
};

#endif

