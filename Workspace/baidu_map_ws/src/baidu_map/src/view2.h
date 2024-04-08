#ifndef VIEW2_H
#define VIEW2_H

#include <QWidget>

namespace Ui {
class View2;
}

class View2 : public QWidget
{
    Q_OBJECT

public:
    explicit View2(QWidget *parent = nullptr);
    ~View2();

private:
    Ui::View2 *ui;
};

#endif // VIEW2_H
