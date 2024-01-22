#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    /*
    // 绘图设备 QPixmap
    QPixmap pix(400, 300); // 设置图像像素 400 * 300
    pix.fill(Qt::white); // 背景颜色设置，默认黑色
    QPainter painter(&pix); // 之前使用this，使之运行后可以在widget界面显示
    painter.setPen(Qt::red);
    painter.drawEllipse(QPoint(100, 100), 30, 30);
    // 存放路径及名称
    pix.save("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/Test/test33/Pix_Image/Image/mypix.jpg");
    */

    // QImage
    QImage img(400, 300, QImage::Format_RGB32);
    img.fill(Qt::white);
    QPainter painter(&img);
    painter.setPen(Qt::red);
    painter.drawEllipse(QPoint(100, 100), 50, 50);
    img.save("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/Test/test33/Pix_Image/Image/myImage.jpg");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QImage img;
    img.load("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/Test/test33/Pix_Image/Image/optimus prime.jpeg");
    for(int i = 50; i < 100; i++)
    {
        for(int j = 50; j < 100; j++)
        {
            QRgb rgb = qRgb(255, 0, 0);
            img.setPixel(i, j, rgb);
        }
    }

    painter.drawImage(0, 0, img);
}

