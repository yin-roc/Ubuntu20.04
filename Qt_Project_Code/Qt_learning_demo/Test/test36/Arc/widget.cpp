#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QtMath>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    resize(1600, 900); // 原型this->resize(),但在widget构造函数里面，因此省略了this
    this->setStyleSheet("background-color: black"); // 背景全黑
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

    painter.drawText(720 * qCos(qDegreesToRadians(30.0)), 720 * qSin(qDegreesToRadians(-30.0)), "-30°");
    painter.drawText(720 * qCos(qDegreesToRadians(60.0)), 720 * qSin(qDegreesToRadians(-60.0)), "-60°");
    painter.drawText(720 * qCos(qDegreesToRadians(90.0)), 720 * qSin(qDegreesToRadians(-90.0)), "-90°");
    painter.drawText(720 * qCos(qDegreesToRadians(120.0)), 720 * qSin(qDegreesToRadians(-120.0)), "-120°");
    painter.drawText(720 * qCos(qDegreesToRadians(150.0)), 720 * qSin(qDegreesToRadians(-150.0)), "-150°");
    painter.drawText(720 * qCos(qDegreesToRadians(180.0)), 720 * qSin(qDegreesToRadians(-180.0)), "-180°");

    painter.drawText(140, 30, "10cm");
    painter.drawText(280, 30, "20cm");
    painter.drawText(420, 30, "30cm");
    painter.drawText(560, 30, "40cm");
    painter.drawText(700, 30, "50cm");

}


