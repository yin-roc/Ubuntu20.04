#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    sharememory.setKey("My_Shared_Memory");

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    if(sharememory.isAttached())
    {
        sharememory.detach();
    }

    if(!sharememory.create(100, QSharedMemory::ReadWrite))
    {
        qDebug() << "Failed to create shared memory!";
        return ;
    }

    sharememory.lock();

    QByteArray arr = ui->lineEdit->text().toLatin1();

    memcpy(sharememory.data(), arr.data(), (size_t)qMin(sharememory.size(), ui->lineEdit->text().size()));

    sharememory.unlock();

}
