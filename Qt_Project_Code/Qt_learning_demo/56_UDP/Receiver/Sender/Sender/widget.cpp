#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("主机2");
    sender = new QUdpSocket(this);


    ui->lineEdit_3->setText("8888");
    sender->bind(ui->lineEdit_3->text().toInt());
    connect(sender, &QUdpSocket::readyRead, this, [&](){
        QByteArray datagram;
        datagram.resize(sender->pendingDatagramSize());
        sender->readDatagram(datagram.data(), datagram.size());
        ui->textEdit->append("对方：" + datagram);
    });

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QByteArray datagram = ui->textEdit_2->toPlainText().toUtf8();
    sender->writeDatagram(datagram.data(), datagram.size(), QHostAddress(ui->lineEdit->text()), ui->lineEdit_2->text().toInt());
    ui->textEdit->append("本机：" + ui->textEdit_2->toPlainText());
    ui->textEdit_2->clear();

}
