#include "widget.h"
#include "ui_widget.h"
#include <myclass.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    MyClass * mc = new MyClass(this);

    ui->toolButton->setIcon(QIcon(":/Image/Images/小悟空.png")); //插入资源文件

    ui->radioButton_2->setChecked(true); // 默认选项设置

    connect(ui->rBscore_5, &QRadioButton::clicked, mc, &MyClass::MySlot); // 关联信号与槽，使之能自动的点击某分数跳出一个评价

}

Widget::~Widget()
{
    delete ui;
}

