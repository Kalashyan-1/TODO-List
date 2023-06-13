#include "timecheckerthread.h"
TimeCheckerThread::TimeCheckerThread(QObject* receiver, QString slot)
        : receiver(receiver),
          slot(slot)
{
}

void TimeCheckerThread::run()
{
     QTimer timer;
     timer.setInterval(5000);
     connect(&timer, &QTimer::timeout, this, &TimeCheckerThread::checkTime);
     timer.start();
     exec();
}

void TimeCheckerThread::checkTime() {
    QMetaObject::invokeMethod(receiver, qPrintable(slot));
}
