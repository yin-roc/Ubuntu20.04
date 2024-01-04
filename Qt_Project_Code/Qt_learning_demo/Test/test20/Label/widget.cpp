#include "widget.h"
#include "ui_widget.h"
#include <QMovie>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->label->setText("I Love You, Rick!");

    ui->label_2->setPixmap(QPixmap(":/Image/Image/1.jpeg")); // 插入图片
    ui->label_2->setScaledContents(true);

//    ui->label_3->setPixmap(QPixmap(":/Image/Image/2.gif"));
//    ui->label_3->setScaledContents(true);

    QMovie * mv = new QMovie(":/Image/Image/2.gif");
    ui->label_3->setMovie(mv);
    ui->label_3->setScaledContents(true);
    mv->start();


}

Widget::~Widget()
{
    delete ui;
}

