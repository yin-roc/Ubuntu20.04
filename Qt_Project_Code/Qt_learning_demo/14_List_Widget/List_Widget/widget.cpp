#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->listWidget->addItem("Hello world");
    ui->listWidget->addItem("good morning");

    QListWidgetItem * listitem = new QListWidgetItem("I love you, Rick!");
    ui->listWidget->addItem(listitem);
    listitem->setTextAlignment(Qt::AlignHCenter); // 居中显示

    QStringList list2; // 字符串容器
    list2 << "ABCD" << "EFGH" << "IJKL" << "LMNO";
    ui->listWidget_2->addItems(list2);
}

Widget::~Widget()
{
    delete ui;
}

