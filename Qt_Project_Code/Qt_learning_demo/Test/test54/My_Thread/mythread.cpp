#include "mythread.h"
#include <QDebug>

const int size = 10;
unsigned int buffer[size];
QSemaphore usedSem(0);
QSemaphore unusedSem(size);

// Producer
void Producer::run()
{
    int i = 0;
    while(!stopped)
    {
        unusedSem.acquire();
        buffer[i] = i;
        msleep(1000);
        qDebug() << "Write to the shared memory.";
        usedSem.release();
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


// Consumer
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
