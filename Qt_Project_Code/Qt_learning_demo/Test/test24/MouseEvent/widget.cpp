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


bool Widget::event(QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress)
    {
        qDebug() << "按键被按下";
        return true;
    }
    return QWidget::event(event);
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


void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        QPoint temp;
        temp = event->globalPos() - pos;
        move(temp);
    }
}


void Widget::wheelEvent(QWheelEvent *event)
{
    if(event->delta() > 0)
    {
        ui->textEdit->zoomIn();
    }
    else
    {
        ui->textEdit->zoomOut();
    }
}

