#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ros_node_1.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Qt界面中的按钮点击事件函数
// 前进
void MainWindow::on_pushButton_clicked()
{
    rosController.publishCommand(0.5, 0.0); // 假设向前移动速度为0.5，角速度为0.0

}

// 后退
void MainWindow::on_pushButton_4_clicked()
{
    rosController.publishCommand(-0.5, 0.0); // 假设向后移动速度为-0.5，角速度为0.0
}

// 左转
void MainWindow::on_pushButton_2_clicked()
{
    rosController.publishCommand(0.0, 0.5); // 假设向左移动速度为0.0，角速度为0.5
}

// 右转
void MainWindow::on_pushButton_3_clicked()
{
    rosController.publishCommand(0.0, -0.5); // 假设向右移动速度为0.0，角速度为-0.5
}

