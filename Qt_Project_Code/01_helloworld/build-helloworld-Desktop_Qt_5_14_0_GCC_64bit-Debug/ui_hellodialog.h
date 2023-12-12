/********************************************************************************
** Form generated from reading UI file 'hellodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLODIALOG_H
#define UI_HELLODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_helloDialog
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *helloDialog)
    {
        if (helloDialog->objectName().isEmpty())
            helloDialog->setObjectName(QString::fromUtf8("helloDialog"));
        helloDialog->resize(800, 600);
        centralwidget = new QWidget(helloDialog);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(300, 90, 131, 81));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label->setFont(font);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(290, 230, 89, 25));
        helloDialog->setCentralWidget(centralwidget);
        menubar = new QMenuBar(helloDialog);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 28));
        helloDialog->setMenuBar(menubar);
        statusbar = new QStatusBar(helloDialog);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        helloDialog->setStatusBar(statusbar);

        retranslateUi(helloDialog);

        QMetaObject::connectSlotsByName(helloDialog);
    } // setupUi

    void retranslateUi(QMainWindow *helloDialog)
    {
        helloDialog->setWindowTitle(QCoreApplication::translate("helloDialog", "helloDialog", nullptr));
        label->setText(QCoreApplication::translate("helloDialog", "I Love you", nullptr));
        pushButton->setText(QCoreApplication::translate("helloDialog", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class helloDialog: public Ui_helloDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLODIALOG_H
