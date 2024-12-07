#ifndef _DLG_SELECTMES_HPP_
#define _DLG_SELECTMES_HPP_

#include "dlg_selectmes.h"

#include "qtdialogwindow.hpp"
#include <QObject>
#include <qttools/QtHelper.hpp>

using namespace std;

class DlgSelectMes : public QtDialogWindow, public Ui::DialogSelectMes {
    Q_OBJECT
    
private:
    QtHelper helper;
    tuple<int, string> selected;
    
private slots:
    void cmbMesIndexChanged(int index);
    
protected:
    void setup() override;
    void connectEvents() override;
    void delayedInitialization() override;
    void onClose() override;
    void onAccept() override;
    
public:
    DlgSelectMes(QWidget* parent = nullptr);
    
    tuple<int, string> getMes() { return selected; };
    
    virtual ~DlgSelectMes();
};

#endif

