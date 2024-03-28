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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Subwindow
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *Subwindow)
    {
        if (Subwindow->objectName().isEmpty())
            Subwindow->setObjectName("Subwindow");
        Subwindow->resize(586, 446);
        pushButton = new QPushButton(Subwindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(150, 100, 111, 51));

        retranslateUi(Subwindow);

        QMetaObject::connectSlotsByName(Subwindow);
    } // setupUi

    void retranslateUi(QWidget *Subwindow)
    {
        Subwindow->setWindowTitle(QCoreApplication::translate("Subwindow", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Subwindow", "\345\210\207\346\215\242\345\210\260\344\270\273\347\252\227\345\217\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Subwindow: public Ui_Subwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBWINDOW_H
