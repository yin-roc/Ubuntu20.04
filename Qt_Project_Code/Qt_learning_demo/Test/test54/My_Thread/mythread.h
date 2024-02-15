#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QSemaphore>

class Producer : public QThread
{
public:
    Producer() { stopped = false;}
    void stop();

protected:
    void run();

private:
    bool stopped;
};


class Consumer : public QThread
{
    Q_OBJECT
public:
    Consumer(){ stopped = false;}
    void stop();

protected:
    void run(); // 线程从 run 函数开始运行，类似于 main 函数，run 函数的调用靠的是 QThread 类里面的 start

private:
    bool stopped;

};

#endif // MYTHREAD_H
