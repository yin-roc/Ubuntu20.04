#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("接收端");

    ui->lineEdit->setText("127.0.0.1");

    receiver = new QUdpSocket(this);



}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_2_clicked()
{
    receiver->bind(ui->lineEdit_2->text().toInt()); // 绑定端口号
    connect(receiver, &QUdpSocket::readyRead, this, [&](){
        QByteArray datagram;
        datagram.resize(receiver->pendingDatagramSize());
        receiver->readDatagram(datagram.data(), datagram.size());
        ui->textEdit->append("对方：" + datagram);
    });

    ui->pushButton_2->setEnabled(false);
    ui->lineEdit_2->setEnabled(false);
}
