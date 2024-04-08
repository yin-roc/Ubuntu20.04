/********************************************************************************
** Form generated from reading UI file 'view2.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW2_H
#define UI_VIEW2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_View2
{
public:
    QLabel *label;

    void setupUi(QWidget *View2)
    {
        if (View2->objectName().isEmpty())
            View2->setObjectName("View2");
        View2->resize(97, 56);
        label = new QLabel(View2);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 67, 17));

        retranslateUi(View2);

        QMetaObject::connectSlotsByName(View2);
    } // setupUi

    void retranslateUi(QWidget *View2)
    {
        View2->setWindowTitle(QCoreApplication::translate("View2", "Form", nullptr));
        label->setText(QCoreApplication::translate("View2", "view2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class View2: public Ui_View2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW2_H
