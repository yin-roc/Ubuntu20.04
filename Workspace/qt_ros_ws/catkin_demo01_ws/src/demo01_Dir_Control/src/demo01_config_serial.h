#ifndef DEMO01_CONFIG_SERIAL_H
#define DEMO01_CONFIG_SERIAL_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class demo01_Config_Serial;
}

class demo01_Config_Serial : public QWidget
{
    Q_OBJECT

public:
    explicit demo01_Config_Serial(QWidget *parent = nullptr);
    ~demo01_Config_Serial();

signals:
    void back_to_main_Signal();

private slots:
    void Send_back_to_main_slots();


private:
    Ui::demo01_Config_Serial *ui;
};

#endif // DEMO01_CONFIG_SERIAL_H
