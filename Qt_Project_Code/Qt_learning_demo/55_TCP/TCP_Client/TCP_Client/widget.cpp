#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    tcpSocket = new QTcpSocket(this);

    connect(tcpSocket, &QTcpSocket::readyRead, this, [&](){
        QByteArray array = tcpSocket->readAll();
        ui->textEdit->append("服务器：" + array);
//        ui->textEdit->setAlignment(Qt::AlignLeft);
    });

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    tcpSocket->connectToHost(ui->lineEdit->text(), ui->lineEdit_2->text().toInt());

}

void Widget::on_pushButton_2_clicked()
{
    if(!tcpSocket)
    {
        qDebug() << "No connection!";
        return ;
    }

    tcpSocket->write(ui->textEdit_2->toPlainText().toUtf8());
    ui->textEdit->append("客户端：" + ui->textEdit_2->toPlainText());
//    ui->textEdit->setAlignment(Qt::AlignRight);
    ui->textEdit_2->clear();
}
