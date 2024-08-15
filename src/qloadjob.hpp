#ifndef __QLISTENERJOB_HPP__
#define __QLISTENERJOB_HPP__

#include <ThreadWeaver/ThreadWeaver>

#include <string>

#include "signalmanager.hpp"

using namespace ThreadWeaver;
using namespace std;

//@@snippet_begin(sample-helloworldraw-class)
class QLoadJob : public ThreadWeaver::Job {
    public:
        QLoadJob();
        bool isRunning() { return running; }

    protected:
        void run(JobPointer, Thread *) override;

    private:
        bool running;
};

#endif
