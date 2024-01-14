#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    resize(800, 600);
    setWindowTitle("串口调试助手");

    timer = new QTimer(this);
    timer->start(500);
    connect(timer, &QTimer::timeout, this, &Widget::TimerEvent_1);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::TimerEvent_1()
{
//    qDebug() << "hello world";
    QStringList newPortStringList;

    newPortStringList.clear();

    foreach (const QSerialPortInfo & info, QSerialPortInfo::availablePorts()) {
        newPortStringList += info.portName();
    }

    if(newPortStringList.size() != portStringList.size())
    {
        portStringList = newPortStringList;
        ui->comboBox->clear();
        ui->comboBox->addItems(newPortStringList);
    }
}

