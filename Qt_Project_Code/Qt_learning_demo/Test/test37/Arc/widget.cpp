#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QtMath>
#include <QTimer>
#include <QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    resize(1600, 900); // 原型this->resize(),但在widget构造函数里面，因此省略了this
    this->setStyleSheet("background-color: black"); // 背景全黑

    // 定时器实现线段旋转
    QTimer * timer = new QTimer(this);
    timer->start(20);
    connect(timer, &QTimer::timeout, this, &Widget::timerTimeout);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen;
    pen.setColor(Qt::green);
    painter.setPen(pen);

    painter.drawArc(100, 100, 1400, 1400, 0 * 16, 180 * 16); // 参数5以 1/16 度为单位，参数为16，意味着16 * (1/16) = 1度
    painter.drawArc(240, 240, 1120, 1120, 0 * 16, 180 * 16);
    painter.drawArc(380, 380, 840, 840, 0 * 16, 180 * 16);
    painter.drawArc(520, 520, 560, 560, 0 * 16, 180 * 16);
    painter.drawArc(660, 660, 280, 280, 0 * 16, 180 * 16);

    // 底部画一道线
    painter.drawLine(0, 800, 1600, 800);

    // 每隔 30 度画一道线
    painter.save();
    painter.translate(800, 800);

    for(int i = 0; i < 5; i++)
    {
        painter.rotate(-30);
        painter.drawLine(0, 0 , 720, 0);
    }
    painter.restore();

    painter.save();
    QFont font("Courier 10 Pitch", 30, QFont::Bold, true);
    painter.setFont(font);
    painter.setPen(Qt::green);
    painter.translate(800, 800);

    painter.drawText(720, 0, "0°");

    // 角度刻度
    painter.drawText(720 * qCos(qDegreesToRadians(30.0)), -720 * qSin(qDegreesToRadians(30.0)), "30°"); // 坐标原点的右下方才是x正和y正
    painter.drawText(720 * qCos(qDegreesToRadians(60.0)), -720 * qSin(qDegreesToRadians(60.0)), "60°");
    painter.drawText(720 * qCos(qDegreesToRadians(90.0))-20, -720 * qSin(qDegreesToRadians(90.0)), "90°");
    painter.drawText(720 * qCos(qDegreesToRadians(120.0))-40, -720 * qSin(qDegreesToRadians(120.0)), "120°");
    painter.drawText(720 * qCos(qDegreesToRadians(150.0))-80, -720 * qSin(qDegreesToRadians(150.0)), "150°");
    painter.drawText(720 * qCos(qDegreesToRadians(180.0))-80, -720 * qSin(qDegreesToRadians(180.0)), "180°");

    // 距离刻度
    painter.drawText(140, 30, "10cm");
    painter.drawText(280, 30, "20cm");
    painter.drawText(420, 30, "30cm");
    painter.drawText(560, 30, "40cm");
    painter.drawText(700, 30, "50cm");
    painter.restore();

    // 扫描线段
    pen.setWidth(12);
    painter.setPen(pen);
    painter.save();
    painter.translate(800, 800);
    int x = int(700 * qCos(qDegreesToRadians(angle)));
    int y = int(-700 * qSin(qDegreesToRadians(angle)));
    painter.drawLine(0, 0, x, y);

    // 添加余影/拖影
    double d_angle = angle;
    if(flag == 0)
    {
        for(int num = 1; num <= d_angle; num++)
        {
            painter.setOpacity(1 - num * 1.0 / ((d_angle > 30.0) ? 30.0 : d_angle));
            x = int(700 * qCos(qDegreesToRadians(d_angle - num)));
            y = int(-700 * qSin(qDegreesToRadians(d_angle - num)));
            painter.drawLine(0, 0, x, y);
            if(num == 30) // 设置最多拖影为 30 个
                break;
        }
    }
    else if(flag == 1)
    {
        for(int num =1; num <= (180 - d_angle); num++)
        {
            painter.setOpacity(1 - num * 1.0 / (((180 - d_angle) > 30.0) ? 30.0 : (180 - d_angle)));
            x = int(700 * qCos(qDegreesToRadians(d_angle + num)));
            y = int(-700 * qSin(qDegreesToRadians(d_angle + num)));
            painter.drawLine(0, 0, x, y);
            if(num == 30)
                break;
        }
    }
    painter.restore();
}


void Widget::timerTimeout()
{
//    qDebug() << "hello world!";
    if(flag == 0)
    {
        angle++;
        if(angle == 180.0)
            flag = 1;
    }
    else
    {
        angle--;
        if(angle == 0)
            flag = 0;
    }

    update();
}
