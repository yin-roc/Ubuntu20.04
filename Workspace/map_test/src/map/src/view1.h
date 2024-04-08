#ifndef VIEW1_H
#define VIEW1_H

#include <QWidget>
#include "view2.h"

namespace Ui {
class View1;
}

class View1 : public QWidget
{
    Q_OBJECT

public:
    explicit View1(QWidget *parent = nullptr);
    ~View1();

private:
    Ui::View1 *ui;
};

#endif // VIEW1_H
