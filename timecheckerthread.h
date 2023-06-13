#ifndef TIMECHECKERTHREAD_H
#define TIMECHECKERTHREAD_H

#include <QTimer>
#include <QApplication>
#include <QListWidget>
#include <QMessageBox>
#include <QThread>
#include <QTime>
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
