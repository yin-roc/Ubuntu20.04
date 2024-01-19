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
    timer->start(500);
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
        angle =0;

    QPainter painter(this);

    painter.setRenderHints(QPainter::Antialiasing); // 抗锯齿
    painter.translate(width()/2, height()/2); //  使坐标中心位于整个界面的中心，无论如何放大/缩小界面
    painter.drawEllipse(QPoint(0, 0), 120, 120); //
    painter.rotate(angle); // 旋转
    painter.drawLine(QPoint(0, 0), QPoint(100, 0));
}


