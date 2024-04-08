/********************************************************************************
** Form generated from reading UI file 'view1_1.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW1_1_H
#define UI_VIEW1_1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_View1_1
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *View1_1)
    {
        if (View1_1->objectName().isEmpty())
            View1_1->setObjectName("View1_1");
        View1_1->resize(600, 400);
        label = new QLabel(View1_1);
        label->setObjectName("label");
        label->setGeometry(QRect(240, 180, 67, 17));
        pushButton = new QPushButton(View1_1);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(240, 110, 89, 25));

        retranslateUi(View1_1);

        QMetaObject::connectSlotsByName(View1_1);
    } // setupUi

    void retranslateUi(QWidget *View1_1)
    {
        View1_1->setWindowTitle(QCoreApplication::translate("View1_1", "Form", nullptr));
        label->setText(QCoreApplication::translate("View1_1", "view1-1", nullptr));
        pushButton->setText(QCoreApplication::translate("View1_1", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class View1_1: public Ui_View1_1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW1_1_H
