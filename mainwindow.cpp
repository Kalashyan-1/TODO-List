#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , itemCount {0}
    , done {0}
{
    ui->setupUi(this);
    QString str = "Done: 0\n\nUndone: 0\n\n";
    ui->label->setText(str);
    TimeCheckerThread* timeCheckerThread = new TimeCheckerThread(this, "checkTime");
    timeCheckerThread->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString str = ui->textEdit->toPlainText();
    QTime time = ui->timeEdit->time();
    if (str == "") {return;}
    str += "             " + time.toString("hh:mm");
    ui->listWidget->addItem(str);
    ui->listWidget->item(itemCount)->setBackground(Qt::white);
    ++itemCount;
    info();
}

void MainWindow::on_DEL_clicked()
{
    if (selected != -1) {
        QListWidgetItem* it = ui->listWidget->takeItem(selected);
        delete it;
        ui->listWidget->setCurrentRow(-1);
    }
    info();
}

void MainWindow::on_listWidget_currentRowChanged(int currentRow)
{
    selected = currentRow;
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
  if (item->background() == Qt::green) {
     item->setBackground(Qt::white);
     --done;
  } else {
     item->setBackground(Qt::green);
     ++done;
  }
  info();
}

void MainWindow::on_change_clicked()
{
    if  (ui->listWidget->selectedItems().count() == 0) {return;}
    QListWidgetItem* it = ui->listWidget->item(selected);
    QString str = ui->textEdit->toPlainText();
    QTime time = ui->timeEdit->time();
    if (str == "") {return;}
    str += "             " + time.toString("hh:mm");
    it->setText(str);
}

void MainWindow::info() {
    QString str = "Done:" +QString::number(done) + "\n\nUndone: " + QString::number(itemCount - done);
    ui->label->setText(str);
}

void MainWindow::checkTime()
{
    QTime currentTime = QTime::currentTime();
    for (int i = 0; i < ui->listWidget->count(); ++i) {
        QListWidgetItem* item = ui->listWidget->item(i);
        QString timeString = item->text();
        timeString = timeString.right(5);
        QTime storedTime = QTime::fromString(timeString, "hh:mm");
        qDebug() << "item->background().color().name()" << item->background().color().name();
        if (storedTime.isValid() && storedTime <= currentTime && item->background() == Qt::white) {
            QString itemText = item->text();
            QString labelText = "<br>It's time for item - <font color=\"red\">" + itemText + "</font>";
            ui->labelRed->setTextFormat(Qt::RichText);
            ui->labelRed->setText(labelText);
            item->setBackground(Qt::red);
        }
    }
}

