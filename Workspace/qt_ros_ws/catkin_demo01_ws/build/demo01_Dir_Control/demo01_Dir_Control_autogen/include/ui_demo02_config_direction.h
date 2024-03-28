/********************************************************************************
** Form generated from reading UI file 'demo02_config_direction.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEMO02_CONFIG_DIRECTION_H
#define UI_DEMO02_CONFIG_DIRECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_demo02_config_direction
{
public:
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;

    void setupUi(QWidget *demo02_config_direction)
    {
        if (demo02_config_direction->objectName().isEmpty())
            demo02_config_direction->setObjectName("demo02_config_direction");
        demo02_config_direction->resize(352, 180);
        pushButton_3 = new QPushButton(demo02_config_direction);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(220, 70, 91, 41));
        QFont font;
        font.setPointSize(18);
        pushButton_3->setFont(font);
        pushButton_3->setIconSize(QSize(25, 25));
        pushButton_4 = new QPushButton(demo02_config_direction);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(130, 110, 91, 41));
        pushButton_4->setFont(font);
        pushButton_4->setIconSize(QSize(25, 25));
        pushButton = new QPushButton(demo02_config_direction);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(130, 30, 91, 41));
        pushButton->setFont(font);
        pushButton->setIconSize(QSize(25, 25));
        pushButton_2 = new QPushButton(demo02_config_direction);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(40, 70, 91, 41));
        pushButton_2->setFont(font);
        pushButton_2->setIconSize(QSize(25, 25));
        pushButton_5 = new QPushButton(demo02_config_direction);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(250, 140, 89, 25));

        retranslateUi(demo02_config_direction);

        QMetaObject::connectSlotsByName(demo02_config_direction);
    } // setupUi

    void retranslateUi(QWidget *demo02_config_direction)
    {
        demo02_config_direction->setWindowTitle(QCoreApplication::translate("demo02_config_direction", "Form", nullptr));
        pushButton_3->setText(QCoreApplication::translate("demo02_config_direction", "\345\217\263\350\275\254", nullptr));
        pushButton_4->setText(QCoreApplication::translate("demo02_config_direction", "\345\220\216\351\200\200", nullptr));
        pushButton->setText(QCoreApplication::translate("demo02_config_direction", "\345\211\215\350\277\233", nullptr));
        pushButton_2->setText(QCoreApplication::translate("demo02_config_direction", "\345\267\246\344\274\240", nullptr));
        pushButton_5->setText(QCoreApplication::translate("demo02_config_direction", "back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class demo02_config_direction: public Ui_demo02_config_direction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEMO02_CONFIG_DIRECTION_H
