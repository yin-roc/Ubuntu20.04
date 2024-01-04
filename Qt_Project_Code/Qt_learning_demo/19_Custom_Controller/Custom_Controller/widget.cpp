#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, [&](){qDebug() << ui->widget->get_Current_Value();});
    // 这里的widget是一个小控件，小写的widget，而不是代表整个界面的大写Widget
}

Widget::~Widget()
{
    delete ui;
}


