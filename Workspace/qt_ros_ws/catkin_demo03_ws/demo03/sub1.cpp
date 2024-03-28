#include "sub1.h"
#include "ui_sub1.h"

Sub1::Sub1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Sub1)
{
    ui->setupUi(this);
}

Sub1::~Sub1()
{
    delete ui;
}
