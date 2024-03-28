/********************************************************************************
** Form generated from reading UI file 'sub1.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUB1_H
#define UI_SUB1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sub1
{
public:

    void setupUi(QWidget *Sub1)
    {
        if (Sub1->objectName().isEmpty())
            Sub1->setObjectName("Sub1");
        Sub1->resize(400, 300);

        retranslateUi(Sub1);

        QMetaObject::connectSlotsByName(Sub1);
    } // setupUi

    void retranslateUi(QWidget *Sub1)
    {
        Sub1->setWindowTitle(QCoreApplication::translate("Sub1", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sub1: public Ui_Sub1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUB1_H
