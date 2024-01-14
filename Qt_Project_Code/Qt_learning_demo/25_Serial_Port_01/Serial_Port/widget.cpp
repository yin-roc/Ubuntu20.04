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

    // 定期扫描当前外部环境，是否有外部设备
    // 需要一个定时器

    timer = new QTimer(this);
    timer->start(500);
    connect(timer, &QTimer::timeout, this, &Widget::TimerEvent1);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::TimerEvent1()
{
//    qDebug() << "hello world";
    QStringList newPortStringList;

    newPortStringList.clear(); // 清空操作，否则每次都在增加

    foreach (const QSerialPortInfo & info, QSerialPortInfo::availablePorts()) {
        newPortStringList += info.portName();
    }
        if(newPortStringList.size() != portStringList.size()) // 如果不加该判断，会每0.5秒加入所有串口，而没有清空之前语句
        {
            portStringList = newPortStringList; // 更新当前容器
            ui->comboBox->clear();  // 清空
            ui->comboBox->addItems(newPortStringList);
        }
}
