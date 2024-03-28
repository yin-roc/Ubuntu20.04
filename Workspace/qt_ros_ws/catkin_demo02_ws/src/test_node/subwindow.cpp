#include "subwindow.h"
#include "ui_subwindow.h"

Subwindow::Subwindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Subwindow)
{
    ui->setupUi(this);
}

Subwindow::~Subwindow()
{
    delete ui;
}
