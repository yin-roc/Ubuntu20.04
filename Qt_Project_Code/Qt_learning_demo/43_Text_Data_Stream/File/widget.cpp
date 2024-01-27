#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDataStream>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, [&](){
        QString filename = QFileDialog::getOpenFileName(this, "打开文件", "/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/43_Text_Data_Stream/File");
        ui->lineEdit->setText(filename);
        QFile file(filename); // 将QFile对象关联到指定文件

        /* // QFile 类读
        // 读
        file.open(QIODevice::ReadOnly);
//        QByteArray array = file.readAll(); // 读取全部内容
        QByteArray array;
        while(!file.atEnd())
        {
            array += file.readLine(); // 一行一行读取
        }
        ui->textEdit->setText(array); // 这里发生了隐式转换
        file.close();

        // 写
        file.open(QIODevice::Append); // 单纯写入会覆盖原有内容，因此选择在原文末尾追加
       file.write("I love you, Rick!"); // 隐式转换
       file.close();
    });
        */


        // QTextStream 类读  文本流
        // 读
        file.open(QIODevice::ReadOnly);

        QTextStream stream(&file); // QFile 类是 QIODevice 类的子类
        stream.setCodec("utf-8"); // 防止中文乱码，设置输出格式

        QByteArray array;
        while(!stream.atEnd())
        {
            array += stream.readLine();
        }

        ui->textEdit->setText(array); // 这里发生了隐式转换
        file.close();

    });


    /*
    // 数据流
    QFile file("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/43_Text_Data_Stream/File/file.dat");
    file.open(QIODevice::WriteOnly);
    QDataStream data_out_stream(&file);
    data_out_stream << QString("Hello world") << (qint32)65;
    file.close();

    file.open(QIODevice::ReadOnly);
    QDataStream data_in_stream(&file); // 读入
    QString str;
    qint32 n;
    data_in_stream >> str >> n;
    qDebug() << "str is" << str << ", n is" << n;
    file.close();
    */


    // UDP, TCP 细讲
    QImage image("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/Qt_learning_demo/43_Text_Data_Stream/File/flower.jpg");
    QByteArray arr;
    QDataStream stream(&arr, QIODevice::ReadWrite);
    stream << image;  // UDP, TCP 细讲

}

Widget::~Widget()
{
    delete ui;
}

