#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <KXmlGuiWindow>

class Window : public KXmlGuiWindow {
    Q_OBJECT
    
    private slots:
        void delayInitialization();
    
    public:
        Window();
        void initWindow();
        virtual ~Window() = default;
        
    protected:
        virtual void setup() = 0;
        virtual void connectEvents() = 0;
        virtual void delayedInitialization() = 0;
};

#endif
