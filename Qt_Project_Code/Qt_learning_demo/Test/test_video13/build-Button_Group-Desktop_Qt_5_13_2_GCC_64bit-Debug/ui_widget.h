/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QToolButton *toolButton;
    QGroupBox *groupBox;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QGroupBox *groupBox_2;
    QRadioButton *rBscore_5;
    QRadioButton *rBscore_3;
    QRadioButton *rBscore_4;
    QRadioButton *rBscore_1;
    QRadioButton *rBscore_2;
    QGroupBox *groupBox_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        toolButton = new QToolButton(Widget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(280, 180, 151, 61));
        toolButton->setIconSize(QSize(32, 32));
        toolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton->setAutoRaise(true);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(150, 240, 121, 181));
        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(10, 110, 112, 23));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(10, 30, 112, 23));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(10, 70, 112, 23));
        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(320, 240, 151, 241));
        rBscore_5 = new QRadioButton(groupBox_2);
        rBscore_5->setObjectName(QString::fromUtf8("rBscore_5"));
        rBscore_5->setGeometry(QRect(10, 190, 112, 23));
        rBscore_3 = new QRadioButton(groupBox_2);
        rBscore_3->setObjectName(QString::fromUtf8("rBscore_3"));
        rBscore_3->setGeometry(QRect(10, 110, 112, 23));
        rBscore_4 = new QRadioButton(groupBox_2);
        rBscore_4->setObjectName(QString::fromUtf8("rBscore_4"));
        rBscore_4->setGeometry(QRect(10, 150, 112, 23));
        rBscore_1 = new QRadioButton(groupBox_2);
        rBscore_1->setObjectName(QString::fromUtf8("rBscore_1"));
        rBscore_1->setGeometry(QRect(10, 30, 112, 23));
        rBscore_2 = new QRadioButton(groupBox_2);
        rBscore_2->setObjectName(QString::fromUtf8("rBscore_2"));
        rBscore_2->setGeometry(QRect(10, 70, 112, 23));
        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(520, 240, 171, 241));
        checkBox = new QCheckBox(groupBox_3);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(10, 30, 92, 23));
        checkBox->setTristate(true);
        checkBox_2 = new QCheckBox(groupBox_3);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(10, 70, 92, 23));
        checkBox_3 = new QCheckBox(groupBox_3);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(10, 110, 92, 23));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        toolButton->setText(QCoreApplication::translate("Widget", "\345\260\217\346\202\237\347\251\272", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "\345\271\264\347\272\247", nullptr));
        radioButton_3->setText(QCoreApplication::translate("Widget", "\344\270\211\345\271\264\347\272\247", nullptr));
        radioButton->setText(QCoreApplication::translate("Widget", "\344\270\200\345\271\264\347\272\247", nullptr));
        radioButton_2->setText(QCoreApplication::translate("Widget", "\344\272\214\345\271\264\347\272\247", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "\346\210\220\347\273\251", nullptr));
        rBscore_5->setText(QCoreApplication::translate("Widget", "<60", nullptr));
        rBscore_3->setText(QCoreApplication::translate("Widget", "70~79", nullptr));
        rBscore_4->setText(QCoreApplication::translate("Widget", "60~69", nullptr));
        rBscore_1->setText(QCoreApplication::translate("Widget", "90~100", nullptr));
        rBscore_2->setText(QCoreApplication::translate("Widget", "80~89", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Widget", "\350\200\201\345\270\210\347\232\204\344\274\230\347\202\271", nullptr));
        checkBox->setText(QCoreApplication::translate("Widget", "\345\270\205", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Widget", "\344\272\272\345\223\201\345\245\275", nullptr));
        checkBox_3->setText(QCoreApplication::translate("Widget", "\346\200\235\347\273\264\346\270\205\346\245\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
