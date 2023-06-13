#ifndef TIMECHECKERTHREAD_H
#define TIMECHECKERTHREAD_H

#include <QApplication>
#include <QListWidget>
#include <QMessageBox>
#include <QThread>
#include <QTime>
#include <QTimer>

class TimeCheckerThread : public QThread
{
public:
    TimeCheckerThread(QObject* receiver, QString slot);
    void run() override;
    void checkTime() ;
private:
    QListWidget* listWidget;
    QObject* receiver;
    QString slot;
};
#endif // TIMECHECKERTHREAD_H
