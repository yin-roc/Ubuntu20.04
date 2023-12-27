#ifndef QMYCLASS_H
#define QMYCLASS_H

#include <QWidget>

class QMyClass : public QWidget
{
    Q_OBJECT
public:
    explicit QMyClass(QWidget *parent = nullptr);
    ~QMyClass();

signals:

};

#endif // QMYCLASS_H
