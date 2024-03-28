/********************************************************************************
** Form generated from reading UI file 'mainwin.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIN_H
#define UI_MAINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWin
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *MainWin)
    {
        if (MainWin->objectName().isEmpty())
            MainWin->setObjectName("MainWin");
        MainWin->resize(400, 300);
        pushButton = new QPushButton(MainWin);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(130, 120, 89, 25));
        pushButton_2 = new QPushButton(MainWin);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(190, 180, 89, 25));

        retranslateUi(MainWin);

        QMetaObject::connectSlotsByName(MainWin);
    } // setupUi

    void retranslateUi(QWidget *MainWin)
    {
        MainWin->setWindowTitle(QCoreApplication::translate("MainWin", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWin", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWin", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWin: public Ui_MainWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIN_H
