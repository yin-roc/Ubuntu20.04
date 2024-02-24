#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QTcpServer * tcpserver; // 监听套接字
    QTcpSocket * clientConnection = nullptr; // 通信套接字

    bool headInfo = true;
    QString fileName;
    qint64 fileSize;
    qint64 recvSize;
    QFile file;
};
#endif // WIDGET_H