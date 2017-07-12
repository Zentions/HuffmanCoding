#ifndef SENDFILEDIALOG_H
#define SENDFILEDIALOG_H

#include <QDialog>
#include <QAbstractSocket>
class QTcpSocket;
class QFile;
namespace Ui {
class SendFileDialog;
}

class SendFileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SendFileDialog(QWidget *parent = 0);
    ~SendFileDialog();

private slots:
    void on_openButton_clicked();

    void on_sendButton_clicked();
    void openFile();
    void send();
    void startTransfer();
    void updateClientProgress(qint64);
    void displayError(QAbstractSocket::SocketError);

private:
    Ui::SendFileDialog *ui;
    QTcpSocket *tcpClient;
    QFile *localFile;
    qint64 totalByets;
    qint64 bytesWritten;
    qint64 bytesToWrite;
    qint64 payloadSize;//每次发送数据大小
    QString FileName;
    QByteArray outBlock;
};

#endif // SENDFILEDIALOG_H


