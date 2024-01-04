#ifndef MY_CUSTOM_WIDGET_H
#define MY_CUSTOM_WIDGET_H

#include <QWidget>

namespace Ui {
class My_Custom_Widget;
}

class My_Custom_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit My_Custom_Widget(QWidget *parent = nullptr);
    ~My_Custom_Widget();
    int get_Current_Value();

private:
    Ui::My_Custom_Widget *ui;
};

#endif // MY_CUSTOM_WIDGET_H
