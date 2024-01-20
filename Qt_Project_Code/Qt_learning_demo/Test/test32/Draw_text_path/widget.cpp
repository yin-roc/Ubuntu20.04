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


//void Widget::paintEvent(QPaintEvent *)
//{
//    QPainter painter(this);

//    QFont font("Noto Sans CJK SC Black", 20, QFont::Bold, true); // 设置字体类型、大小、黑体、斜体
////    QFont font("Courier 10 Pitch", 50, QFont::Bold, true);

//    font.setUnderline(true); // 设置下划线

//    painter.setFont(font); // 设置画笔
//    painter.setPen(Qt::blue); // 设置画笔颜色
//    painter.drawText(50, 50, "I love you, Rick!");
//}


void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPainterPath path;

    path.moveTo(50, 250);
    path.lineTo(50, 200);
    path.lineTo(100, 100);
    path.addEllipse(QPoint(100, 100), 30, 30);
    painter.setPen(Qt::red);
    painter.drawPath(path);

    path.translate(200, 0);
    painter.setPen(Qt::blue);
    painter.drawPath(path);
}


