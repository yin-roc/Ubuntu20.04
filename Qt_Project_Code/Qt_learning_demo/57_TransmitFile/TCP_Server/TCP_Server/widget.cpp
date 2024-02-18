#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->lineEdit->setText("8080");

    tcpserver = new QTcpServer(this);


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    tcpserver->listen(QHostAddress::LocalHost, ui->lineEdit->text().toInt());

    connect(tcpserver, &QTcpServer::newConnection, this, [&](){
        clientConnection = tcpserver->nextPendingConnection(); // 获取新的连接套接字

        clientConnection->write("Welcome to connect to the server!");

        connect(clientConnection, &QTcpSocket::readyRead, this, [&](){
            QByteArray array = clientConnection->readAll();
            if(headInfo)
            {
                headInfo = false;
                recvSize = 0;

                fileName = QString(array).section("**", 0, 0);
                fileSize = QString(array).section("**", 1, 1).toInt();

                file.setFileName(fileName);
                file.open(QIODevice::WriteOnly);

                ui->progressBar->setMinimum(0);
                ui->progressBar->setMaximum(fileSize / 1024);
                ui->progressBar->setValue(0);

            }
            else
            {

                qint64 length = file.write(array);
                if(length > 0)
                    recvSize += length;
                ui->progressBar->setValue(recvSize / 1024);
                if(recvSize == fileSize)
                {
                    QMessageBox::information(this, "完成", "文件接收完成");
                    file.close();
                }
            }
        });
    });

    ui->pushButton->setEnabled(false);
}
