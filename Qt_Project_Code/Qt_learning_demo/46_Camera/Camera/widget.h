#ifndef WIDGET_H
#define WIDGET_H

/*
    QCamera：用于打开摄像头设备；

    QCameraInfo：和摄像头有关的信息和属性；

    QCameraViewfinder：用于显示摄像头捕获的画面；

    QCameraImageCapture：用于摄像头截图。
*/

#include <QWidget>
#include <QCamera>
#include <QCameraInfo>
#include <QCameraViewfinder>
#include <QCameraImageCapture>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QCamera * camera;
    QCameraViewfinder * viewfinder;
    QCameraImageCapture * imageCapture;
};
#endif // WIDGET_H
