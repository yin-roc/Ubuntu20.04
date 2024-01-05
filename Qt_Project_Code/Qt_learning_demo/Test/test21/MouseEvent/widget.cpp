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
        qDebug() << "Left button is pressed.";
        qDebug() << "x = " << event->x() << ", y = " << event->y();
    }
    else if(event->button() == Qt::RightButton)
    {
        qDebug() << "Right button is pressed.";
        qDebug() << "x = " << event->globalX() << ", y = " << event->globalY();
    }
}


