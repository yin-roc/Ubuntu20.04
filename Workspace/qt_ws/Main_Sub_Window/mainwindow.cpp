#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "subwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // subw = new Subwindow();
    this->setWindowTitle("屏幕一");



    connect(ui->pushButton, &QPushButton::released, this, &MainWindow::changeWin);

    // 处理子窗口的信号
    connect(&subw, &Subwindow::mySignal, this, &MainWindow::dealSub);
}

void MainWindow::dealSub(){

    this->show();
    subw.hide();
}


void MainWindow::changeWin(){
    // 主窗口隐藏，显示子窗口
    subw.show();
    this->hide();
}



MainWindow::~MainWindow()
{
    delete ui;
}
