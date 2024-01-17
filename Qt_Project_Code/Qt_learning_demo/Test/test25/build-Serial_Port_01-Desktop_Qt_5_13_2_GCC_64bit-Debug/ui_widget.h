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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *comboBox_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *comboBox_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QComboBox *comboBox_5;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_9;
    QLabel *label_11;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_10;
    QLabel *label_12;
    QWidget *widget4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_8;
    QTextEdit *textEdit_2;
    QWidget *widget5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_7;
    QTextEdit *textEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 20, 221, 241));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        comboBox_2 = new QComboBox(widget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        horizontalLayout_2->addWidget(comboBox_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        comboBox_3 = new QComboBox(widget);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));

        horizontalLayout_3->addWidget(comboBox_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        comboBox_4 = new QComboBox(widget);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));

        horizontalLayout_4->addWidget(comboBox_4);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        comboBox_5 = new QComboBox(widget);
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));

        horizontalLayout_5->addWidget(comboBox_5);


        verticalLayout->addLayout(horizontalLayout_5);

        widget1 = new QWidget(Widget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(40, 300, 63, 118));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_2->addWidget(label_6);

        checkBox = new QCheckBox(widget1);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout_2->addWidget(checkBox);

        checkBox_2 = new QCheckBox(widget1);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        verticalLayout_2->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(widget1);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        verticalLayout_2->addWidget(checkBox_3);

        widget2 = new QWidget(Widget);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(350, 510, 151, 25));
        horizontalLayout_6 = new QHBoxLayout(widget2);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(widget2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_6->addWidget(label_9);

        label_11 = new QLabel(widget2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_6->addWidget(label_11);

        widget3 = new QWidget(Widget);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        widget3->setGeometry(QRect(350, 550, 151, 25));
        horizontalLayout_7 = new QHBoxLayout(widget3);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(widget3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_7->addWidget(label_10);

        label_12 = new QLabel(widget3);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_7->addWidget(label_12);

        widget4 = new QWidget(Widget);
        widget4->setObjectName(QString::fromUtf8("widget4"));
        widget4->setGeometry(QRect(350, 260, 258, 223));
        verticalLayout_3 = new QVBoxLayout(widget4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(widget4);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_3->addWidget(label_8);

        textEdit_2 = new QTextEdit(widget4);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));

        verticalLayout_3->addWidget(textEdit_2);

        widget5 = new QWidget(Widget);
        widget5->setObjectName(QString::fromUtf8("widget5"));
        widget5->setGeometry(QRect(350, 20, 258, 223));
        verticalLayout_4 = new QVBoxLayout(widget5);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(widget5);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_4->addWidget(label_7);

        textEdit = new QTextEdit(widget5);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_4->addWidget(textEdit);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\344\270\262\345\217\243", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\346\263\242\347\211\271\347\216\207", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("Widget", "2400", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("Widget", "4800", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("Widget", "9600", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("Widget", "19200", nullptr));
        comboBox_2->setItemText(4, QCoreApplication::translate("Widget", "38400", nullptr));
        comboBox_2->setItemText(5, QCoreApplication::translate("Widget", "115200", nullptr));
        comboBox_2->setItemText(6, QCoreApplication::translate("Widget", "128000", nullptr));
        comboBox_2->setItemText(7, QCoreApplication::translate("Widget", "256000", nullptr));

        label_3->setText(QCoreApplication::translate("Widget", "\346\225\260\346\215\256\344\275\215", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("Widget", "5", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("Widget", "6", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("Widget", "7", nullptr));
        comboBox_3->setItemText(3, QCoreApplication::translate("Widget", "8", nullptr));

        label_4->setText(QCoreApplication::translate("Widget", "\346\240\241\351\252\214\344\275\215", nullptr));
        comboBox_4->setItemText(0, QCoreApplication::translate("Widget", "Even", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("Widget", "Odd", nullptr));
        comboBox_4->setItemText(2, QCoreApplication::translate("Widget", "NoParity", nullptr));

        label_5->setText(QCoreApplication::translate("Widget", "\345\201\234\346\255\242\344\275\215", nullptr));
        comboBox_5->setItemText(0, QCoreApplication::translate("Widget", "1", nullptr));
        comboBox_5->setItemText(1, QCoreApplication::translate("Widget", "1.5", nullptr));
        comboBox_5->setItemText(2, QCoreApplication::translate("Widget", "2", nullptr));

        label_6->setText(QCoreApplication::translate("Widget", "\346\216\245\346\224\266\350\256\276\347\275\256", nullptr));
        checkBox->setText(QCoreApplication::translate("Widget", "Hex", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Widget", "ASCII", nullptr));
        checkBox_3->setText(QCoreApplication::translate("Widget", "\346\232\202\345\201\234", nullptr));
        label_9->setText(QCoreApplication::translate("Widget", "\346\216\245\346\224\266\345\255\227\350\212\202\357\274\232", nullptr));
        label_11->setText(QCoreApplication::translate("Widget", "0", nullptr));
        label_10->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201\345\255\227\350\212\202\357\274\232", nullptr));
        label_12->setText(QCoreApplication::translate("Widget", "0", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201\346\225\260\346\215\256", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "\346\216\245\346\224\266\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
