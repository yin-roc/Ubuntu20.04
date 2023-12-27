#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "myclass1.h"
#include "myclass2.h"

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
    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    MyClass1 *mc1;
    MyClass2 *mc2;

    int num = 1;
};
#endif // WIDGET_H
