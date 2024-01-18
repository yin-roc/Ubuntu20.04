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

    QPen pen(QColor (255, 0, 0)); // 创建了红色画笔对象
    pen.setWidth(3); // 设置画笔宽度为3个像素
    pen.setStyle(Qt::DashDotLine); // 设置画笔样式为虚线点线。
    painter.setPen(pen);    // 将上述配置好的画笔对象设置给painter


    painter.drawLine(QPoint (0, 0), QPoint (100, 100)); // 创建匿名对象；两个参数表示直线的起始位置；线
    painter.drawEllipse(QPoint (100, 100), 20, 20); // 圆形
    painter.drawEllipse(QPoint (100, 100), 50, 80); // 椭圆
    painter.drawRect(100, 100, 30, 30); // 正方形
    painter.drawRect(100, 100, 40, 80); // 长方形
    painter.drawText(100, 100, "I love you, Rick!"); // 显示文本


    QBrush brush(Qt::green, Qt::Dense3Pattern);
    painter.setBrush(brush);
//    painter.setPen(pen);
    painter.drawRect(200, 200, 50, 50);


    QConicalGradient conicalGradient(QPointF(200, 100), 0); // 渐变色 // 参数2：从该角度逆时针开始;这里指从三点钟方向开始
    conicalGradient.setColorAt(0.2, Qt::cyan); // 参数1：0～1，360度*0.2 = 72度，意思从0度开始，逆时针旋转72度
    conicalGradient.setColorAt(0.4, Qt::black);
    conicalGradient.setColorAt(0.7, Qt::red);
    conicalGradient.setColorAt(1, Qt::yellow);

    painter.setBrush(conicalGradient); // 不能使用上一个画刷，上一个画刷全是绿色
    painter.drawEllipse(QPointF(200, 100), 50, 50);
}

