#include "widget.h"
#include "ui_widget.h"
#include <QDir>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    QDir myDir(QDir::currentPath());
//    qDebug() << myDir;

    QDir myDir("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/Test/test42/Dir");
    ui->listWidget->addItem(myDir.absolutePath()); // 返回文件的绝对路径，但不包括文件名
    ui->listWidget->addItems(myDir.entryList()); // "."代表当前目录；".."代表父目录

    myDir.setNameFilters(QStringList("*.cpp")); // 设置过滤器，筛选出所有的 Cpp 文件
    ui->listWidget->addItems(myDir.entryList());

    // 监视某个文件下是否被改动过
    myDir.mkdir("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/Test/test42/Dir/myDir");
    // 添加需要监测的文件或目录到监视器中
    myWatcher.addPath("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/Test/test42/Dir/myDir");
    myWatcher.addPath("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/Test/test42/Dir/Mytest.txt");
    // 关联监视器触发信号和槽函数
    connect(&myWatcher, &QFileSystemWatcher::directoryChanged, this, &Widget::Showmessage);
    connect(&myWatcher, &QFileSystemWatcher::fileChanged, this, &Widget::Showmessage);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::Showmessage(const QString &path)
{
    if(path == "/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/Test/test42/Dir/myDir")
        ui->listWidget->addItem("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/Test/test42/Dir/myDir 目录发生改变");
    else
        ui->listWidget->addItem("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/Test/test42/Dir/Mytest.txt 文件发生改变");
    ui->listWidget->addItem("------------------------------------------------------");
}


