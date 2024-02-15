#include "mythread.h"
#include <QDebug>

const int size = 10;
unsigned int buffer[size];
QSemaphore usedSem(0);
QSemaphore unusedSem(size);


void Producer::run()
{
    int i = 0;
    while(!stopped)
    {
        unusedSem.acquire(); // unusedSem 减 1：请求一个资源，如果计数器大于零，计数器减一，否则线程将被阻塞
        buffer[i] = i;
        msleep(1000);
        qDebug() << "Write to the shared memory";
        usedSem.release(); // usedSem 加 1
        i++;
        if(i == size)
            i = 0;
    }

    stopped = false;
}

void Producer::stop()
{
    stopped = true;
}



void Consumer::run()
{
    int i = 1;
    while(!stopped)
    {
        usedSem.acquire();
        qDebug() << buffer[i];
        unusedSem.release();
        i++;
        if(i == size)
            i = 0;
    }

    stopped = false;
}

void Consumer::stop()
{
    stopped = true;
}
