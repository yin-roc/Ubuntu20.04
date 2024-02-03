#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    videowidget = new QVideoWidget(this);

    videowidget->resize(800, 300);
    player->setVideoOutput(videowidget); // 设置视频显示所在

    connect(player, &QMediaPlayer::durationChanged, this, &Widget::Get_Duration);

    connect(ui->horizontalSlider, &QSlider::valueChanged, this, &Widget::Slider_Changed);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    fileName = QFileDialog::getOpenFileName(this, "Open File", "..\\");
    player->setMedia(QUrl::fromLocalFile(fileName));
//    qDebug() << player->duration();
    player->play();
}

void Widget::on_pushButton_2_clicked()
{
    player->play();
}

void Widget::on_pushButton_3_clicked()
{
    player->pause();
}

void Widget::on_pushButton_4_clicked()
{
    player->stop();
}

void Widget::Get_Duration()
{
    ui->horizontalSlider->setMaximum(player->duration());
}

void Widget::Slider_Changed()
{
    pos = ui->horizontalSlider->value();
    player->setPosition(pos);
}


