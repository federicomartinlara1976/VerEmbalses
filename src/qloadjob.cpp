#include "qloadjob.hpp"

#include <QThread>

QLoadJob::QLoadJob() {
    running = true;
    SignalManager::instance()->sendStarted();
}

void QLoadJob::run(JobPointer, Thread *) {
    QThread::sleep(1);
    SignalManager::instance()->sendPercent(20, "Primera fase");
    
    QThread::sleep(1);
    SignalManager::instance()->sendPercent(40, "Segunda fase");
    
    QThread::sleep(1);
    SignalManager::instance()->sendPercent(60, "Compilando");
    
    QThread::sleep(1);
    SignalManager::instance()->sendPercent(80, "Agrupando");
    
    QThread::sleep(1);
    SignalManager::instance()->sendFinished();
    
    running = false;
}

