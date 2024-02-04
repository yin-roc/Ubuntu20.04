#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 获取当前系统支持的数据库驱动程序的列表
    QStringList drivers = QSqlDatabase::drivers();

    foreach(QString driver, drivers) {
        qDebug() << driver;
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("dataset.db");
    if(!db.open())
    {
        qDebug() << "Error: Failed to connect to the database." << db.lastError();
    }
    else
    {
        qDebug() << "Connect database successful!";
    }

}

Widget::~Widget()
{
    delete ui;
}

