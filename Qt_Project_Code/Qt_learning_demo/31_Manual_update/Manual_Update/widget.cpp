#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    angle = 0;
    QTimer *timer = new QTimer(this);
    timer->start(1000);
    connect(timer, &QTimer::timeout, this, [&](){update();});
}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent *)
{
    angle += 10;
    if(angle == 360)
        angle = 0;
    QPainter painter(this);

    painter.setRenderHints(QPainter::Antialiasing);
    painter.translate(width()/2, height()/2);
    painter.drawEllipse(QPoint(0, 0), 120, 120);
    painter.rotate(angle);
    painter.drawLine(QPoint(0, 0), QPoint(100, 0));

}


