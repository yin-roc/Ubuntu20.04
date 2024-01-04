#ifndef MY_CUSTOM_CONTROLLER_H
#define MY_CUSTOM_CONTROLLER_H

#include <QWidget>

namespace Ui {
class My_Custom_Controller;
}

class My_Custom_Controller : public QWidget
{
    Q_OBJECT

public:
    explicit My_Custom_Controller(QWidget *parent = nullptr);
    ~My_Custom_Controller();
    int get_Current_Value();

private:
    Ui::My_Custom_Controller *ui;
};

#endif // MY_CUSTOM_CONTROLLER_H
