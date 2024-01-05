#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
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


void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        qDebug() << "Left Button is pressed.";
//        qDebug() << "x = " << event->x() << ", y = " << event->y(); // 在当前界面的局部位置
        qDebug() << "x = " << event->globalX() << ", y = " << event->globalY(); // 全局位置

    }
    else if(Qt::RightButton)
    {
        qDebug() << "Right Button is pressed.";
        qDebug() << "x = " << event->x() << ", y = " << event->y();
    }
}


