#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPicture>
#include <QBitmap>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    /*
    // QPicture 可以理解为是一个绘图的容器，里面保存有绘图的记录和重绘制的指令
    // 存储的形式是二进制形式，也就是说我们无法双击打开 picture 文件

    QPicture pic;
//    QPainter painter(&pic);
    QPainter painter;
    painter.begin(&pic); // 为了和 end 成对出现
    painter.setPen(Qt::red);
    painter.drawEllipse(QPoint(100, 100), 50, 50);
    painter.end();
    pic.save("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/34_Picture_Bitmap/Picture_Bitmap/Image/pic.jpg");
    */

    // QBitmap 绘制出来的是黑白的

    QBitmap bm(400, 300);
    QPainter painter(&bm);
    painter.setPen(Qt::red);
    painter.drawEllipse(QPoint(100, 100), 50, 50);
    bm.save("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/34_Picture_Bitmap/Picture_Bitmap/Image/bm.jpg");


}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent *)
{
    /*
    QPainter painter(this);
    QPicture pic;
    // 加载图片
    pic.load("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/34_Picture_Bitmap/Picture_Bitmap/Image/pic.jpg");
    painter.drawPicture(0, 0, pic);
    */

    // 用QBitmap打开彩色图片
    QPainter painter(this);
    QBitmap bm;
    // 加载图片
    bm.load("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/34_Picture_Bitmap/Picture_Bitmap/Image/optimus prime.jpeg");
    painter.drawPixmap(0, 0, bm);



}


