#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->comboBox->addItem("博士");
    ui->comboBox->addItem("硕士");
    ui->comboBox->addItem("本科");
    ui->comboBox->addItem("专科");
    ui->comboBox->addItem("高中及以下");

    connect(ui->pushButton, &QPushButton::clicked, this, [&](){ui->label->setFont(ui->fontComboBox->currentFont());});

    QDateTime curDateTime = QDateTime::currentDateTime(); // curDateTime里面既有日期也有时间
    ui->timeEdit->setTime(curDateTime.time());
    ui->dateTimeEdit->setDateTime(curDateTime);
}

Widget::~Widget()
{
    delete ui;
}

