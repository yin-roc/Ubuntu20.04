#include "widget.h"
#include "ui_widget.h"
#include <QMovie>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->label->setText("I love you, Rick!");

    ui->label_2->setPixmap(QPixmap(":/Image/Image/1.jpeg")); // 插入图片
    ui->label_2->setScaledContents(true); // 改变图片大小

    QMovie *mv = new QMovie(":/Image/Image/2.gif");
    ui->label_3->setMovie(mv); // 插入动图GIF
    ui->label_3->setScaledContents(true); // 改变动图大小
    mv->start(); // 显示GIF
}

Widget::~Widget()
{
    delete ui;
}

