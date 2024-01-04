#include "my_custom_widget.h"
#include "ui_my_custom_widget.h"

My_Custom_Widget::My_Custom_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::My_Custom_Widget)
{
    ui->setupUi(this);

    void (QSpinBox:: *sbp)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox, sbp, ui->horizontalSlider, &QSlider::setValue);

    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);

}

My_Custom_Widget::~My_Custom_Widget()
{
    delete ui;
}

int My_Custom_Widget::get_Current_Value()
{
    return ui->spinBox->value();
}
