#include "mythread.h"
#include <QDebug>

void MyThread::run()
{
    int i = 0;
    while(!stopped)
    {
        qDebug() << "MyThread: " << i;
        msleep(1000);
        i += 2;
    }

    stopped = false;

}


void MyThread::stop()
{
    stopped = true;
}
