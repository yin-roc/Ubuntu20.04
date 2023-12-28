#include "widget.h"
#include "ui_widget.h"
#include <myclass.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->toolButton->setIcon(QIcon(":/Image/Images/小悟空.png"));

    ui->radioButton_2->setChecked(true);

    MyClass * mc = new MyClass(this);

    connect(ui->rBscore_5, &QRadioButton::clicked, mc, &MyClass::MySlot);

}

Widget::~Widget()
{
    delete ui;
}

