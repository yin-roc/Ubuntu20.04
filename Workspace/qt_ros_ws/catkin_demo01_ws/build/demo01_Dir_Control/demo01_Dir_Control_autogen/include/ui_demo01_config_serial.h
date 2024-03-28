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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_demo01_Config_Serial
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *demo01_Config_Serial)
    {
        if (demo01_Config_Serial->objectName().isEmpty())
            demo01_Config_Serial->setObjectName("demo01_Config_Serial");
        demo01_Config_Serial->resize(400, 300);
        pushButton = new QPushButton(demo01_Config_Serial);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(280, 240, 89, 25));

        retranslateUi(demo01_Config_Serial);

        QMetaObject::connectSlotsByName(demo01_Config_Serial);
    } // setupUi

    void retranslateUi(QWidget *demo01_Config_Serial)
    {
        demo01_Config_Serial->setWindowTitle(QCoreApplication::translate("demo01_Config_Serial", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("demo01_Config_Serial", "back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class demo01_Config_Serial: public Ui_demo01_Config_Serial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEMO01_CONFIG_SERIAL_H
