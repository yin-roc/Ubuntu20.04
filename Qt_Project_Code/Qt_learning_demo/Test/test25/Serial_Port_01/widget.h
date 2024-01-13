#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QSerialPortInfo>
#include <QSerialPort>

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
    QTimer * timer;
    QStringList portStringList;

private slots:
    void TimerEvent_1();
};
#endif // WIDGET_H
