#include "mythread.h"
#include <QDebug>

void MyThread::run()
{
    int i = 0;
    while(!stopped)
    {
        qDebug() << "MyThread: " << i;
        msleep(1000);
        // QThread::msleep(); // 因为定义了 MyThread 是 QThread 的派生类
        i += 2;
    }

    stopped = false;
}

void MyThread::stop()
{
    stopped = true;
}



void MyThread_2::run()
{
    int i = 1;
    while(!stopped)
    {
        qDebug() << "MyThread_2: " << i;
        msleep(1000);
        // QThread::msleep(); // 因为定义了 MyThread 是 QThread 的派生类
        i += 2;
    }

    stopped = false;
}

void MyThread_2::stop()
{
    stopped = true;
}
