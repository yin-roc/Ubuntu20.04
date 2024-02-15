#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
public:
    MyThread() { stopped = false;}
    void stop();

protected:
    void run();

private:
    bool stopped;
};

#endif // MYTHREAD_H
