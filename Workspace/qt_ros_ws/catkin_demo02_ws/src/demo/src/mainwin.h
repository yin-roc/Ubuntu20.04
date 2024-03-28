#ifndef MAINWIN_H
#define MAINWIN_H

#include <QWidget>


namespace Ui {
class MainWin;
}

class MainWin : public QWidget
{
    Q_OBJECT

public:
    explicit MainWin(QWidget *parent = nullptr);
    ~MainWin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWin *ui;
};

#endif // MAINWIN_H
