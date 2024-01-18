#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


private:
    Ui::Widget *ui;
    QTimer *timer;
    QStringList portStringList;
    QSerialPort * serial;
    QString Receivetext; // 表示收到的内容
    long Receive_Byte; // 接收的Receivetext的长度
    QString Sendtext; // 发送的内容
    long Send_Byte; // 发送的Sendtext的长度


private slots:
    void TimerEvent1();
    void on_pushButton_clicked();
    void serialPort_readyRead();
    void on_checkBox_clicked();
    void on_checkBox_2_clicked();
    void on_checkBox_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
};
#endif // WIDGET_H
