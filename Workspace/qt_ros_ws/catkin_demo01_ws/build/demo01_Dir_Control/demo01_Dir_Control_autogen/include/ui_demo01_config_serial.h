/********************************************************************************
** Form generated from reading UI file 'demo01_config_serial.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEMO01_CONFIG_SERIAL_H
#define UI_DEMO01_CONFIG_SERIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_demo01_Config_Serial
{
public:
    QPushButton *pushButton;
    QPushButton *open_serial_pushButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;

    void setupUi(QWidget *demo01_Config_Serial)
    {
        if (demo01_Config_Serial->objectName().isEmpty())
            demo01_Config_Serial->setObjectName("demo01_Config_Serial");
        demo01_Config_Serial->resize(300, 300);
        pushButton = new QPushButton(demo01_Config_Serial);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(190, 240, 89, 25));
        open_serial_pushButton = new QPushButton(demo01_Config_Serial);
        open_serial_pushButton->setObjectName("open_serial_pushButton");
        open_serial_pushButton->setGeometry(QRect(90, 30, 121, 51));
        widget = new QWidget(demo01_Config_Serial);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(80, 110, 124, 27));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName("comboBox");

        horizontalLayout->addWidget(comboBox);


        retranslateUi(demo01_Config_Serial);

        QMetaObject::connectSlotsByName(demo01_Config_Serial);
    } // setupUi

    void retranslateUi(QWidget *demo01_Config_Serial)
    {
        demo01_Config_Serial->setWindowTitle(QCoreApplication::translate("demo01_Config_Serial", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("demo01_Config_Serial", "back", nullptr));
        open_serial_pushButton->setText(QCoreApplication::translate("demo01_Config_Serial", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        label->setText(QCoreApplication::translate("demo01_Config_Serial", "\344\270\262\345\217\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class demo01_Config_Serial: public Ui_demo01_Config_Serial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEMO01_CONFIG_SERIAL_H
