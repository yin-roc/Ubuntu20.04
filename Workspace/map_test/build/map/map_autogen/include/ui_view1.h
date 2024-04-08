/********************************************************************************
** Form generated from reading UI file 'view1.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW1_H
#define UI_VIEW1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <view2.h>

QT_BEGIN_NAMESPACE

class Ui_View1
{
public:
    QLabel *label;
    View2 *widget;

    void setupUi(QWidget *View1)
    {
        if (View1->objectName().isEmpty())
            View1->setObjectName("View1");
        View1->resize(439, 326);
        label = new QLabel(View1);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 20, 67, 17));
        widget = new View2(View1);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(50, 80, 321, 181));

        retranslateUi(View1);

        QMetaObject::connectSlotsByName(View1);
    } // setupUi

    void retranslateUi(QWidget *View1)
    {
        View1->setWindowTitle(QCoreApplication::translate("View1", "Form", nullptr));
        label->setText(QCoreApplication::translate("View1", "View1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class View1: public Ui_View1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW1_H
