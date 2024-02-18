#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    tcpSocket = new QTcpSocket(this);

    connect(tcpSocket, &QTcpSocket::readyRead, this, [&](){
        QByteArray array = tcpSocket->readAll();
        qDebug() << "服务器: " << array;
    });

    mytimer = new QTimer(this);
    connect(mytimer, &QTimer::timeout, this, [&](){
        mytimer->stop();

        qint64 len;
        qint64 sendSize = 0;

        do{
            char buf[4*1024] = {0};
            len = 0;
            len = file.read(buf, sizeof(buf)); // 每次提取多少字节
            tcpSocket->write(buf, len); // 后续内容不足 4kb，所以用 len，而不用 sizeof(buf)
            sendSize += len;
            ui->progressBar->setValue(sendSize / 1024);
        }while(len > 0);
        if(sendSize == fileSize)
        {
            file.close();
            tcpSocket->disconnect();
            tcpSocket->close();
        }
    });

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    tcpSocket->connectToHost(ui->lineEdit->text(), ui->lineEdit_2->text().toInt());
}



void Widget::on_pushButton_2_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this); // 打开文件

    QFileInfo FileData(filePath);
    fileName = FileData.fileName(); // 得到文件名称
    fileSize = FileData.size(); // 得到文件大小

    qDebug() << "文件名： " << fileName;
    qDebug() << "文件大小： " << fileSize;

    if(filePath.isEmpty())
    {
        ui->label_3->setText(filePath);
        file.setFileName(filePath);
        file.open(QIODevice::ReadOnly);

    }

    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(fileSize / 1024);
    ui->progressBar->setValue(0);

}

void Widget::on_pushButton_3_clicked()
{
    // 发送：“我的小苹果.mp3**313256” (先名称后文件大小)
    QString head = fileName + "**" + QString::number(fileSize);
    qint64 length = tcpSocket->write(head.toUtf8());
    if(length > 0) // 发送成功
    {
        // 延时防止粘包
        mytimer->start(20);
    }
    else // 发送失败
    {
        file.close();
    }

}
