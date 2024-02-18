#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("主机1");

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
    // QUdpSocket::readyRead 信号
    connect(receiver, &QUdpSocket::readyRead, this, [&](){
        // 创建一个 QByteArray 对象 datagram，用于存储接收到的数据
        QByteArray datagram;
        datagram.resize(receiver->pendingDatagramSize()); // // 使用 pendingDatagramSize 函数获取当前待处理数据报的大小

        // 使用 readDatagram 函数从 receiver 接收数据
        receiver->readDatagram(datagram.data(), datagram.size());
        ui->textEdit->append("对方：" + datagram);
    });

    ui->pushButton_2->setEnabled(false);
    ui->lineEdit_2->setEnabled(false);
}

void Widget::on_pushButton_clicked()
{
    QByteArray datagram = ui->textEdit_2->toPlainText().toUtf8();
    receiver->writeDatagram(datagram.data(), datagram.size(), QHostAddress(ui->lineEdit->text()), ui->lineEdit_3->text().toInt());
    ui->textEdit->append("本机：" + ui->textEdit_2->toPlainText());
    ui->textEdit_2->clear();
}
