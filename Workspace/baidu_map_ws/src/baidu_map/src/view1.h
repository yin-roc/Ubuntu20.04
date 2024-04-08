#ifndef VIEW1_H
#define VIEW1_H

#include <QWidget>
#include "view2.h"

namespace Ui {
class view1;
}

class view1 : public QWidget
{
    Q_OBJECT

public:
    explicit view1(QWidget *parent = nullptr);
    ~view1();

private:
    Ui::view1 *ui;
};

#endif // VIEW1_H
