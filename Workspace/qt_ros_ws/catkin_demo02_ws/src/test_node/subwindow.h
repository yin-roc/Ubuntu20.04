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

private:
    Ui::Subwindow *ui;
};

#endif // SUBWINDOW_H
