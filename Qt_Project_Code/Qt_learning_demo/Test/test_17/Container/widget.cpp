#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 一开始弹出默认的界面
    ui->stackedWidget->setCurrentIndex(2);

//    connect(ui->pB_ScrollArea, &QPushButton::clicked, this, [](){qDebug() << "Hello World!";});

    connect(ui->pB_ScrollArea, &QPushButton::clicked, this, [&](){ui->stackedWidget->setCurrentIndex(0);});
    connect(ui->pB_ToolBox, &QPushButton::clicked, this, [&](){ui->stackedWidget->setCurrentIndex(1);});
    connect(ui->pB_TabWidget, &QPushButton::clicked, this, [&](){ui->stackedWidget->setCurrentIndex(2);});

}

Widget::~Widget()
{
    delete ui;
}

