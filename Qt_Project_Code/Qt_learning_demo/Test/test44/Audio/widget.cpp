#include "widget.h"
#include "ui_widget.h"
#include <QDir>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);

    // 获取当前应用程序的可执行文件所在的目录路径
    QString appDir = QCoreApplication::applicationDirPath();

    // 使用 QDir 构造函数创建一个 QDir 对象，表示应用程序目录。QDir 是 Qt 提供的处理目录和文件路径的类。
    QDir sourceCodeDir(appDir);

    // 将当前目录切换到上一级目录，即源代码目录
    sourceCodeDir.cdUp();

    //获取切换后的源代码目录的路径。现在，sourceCodePath 包含了源代码目录的绝对路径。
    QString sourceCodePath = sourceCodeDir.path();

    // 构建音频文件的绝对路径
    QString filePath_1 = sourceCodePath + "/Audio/1.mp3";
    player->setMedia(QUrl::fromLocalFile(filePath_1));
    player->setVolume(50);
    player->play();
    player->stop();
}

Widget::~Widget()
{
    delete ui;
}

