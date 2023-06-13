#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QColor>
#include <QTimer>
#include <QTime>
#include "timecheckerthread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void info();
    QListWidget* getListWidget() const;
public slots:
    void checkTime();

private slots:

    void on_pushButton_clicked();

    void on_DEL_clicked();

    void on_listWidget_currentRowChanged(int currentRow);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_change_clicked();

private:
    Ui::MainWindow *ui;
    int selected;
    int itemCount;
    int done;
    int missed;
};
#endif // MAINWINDOW_H
