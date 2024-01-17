#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMessageBox>

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

    serial = new QSerialPort(this);

    ui->comboBox_2->setCurrentIndex(5);
    ui->comboBox_3->setCurrentIndex(3);
    ui->comboBox_4->setCurrentIndex(2);
    ui->comboBox_5->setCurrentIndex(0);
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

void Widget::on_pushButton_clicked()
{
    if(ui->pushButton->text() == QString("打开串口"))
    {
        // 串口名
        serial->setPortName(ui->comboBox->currentText());

        // 波特率
        serial->setBaudRate(ui->comboBox_2->currentText().toInt());

        // 数据位
        switch(ui->comboBox_3->currentText().toInt()) // 枚举类型
        {
            case 5:serial->setDataBits(QSerialPort::Data5); break;
            case 6:serial->setDataBits(QSerialPort::Data6); break;
            case 7:serial->setDataBits(QSerialPort::Data7); break;
            case 8:serial->setDataBits(QSerialPort::Data8); break;
            default:serial->setDataBits(QSerialPort::UnknownDataBits); break;
        }

        // 校验位
        switch(ui->comboBox_4->currentIndex())
        {
            case 0: serial->setParity(QSerialPort::EvenParity);break;
            case 1: serial->setParity(QSerialPort::OddParity);break;
            case 2: serial->setParity(QSerialPort::NoParity);break;
            default: serial->setParity(QSerialPort::UnknownParity);break;
        }

        // 停止位
        switch(ui->comboBox_5->currentIndex())
        {
            case 0: serial->setStopBits(QSerialPort::OneStop);break;
            case 1: serial->setStopBits(QSerialPort::OneAndHalfStop);break;
            case 2: serial->setStopBits(QSerialPort::TwoStop);break;
            default: serial->setStopBits(QSerialPort::UnknownStopBits);break;
        }

        // 流控
        serial->setFlowControl(QSerialPort::NoFlowControl);

        if(!serial->open(QIODevice::ReadWrite))
        {
            QMessageBox::information(this, "错误提示", "无法打开串口", QMessageBox::Ok);
            return ;
        }

        ui->comboBox->setEnabled(false); // 禁止修改相应参数
        ui->comboBox_2->setEnabled(false);
        ui->comboBox_3->setEnabled(false);
        ui->comboBox_4->setEnabled(false);
        ui->comboBox_5->setEnabled(false);

        ui->pushButton->setText("关闭串口");
    }
    else
    {
        serial->close();
        ui->comboBox->setEnabled(true);
        ui->comboBox_2->setEnabled(true);
        ui->comboBox_3->setEnabled(true);
        ui->comboBox_4->setEnabled(true);
        ui->comboBox_5->setEnabled(true);

        ui->pushButton->setText("打开串口");
    }
}
