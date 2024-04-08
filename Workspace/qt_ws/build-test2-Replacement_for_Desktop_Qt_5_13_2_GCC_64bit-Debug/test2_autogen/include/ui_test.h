/********************************************************************************
** Form generated from reading UI file 'test.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Test
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Test)
    {
        if (Test->objectName().isEmpty())
            Test->setObjectName("Test");
        Test->resize(169, 99);
        label = new QLabel(Test);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 10, 67, 17));
        pushButton = new QPushButton(Test);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 40, 89, 25));
        pushButton_2 = new QPushButton(Test);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(50, 70, 89, 25));

        retranslateUi(Test);

        QMetaObject::connectSlotsByName(Test);
    } // setupUi

    void retranslateUi(QWidget *Test)
    {
        Test->setWindowTitle(QCoreApplication::translate("Test", "Form", nullptr));
        label->setText(QCoreApplication::translate("Test", "Test", nullptr));
        pushButton->setText(QCoreApplication::translate("Test", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Test", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Test: public Ui_Test {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H
