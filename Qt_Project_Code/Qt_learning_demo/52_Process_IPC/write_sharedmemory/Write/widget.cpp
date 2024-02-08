#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    sharedmemory.setKey("My_Shared_Memory");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    if(sharedmemory.isAttached()) // 是否处于被绑定状态中
    {
        sharedmemory.detach(); // 解绑
    }

    if(!sharedmemory.create(100, QSharedMemory::ReadWrite)) // 尝试创建一个新的共享内存区域
    {
        qDebug() << "Failed to create shared memory!";
        return;
    }

    sharedmemory.lock(); // 共享内存上锁,以确保在修改共享内存时不会被其他进程干扰。
    //--------临界区的内容不允许其他进程访问---------------
    QByteArray arr = ui->lineEdit->text().toLatin1();

    // memcpy(void * dst, void * src, size_t);
    // 拷贝
    memcpy(sharedmemory.data(), arr.data(), (size_t)qMin(sharedmemory.size(), ui->lineEdit->text().size()));


    //-----------------------------------------
    sharedmemory.unlock(); // 解锁共享内存，表示临界区操作结束，其他进程可以访问共享内存

}
