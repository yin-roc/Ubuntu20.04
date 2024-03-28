/********************************************************************************
** Form generated from reading UI file 'subwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBWINDOW_H
#define UI_SUBWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Subwindow
{
public:

    void setupUi(QWidget *Subwindow)
    {
        if (Subwindow->objectName().isEmpty())
            Subwindow->setObjectName("Subwindow");
        Subwindow->resize(400, 300);

        retranslateUi(Subwindow);

        QMetaObject::connectSlotsByName(Subwindow);
    } // setupUi

    void retranslateUi(QWidget *Subwindow)
    {
        Subwindow->setWindowTitle(QCoreApplication::translate("Subwindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Subwindow: public Ui_Subwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBWINDOW_H
