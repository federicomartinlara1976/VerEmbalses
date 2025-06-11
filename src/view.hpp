#ifndef __VIEW_HPP__
#define __VIEW_HPP__

#include <QtWidgets/QWidget>

class View : public QWidget {
    Q_OBJECT
    
    private slots:
        void delayInitialization();
    
    public:
        View(QWidget *parent);
        void initView();
        virtual ~View() = default;
        
    protected:
        virtual void setup() = 0;
        virtual void connectEvents() = 0;
        virtual void delayedInitialization() = 0;
};

#endif
