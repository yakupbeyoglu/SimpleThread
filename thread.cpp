#include "thread.h"
#include <QMutex>

Thread::Thread(QObject *parent) :
    QThread (parent)
{

}
void
Thread::Progress() {
    for(int i=0; i<=100; i++) {
        ///lock process
        QMutex mutex;
        mutex.lock();
        if(this->status)
            break;
        mutex.unlock();

        emit ValueChanged(i);
    ///sleep working inside the thread so not sleep whole the system!
        this->msleep(100);
    }

}
void
Thread::run() {
    if(status)
        status = false;
    Progress();
}

void
Thread::stop() {
    status = true;
}
