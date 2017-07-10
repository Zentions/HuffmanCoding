#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTime>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void sleep(unsigned int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void MainWindow::on_toolButton_clicked()
{
    ui->progressBar->setValue(0);
    QString oriText = ui->textEdit->toPlainText();
    if(oriText=="")
    {
        QMessageBox::information(this,"Error Message","请先填入要编码的文字");
        return;
    }
    EncoderMachine machine(oriText,40);
    machine.start();
    weight = machine.getWeght();
    num = machine.getNum();
    ui->progressBar->setValue(85);
    ui->textArea->setText(QString::fromStdString(machine.encode()));
    ui->textArea_2->setText(QString::fromStdString(machine.make()));
    ui->progressBar->setValue(100);
    sleep(1000);
    ui->progressBar->setValue(0);
}

void MainWindow::on_toolButton_2_clicked()
{
    ui->progressBar->setValue(0);
    DecodeMachine machine;
    machine.start();
    ui->progressBar->setValue(70);
    ui->textArea_3->setText(machine.getText());
    ui->progressBar->setValue(100);
    sleep(1000);
    ui->progressBar->setValue(0);
}

void MainWindow::on_toolButton_3_clicked()
{
    if(ui->textEdit->toPlainText() ==ui->textArea_3->toPlainText())
        QMessageBox::about(this, "提示", "解码成功");
    else QMessageBox::information(this,"Error Message","解码失败，请检查");
}

void MainWindow::on_toolButton_4_clicked()
{
    if(weight==NULL){
        QMessageBox::information(this,"Error Message","未添加过要编码的内容");
        return;
    }
   TreeDialog *log = new TreeDialog(weight,num);
   log->show();
}
