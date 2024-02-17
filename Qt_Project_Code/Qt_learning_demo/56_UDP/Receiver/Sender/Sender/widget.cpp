#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("发送端");
    sender = new QUdpSocket(this);


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
