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

    painter.setRenderHint(QPainter::Antialiasing); // 抗锯齿


    pen.setColor(Qt::green);
    painter.setPen(pen);

    painter.drawArc(100, 100, 1400, 1400, 0 * 16, 180 * 16); // 参数5以 1/16 度为单位，参数为16，意味着16 * (1/16) = 1度
    painter.drawArc(240, 240, 1120, 1120, 0 * 16, 180 * 16);
    painter.drawArc(380, 380, 840, 840, 0 * 16, 180 * 16);
    painter.drawArc(520, 520, 560, 560, 0 * 16, 180 * 16);
    painter.drawArc(660, 660, 280, 280, 0 * 16, 180 * 16);

    // 底部画一道线
    painter.drawLine(0, 800, 1600, 800);

    // 每隔30度画一道线
    painter.save(); // 保存一下坐标系：原坐标系
    painter.translate(800, 800);

    for(int i = 0; i < 5; i++)
    {
        painter.rotate(-30); // 旋转坐标系30度，相对于原坐标系逆时针旋转30度
        painter.drawLine(0, 0, 720, 0);
    }
    painter.restore(); // 恢复到原坐标系

    painter.save();
    QFont font("Courier 10 Pitch", 30, QFont::Bold, true);
    painter.setFont(font);
    painter.setPen(Qt::green);
    painter.translate(800, 800); // 平移当前坐标系原点

    painter.drawText(720, 0, "0°");

    // 角度刻度
    // x = 720 * cos30, y = 720 * sin30
    painter.drawText(720 * qCos(qDegreesToRadians(30.0)), 720 * qSin(qDegreesToRadians(-30.0)), "30°"); // 坐标原点的右下方才是x正和y正
    painter.drawText(720 * qCos(qDegreesToRadians(60.0)), 720 * qSin(qDegreesToRadians(-60.0)), "60°");
    painter.drawText(720 * qCos(qDegreesToRadians(90.0))-20, 720 * qSin(qDegreesToRadians(-90.0)), "90°");
    painter.drawText(720 * qCos(qDegreesToRadians(120.0))-40, 720 * qSin(qDegreesToRadians(-120.0)), "120°");
    painter.drawText(720 * qCos(qDegreesToRadians(150.0))-80, 720 * qSin(qDegreesToRadians(-150.0)), "150°");
    painter.drawText(720 * qCos(qDegreesToRadians(180.0))-80, 720 * qSin(qDegreesToRadians(-180.0)), "180°");

    // 距离刻度
    painter.drawText(140, 30, "10cm");
    painter.drawText(280, 30, "20cm");
    painter.drawText(420, 30, "30cm");
    painter.drawText(560, 30, "40cm");
    painter.drawText(700, 30, "50cm");

}

