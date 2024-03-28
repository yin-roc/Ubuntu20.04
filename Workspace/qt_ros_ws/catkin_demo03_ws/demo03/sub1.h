#ifndef SUB1_H
#define SUB1_H

#include <QWidget>

namespace Ui {
class Sub1;
}

class Sub1 : public QWidget
{
    Q_OBJECT

public:
    explicit Sub1(QWidget *parent = nullptr);
    ~Sub1();

private:
    Ui::Sub1 *ui;
};

#endif // SUB1_H
