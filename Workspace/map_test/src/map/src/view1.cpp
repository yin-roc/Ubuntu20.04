#include "view2.h"
#include "view1.h"
#include "ui_view1.h"

View1::View1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::View1)
{
    ui->setupUi(this);

}

View1::~View1()
{
    delete ui;
}
