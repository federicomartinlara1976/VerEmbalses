#ifndef __SIGNALMANAGER_HPP__
#define __SIGNALMANAGER_HPP__

#include <QObject>
#include <QEvent>
#include <QDebug>

class SignalManager : public QObject {
    Q_OBJECT
    
private:
    static SignalManager*  _signalManager;
    
    static void destroy(SignalManager* instance);

Q_SIGNALS:
    void percentSignal(int percent, QString message);
    void finishedSignal();
    void startedSignal();

public:
    static SignalManager* instance();
    static void destroyInstance();
    
    void sendPercent(int percent, QString message);
    void sendFinished();
    void sendStarted();
    
    virtual ~SignalManager();
};

#endif
