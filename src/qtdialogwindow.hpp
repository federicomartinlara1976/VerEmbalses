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
        void closeEvent(QCloseEvent *event) override;
        void accept() override;

        virtual void setup() = 0;
        virtual void connectEvents() = 0;
        virtual void delayedInitialization() = 0;
        virtual void onClose() = 0;
        virtual void onAccept() = 0;
};

#endif
