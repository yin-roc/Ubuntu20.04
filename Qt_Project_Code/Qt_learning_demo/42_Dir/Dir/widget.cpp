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

    QDir myDir("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/42_Dir/Dir");
    ui->listWidget->addItem(myDir.absolutePath()); // 返回文件的绝对路径，但不包括文件名
    ui->listWidget->addItems(myDir.entryList()); // ".":代表路径中的当前目录；".."代表父目录

    myDir.setNameFilters(QStringList("*.cpp")); // 设置过滤器,筛选出所有的cpp文件
    ui->listWidget->addItems(myDir.entryList());

    // 监视某个文件夹下是否被改动过
    myDir.mkdir("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/42_Dir/Dir/mydir");
    connect(&myWatcher, &QFileSystemWatcher::directoryChanged, this, &Widget::showMessage);
    connect(&myWatcher, &QFileSystemWatcher::fileChanged, this, &Widget::showMessage);
    myWatcher.addPath("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/42_Dir/Dir/mydir");
    myWatcher.addPath("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/42_Dir/Dir/Mytest.txt");

}

Widget::~Widget()
{
    delete ui;
}


void Widget::showMessage(const QString &path)
{
    if(path == "/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/42_Dir/Dir/mydir")
        ui->listWidget->addItem("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/42_Dir/Dir/mydir 目录发生改变");
    else
        ui->listWidget->addItem("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/42_Dir/Dir/Mytest.txt 文件发生改变");
    ui->listWidget->addItem("----------------------------------------------------");
}

