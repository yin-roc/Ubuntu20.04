#include "view1.h"
#include "ui_view1.h"
#include "view2.h"

view1::view1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::view1)
{
    ui->setupUi(this);

    this->setWindowTitle("View1");
    this->resize(800, 600);
}

view1::~view1()
{
    delete ui;
}
