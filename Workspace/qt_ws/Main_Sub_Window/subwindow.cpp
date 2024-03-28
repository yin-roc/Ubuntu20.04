#include "subwindow.h"
#include "ui_subwindow.h"

Subwindow::Subwindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Subwindow)
{
    ui->setupUi(this);

    this->setWindowTitle("屏幕二");

    connect(ui->pushButton, &QPushButton::clicked, this, &Subwindow::sendSlot);
}

void Subwindow::sendSlot(){
    emit mySignal();
}

Subwindow::~Subwindow()
{
    delete ui;
}

