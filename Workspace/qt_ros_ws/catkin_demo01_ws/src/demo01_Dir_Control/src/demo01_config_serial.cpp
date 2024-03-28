#include "demo01_config_serial.h"
#include "ui_demo01_config_serial.h"

demo01_Config_Serial::demo01_Config_Serial(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::demo01_Config_Serial)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &demo01_Config_Serial::Send_back_to_main_slots);

}

void demo01_Config_Serial::Send_back_to_main_slots(){
    emit back_to_main_Signal();
}


demo01_Config_Serial::~demo01_Config_Serial()
{
    delete ui;
}
