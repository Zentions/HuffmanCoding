#include "sendfiledialog.h"
#include "ui_sendfiledialog.h"
#include <iostream>
#include <QDialog>
#include <QtNetwork>
#include <QTextCodec>
#include <QtNetwork>
#include <QFileDialog>
using namespace std;
SendFileDialog::SendFileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SendFileDialog)
{
    ui->setupUi(this);
    payloadSize = 64*1024;
    totalByets = 0;
    bytesToWrite = 0;
    bytesWritten = 0;
    ui->clientProgressBar->setValue(0);
    tcpClient = new QTcpSocket(this);
    connect(tcpClient,SIGNAL(connected()),this,SLOT(startTransfer()));
    connect(tcpClient,SIGNAL(bytesWritten(qint64)),this,SLOT(updateClientProgress(qint64)));
    connect(tcpClient,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
    ui->sendButton->setEnabled(false);
}

SendFileDialog::~SendFileDialog()
{
    delete ui;
}

void SendFileDialog::on_openButton_clicked()
{
    ui->clientProgressBar->reset();
    ui->state->setText(tr("客户端就绪"));
    openFile();
}

void SendFileDialog::on_sendButton_clicked()
{
    send();
}
void SendFileDialog::openFile()
{
   FileName = QFileDialog::getOpenFileName(this);
   if(!FileName.isEmpty())
   {
       ui->sendButton->setEnabled(true);
       ui->state->setText(tr("打开文件%1成功").arg(FileName));
   }
   totalByets = 0;
   bytesWritten = 0;
}
void SendFileDialog::send()
{
    ui->sendButton->setEnabled(false);
    bytesWritten = 0;
    ui->state->setText(tr("连接中……"));
    tcpClient->connectToHost(ui->hostLineEdit->text(),ui->postLineEdit->text().toInt());
}
void SendFileDialog::startTransfer()
{
    localFile = new QFile(FileName);
    if(!localFile->open(QFile::ReadOnly))
    {
        return ;
    }
    totalByets = localFile->size();
    QDataStream sentOut(&outBlock,QIODevice::WriteOnly);
    sentOut.setVersion(QDataStream::Qt_4_0);
    QString currentFileName = FileName.right(FileName.size()-FileName.lastIndexOf('/')-1);
    cout<<currentFileName.toStdString()<<endl;
    sentOut<<qint64(0)<<qint64(0)<<currentFileName;
    totalByets+=outBlock.size();
    sentOut.device()->seek(0);
    sentOut<<totalByets<<qint64((outBlock.size()-sizeof(qint64)*2));
    bytesToWrite = totalByets-tcpClient->write(outBlock);
    ui->state->setText(tr("已连接"));
    outBlock.resize(0);
}
void SendFileDialog::updateClientProgress(qint64 num)
{
    bytesWritten += (int)num;
    if(bytesToWrite>0)
    {
        outBlock = localFile->read(qMin(bytesToWrite,payloadSize));
        bytesToWrite -=(int)tcpClient->write(outBlock);
        outBlock.resize(0);
    }else{
        localFile->close();
    }
    ui->clientProgressBar->setMaximum(totalByets);
    ui->clientProgressBar->setValue(bytesWritten);
    if(bytesWritten==totalByets){
        ui->state->setText(tr("完成"));
        localFile->close();
       tcpClient->close();
    }
}
void SendFileDialog::displayError(QAbstractSocket::SocketError)
{
    cout<<tcpClient->errorString().toStdString()<<endl;
    //cout<<QAbstractSocket::SocketError::errorString().toStdWString()<<endl;
    tcpClient->close();
    ui->clientProgressBar->reset();
    ui->state->setText(tr("客户端就绪"));
    ui->sendButton->setEnabled(true);
}


