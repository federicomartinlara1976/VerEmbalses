#ifndef __QTWINDOW_HPP__
#define __QTWINDOW_HPP__

#include <QMainWindow>

class QtWindow : public QMainWindow {
    Q_OBJECT
    
    private slots:
        void delayInitialization();
    
    public:
        QtWindow(QWidget *parent);
        void initWindow();
        virtual ~QtWindow() = default;
        
    protected:
        virtual void setup() = 0;
        virtual void connectEvents() = 0;
        virtual void delayedInitialization() = 0;
};

#endif
