#include "my_custom_controller.h"
#include "ui_my_custom_controller.h"

My_Custom_Controller::My_Custom_Controller(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::My_Custom_Controller)
{
    ui->setupUi(this);

    void (QSpinBox:: *sbp)(int) = &QSpinBox::valueChanged; // 公众号2022-5-17内容或b站函数指针内容,因为函数QSpinBox::valueChanged有重载
    connect(ui->spinBox, sbp, ui->horizontalSlider, &QSlider::setValue);

    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);
}

My_Custom_Controller::~My_Custom_Controller()
{
    delete ui;
}

int My_Custom_Controller::get_Current_Value()
{
    return ui->spinBox->value();
}
