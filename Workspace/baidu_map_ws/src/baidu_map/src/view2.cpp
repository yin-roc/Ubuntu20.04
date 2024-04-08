#include "view2.h"
#include "ui_view2.h"

View2::View2(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::View2)
{
    ui->setupUi(this);
}

View2::~View2()
{
    delete ui;
}
