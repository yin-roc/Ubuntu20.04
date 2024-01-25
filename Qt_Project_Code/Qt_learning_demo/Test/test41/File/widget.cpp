#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, [&](){
        QString filename = QFileDialog::getOpenFileName(this, "打开文件", "/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/Test/test41/File");
        ui->lineEdit->setText(filename);
        QFile file(filename); // 将QFile对象关联到指定文件

        // 读
        file.open(QIODevice::ReadOnly);
//        QByteArray array = file.readAll(); // 读取全部内容
        QByteArray array;
        while(!file.atEnd())
        {
            array += file.readLine(); // 一行一行的读取
        }
        ui->textEdit->setText(array); // 此处发生了隐式转换
        file.close();

        // 写
        file.open(QIODevice::Append); // 单纯写入会覆盖原有内容，因此选择在原文末尾追加
        file.write("I love you, Rick!");
        file.close(); // 隐式转换
    });

    QFile file("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/Test/test41/File/MyTest.txt");
    QFileInfo info(file);
    qDebug() << "绝对路径：" << info.absoluteFilePath();
    qDebug() << "文件名：" << info.fileName();
    qDebug() << "后缀名：" << info.suffix();
    qDebug() << "创建时间：" << info.created().toString("yyyy.MM.dd hh:mm:ss");
    qDebug() << "文件大小：" << info.size();

    file.open(QIODevice::ReadOnly);
    file.seek(0);
    QByteArray array = file.read(5);
    qDebug() << "前 5 个字节：" << array;
    qDebug() << "当前位置：" << file.pos();
    file.seek(15);
    array = file.read(5);
    qDebug() << "第 16 ～ 20 个字节：" << array;
    file.close();
}

Widget::~Widget()
{
    delete ui;
}

