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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <view2.h>

QT_BEGIN_NAMESPACE

class Ui_view1
{
public:
    QPushButton *pushButton;
    View2 *widget;

    void setupUi(QWidget *view1)
    {
        if (view1->objectName().isEmpty())
            view1->setObjectName("view1");
        view1->resize(800, 600);
        pushButton = new QPushButton(view1);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(200, 40, 89, 25));
        widget = new View2(view1);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(150, 180, 411, 171));

        retranslateUi(view1);

        QMetaObject::connectSlotsByName(view1);
    } // setupUi

    void retranslateUi(QWidget *view1)
    {
        view1->setWindowTitle(QCoreApplication::translate("view1", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("view1", "View1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class view1: public Ui_view1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW1_H
