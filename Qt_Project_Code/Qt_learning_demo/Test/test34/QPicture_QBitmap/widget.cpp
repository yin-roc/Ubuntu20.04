#include "widget.h"
#include "ui_widget.h"
#include <QPicture>
#include <QPainter>
#include <QBitmap>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    /*
    QPicture pic;
//    QPainter painter(&pic); // 形式1
    QPainter painter;   // 形式2
    painter.begin(&pic); // 形式2

    painter.setPen(Qt::red);
    painter.drawEllipse(QPoint(100, 100), 50, 50);
    painter.end();
    pic.save("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/Test/test34/QPicture_QBitmap/Image/pic.jpg");
    */


    // QBitmap 绘制出来的是黑白的
    QBitmap bm(400, 300);
    QPainter painter(&bm);
    painter.setPen(Qt::red);
    painter.drawEllipse(QPoint(100, 100), 50, 50);
    bm.save("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/Test/test34/QPicture_QBitmap/Image/bm.jpg");
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
    pic.load("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/Test/test34/QPicture_QBitmap/Image/pic.jpg");
    painter.drawPicture(0, 0, pic);
    */

    // QBitmap 打开彩色图片
    QPainter painter(this);
    QBitmap bm;
    // 加载图片
    bm.load("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/Test/test34/QPicture_QBitmap/Image/bm.jpg");
    painter.drawPixmap(0, 0, bm);
}


