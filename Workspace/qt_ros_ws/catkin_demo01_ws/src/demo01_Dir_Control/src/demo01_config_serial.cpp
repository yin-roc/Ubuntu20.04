#include "demo01_config_serial.h"
#include "ui_demo01_config_serial.h"

demo01_Config_Serial::demo01_Config_Serial(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::demo01_Config_Serial)
{
    ui->setupUi(this);

    this->setWindowTitle("串口调试窗口");
    this->resize(300, 300);
    this->move(800, 400);

    timer = new QTimer(this);
    timer->start(500);
    connect(timer, &QTimer::timeout, this, &demo01_Config_Serial::TimerEvent_1);

    // 返回主界面
    connect(ui->pushButton, &QPushButton::clicked, this, &demo01_Config_Serial::Send_back_to_main_slots);

    // 打开串口
    // connect(ui->open_serial_pushButton, &QPushButton::clicked, this, );
}

void demo01_Config_Serial::TimerEvent_1(){

    QStringList newportStringList;
    foreach(const QSerialPortInfo & info, QSerialPortInfo::availablePorts()){
        newportStringList += info.portName();
    }

    if(newportStringList.size() != portStringList.size()){
        portStringList = newportStringList;
        ui->comboBox->clear();
        ui->comboBox->addItems(newportStringList);
    }
}

void demo01_Config_Serial::Send_back_to_main_slots(){
    emit back_to_main_Signal();
}


demo01_Config_Serial::~demo01_Config_Serial()
{
    delete ui;
}
