#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void paintEvent(QPaintEvent *);

public slots:
    void timerTimeOut();

private:
    Ui::Widget *ui;
    double angle = 0.0;
    int flag = 0; // 0代表逆时针转动，1代表顺时针转动

};
#endif // WIDGET_H