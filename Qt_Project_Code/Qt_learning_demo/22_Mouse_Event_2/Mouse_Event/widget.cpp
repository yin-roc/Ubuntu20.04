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


void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "Button is released";
}


void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        if(windowState() != Qt::WindowFullScreen)
        {
            setWindowState(Qt::WindowFullScreen);
        }
        else
        {
            setWindowState(Qt::WindowNoState);
        }
    }
}


void Widget::mouseMoveEvent(QMouseEvent *event) // 在窗体范围内，一点一拖动，窗体出现在鼠标点击的位置
{
    if(event->buttons() & Qt::LeftButton) // Button和Buttons的区别
    {
        QPoint temp;

        temp = event->globalPos() - pos; // 鼠标当前的位置 - 当前窗体的位置 = 移动了多少

        move(temp);
    }
}


void Widget::wheelEvent(QWheelEvent *event)
{
    if(event->delta() > 0)
    {
        ui->textEdit->zoomIn(); // 上滚变大
    }
    else
        ui->textEdit->zoomOut(); // 下滚变小
}

