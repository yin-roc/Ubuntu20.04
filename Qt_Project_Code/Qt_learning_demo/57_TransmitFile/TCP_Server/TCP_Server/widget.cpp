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
    tcpserver->listen(QHostAddress::LocalHost, ui->lineEdit->text().toInt());

    connect(tcpserver, &QTcpServer::newConnection, this, [&](){
        clientConnection = tcpserver->nextPendingConnection(); // 获取新的连接套接字

        clientConnection->write("Welcome to connect to the server!");

        ui->textEdit->append("New connection......");

        connect(clientConnection, &QTcpSocket::readyRead, this, [&](){
            QByteArray array = clientConnection->readAll();
            ui->textEdit->append("客户端：" + array);
//            ui->textEdit->setAlignment(Qt::AlignRight);
        });
    });

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    if(!clientConnection) // 判断是否连接
    {
        qDebug() << "No connection!";
        return;
    }

    clientConnection->write(ui->textEdit_2->toPlainText().toUtf8());
    ui->textEdit->append("服务器：" + ui->textEdit_2->toPlainText());
//    ui->textEdit->setAlignment(Qt::AlignLeft);
    ui->textEdit_2->clear();
}
