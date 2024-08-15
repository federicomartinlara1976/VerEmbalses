#ifndef __QTDIALOGWINDOW_HPP__
#define __QTDIALOGWINDOW_HPP__

#include <QDialog>

class QtDialogWindow : public QDialog {
    
    private slots:
        void delayInitialization();
    
    public:
        QtDialogWindow(QWidget *parent);
        void initWindow();
        
        int mostrar(bool modal = false);
        
        virtual ~QtDialogWindow() = default;
        
    protected:
        virtual void setup() = 0;
        virtual void connectEvents() = 0;
        virtual void delayedInitialization() = 0;
};

#endif
