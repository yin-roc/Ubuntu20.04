/********************************************************************************
** Form generated from reading UI file 'my_custom_controller.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MY_CUSTOM_CONTROLLER_H
#define UI_MY_CUSTOM_CONTROLLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_My_Custom_Controller
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpinBox *spinBox;
    QSlider *horizontalSlider;

    void setupUi(QWidget *My_Custom_Controller)
    {
        if (My_Custom_Controller->objectName().isEmpty())
            My_Custom_Controller->setObjectName(QString::fromUtf8("My_Custom_Controller"));
        My_Custom_Controller->resize(246, 58);
        widget = new QWidget(My_Custom_Controller);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 10, 201, 28));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        spinBox = new QSpinBox(widget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout->addWidget(spinBox);

        horizontalSlider = new QSlider(widget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);


        retranslateUi(My_Custom_Controller);

        QMetaObject::connectSlotsByName(My_Custom_Controller);
    } // setupUi

    void retranslateUi(QWidget *My_Custom_Controller)
    {
        My_Custom_Controller->setWindowTitle(QCoreApplication::translate("My_Custom_Controller", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class My_Custom_Controller: public Ui_My_Custom_Controller {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MY_CUSTOM_CONTROLLER_H
