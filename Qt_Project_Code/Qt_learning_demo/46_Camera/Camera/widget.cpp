#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QFileDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QList<QCameraInfo> cameras = QCameraInfo::availableCameras(); // 获取系统上可用摄像头的信息
    if(cameras.count() > 0) // 检测到摄像头
    {
        // 输出已有摄像头信息
        foreach (const QCameraInfo &cameraInfo, cameras)
            qDebug() << cameraInfo.deviceName();
        camera = new QCamera(cameras.at(0)); // 从之前提到的摄像头列表中选择第一个摄像头（索引为0）
    }

    viewfinder = new QCameraViewfinder(this);
    camera->setViewfinder(viewfinder);
    viewfinder->resize(800, 350);

    imageCapture = new QCameraImageCapture(camera); // 使用摄像头进行截图

    camera->start();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    camera->setCaptureMode(QCamera::CaptureStillImage); // 设置摄像头的捕捉模式为静态图像
    QString filename = QFileDialog::getSaveFileName(); // 弹出一个文件对话框，让用户选择保存图像的文件名和位置
    imageCapture->capture(filename); // 捕捉到的图像保存到用户选择的文件中，文件名由 fileName 变量指定
}
