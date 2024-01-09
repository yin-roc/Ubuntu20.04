#include "widget.h"
#include "ui_widget.h"
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 方法一：
    QTimer * timer = new QTimer(this);
    timer->start(1000);
    connect(timer, &QTimer::timeout, [&](){
        static int num = 1; // 如果不是static静态类型，那么会一直初始化 num 为1
        ui->label->setText(QString::number(num++)); // QString 里面的方法，将数字转换成字符串
    });

    // 方法二：
    timer_id1 = startTimer(500); // 参数1：定时周期500ms
    timer_id2 = startTimer(2000);

    // 使用timer_id1, timer_id2进行区分，

}

Widget::~Widget()
{
    delete ui;
}


void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == timer_id1) // 因为该函数中得不到WIdget函数中局部变量的值，所以将该函数的值放在类的成员中
    {
        static int num = 1;
        ui->label_2->setText(QString::number(num++));
    }
    if(event->timerId() == timer_id2)
    {
        static int num2 = 1;
        ui->label_3->setText(QString::number(num2++));
    }

}
