#include "widget.h"
#include "ui_widget.h"
#include <QDir>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    QString appDir = QCoreApplication::applicationDirPath();
    // 获取上级目录（即源代码目录）
    QDir sourceCodeDir(appDir);
    sourceCodeDir.cdUp();
    QString sourceCodePath = sourceCodeDir.path();
    QString filePath1 = sourceCodePath + "/Audio/1.mp3";
    player->setMedia(QUrl::fromLocalFile(filePath1));
    player->setVolume(50);
    player->play();
    player->stop();

//    打开 wav 文件
    effect = new QSoundEffect(this);
    QString filePath2 = sourceCodePath + "/Audio/2.wav";
    effect->setSource(QUrl::fromLocalFile(filePath2));
    effect->setVolume(0.5);
    effect->play();
    effect->stop();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    player->play();
}

void Widget::on_pushButton_2_clicked()
{
    player->stop();
}

void Widget::on_pushButton_3_clicked()
{
    effect->play();
}

void Widget::on_pushButton_4_clicked()
{
    effect->stop();
}
