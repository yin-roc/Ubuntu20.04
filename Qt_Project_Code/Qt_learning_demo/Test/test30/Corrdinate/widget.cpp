#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

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


void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    /*
    // 1.抗锯齿：边缘平滑 Antialiasing，translate
//    QPen pen(QColor(255, 0, 0));
    painter.setPen(QPen(Qt::red, 15));
    painter.drawEllipse(QPoint(200, 150), 100, 100);

    painter.setRenderHints(QPainter::Antialiasing); // 抗锯齿操作
    painter.translate(200, 0); // 平移
    painter.drawEllipse(QPoint(200, 150), 100, 100);
    */

    /*
    // 2.旋转 rotate
    painter.setPen(QPen(Qt::red, 10));
    painter.drawLine(QPoint(10, 10), QPoint(100, 100));
    painter.save(); // 保存一下当前的设置
    painter.translate(200, 0);
    painter.rotate(90); // 顺时针旋转90度
    painter.setPen(QPen(Qt::blue, 10));
    painter.drawLine(QPoint(10, 10), QPoint(100, 100));
    painter.restore(); // 恢复到之前的状态
    */

    /*
    // 3.缩放 scale
    painter.setPen(QPen(Qt::red));
    painter.setBrush(Qt::yellow);
    painter.drawRect(50, 50, 50, 50);
    painter.save();
    painter.scale(1.5, 2);
    painter.setBrush(Qt::green);
    painter.drawRect(50, 50, 50, 50);
    painter.restore();
    */

    // 4.扭曲 shear
    painter.setPen(QPen(Qt::blue));
    painter.setBrush(Qt::yellow);
    painter.drawRect(50, 50, 50, 50);
    painter.save();
    painter.shear(0.5, 0); // 左上角 50*1.5 = 75， 右下角 100*1.5 = 150
    painter.setBrush(Qt::gray);
    painter.drawRect(50, 50, 50, 50);
    painter.restore();
}

