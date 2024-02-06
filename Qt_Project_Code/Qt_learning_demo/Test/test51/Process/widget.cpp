#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    myprocess.start("/home/yin-roc/Qt/install/5.13.2/gcc_64/bin/assistant");
    myprocess.waitForFinished();
}

void Widget::on_pushButton_2_clicked()
{
    qDebug() << "hello world";
}
