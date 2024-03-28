#include "mainwin.h"
#include "ui_mainwin.h"

MainWin::MainWin(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWin)
{
    ui->setupUi(this);


    connect(ui->pushButton, &QPushButton::clicked, this, &MainWin::on_pushButton_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWin::on_pushButton_clicked);


    // 输出一条调试消息，确认信号和槽连接成功
    qDebug() << "Signal and slot connected!";
}

MainWin::~MainWin()
{
    delete ui;
}

void MainWin::on_pushButton_clicked()
{
    qDebug() << "Button clicked!";
}

