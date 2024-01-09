#include "widget.h"
#include "ui_widget.h"
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 方法1
    QTimer * timer = new QTimer(this);
    timer->start(1000);
    connect(timer, &QTimer::timeout, [&](){
        static int num = 1;
        ui->label->setText(QString::number(num++));
    });

    // 方法2
    timer_id1 = startTimer(500);
    timer_id2 = startTimer(2000);


}

Widget::~Widget()
{
    delete ui;
}


void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == timer_id1)
    {
        static int num1 = 1;
        ui->label_2->setText(QString::number(num1++));
    }

    if(event->timerId() == timer_id2)
    {
        static int num2 = 1;
        ui->label_3->setText(QString::number(num2++));
    }
}
