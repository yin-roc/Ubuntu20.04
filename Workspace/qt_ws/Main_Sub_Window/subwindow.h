#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QWidget>

namespace Ui {
class Subwindow;
}

class Subwindow : public QWidget
{
    Q_OBJECT

public:
    explicit Subwindow(QWidget *parent = nullptr);
    ~Subwindow();
    void sendSlot();

signals:
    /*
        信号必须有 signals 关键字来声明；
        信号没有返回值，但可以有参数；
        信号就是函数的声明，只需声明，无需定义；
        使用：emit mySignal();
*/
    void mySignal();

public slots:

private:
    Ui::Subwindow *ui;
};

#endif // SUBWINDOW_H
