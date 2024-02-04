#include "widget.h"
#include "ui_widget.h"
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    /*
    // 获取当前系统支持的数据库驱动程序的列表
    QStringList drivers = QSqlDatabase::drivers();
    foreach (QString driver, drivers) {
        qDebug() << driver;
    }
    */

    // 创建一个与SQLite数据库的连接
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


    // 需要了解 sqlite 语句语法
    QSqlQuery sql_query;

    // 创建新表
    // 语法：create table tabname(col1 type1 [not null] [primary key],col2 type2 [not null],..)
    QString create_sql = "create table student(id int, name varchar(30), age int)";
//    sql_query.prepare(create_sql);
//    if(!sql_query.exec())
//    {
//        qDebug() << "Error, failed to create table." << sql_query.lastError();
//    }
//    else
//    {
//        qDebug() << "Table created.";
//    }

    // 创建 SQL 查询语句
    // 使用了占位符"?"，表示后续会通过绑定参数的方式为这些占位符提供具体的值
    QString insert_sql = "insert into student values(?, ?, ?)";
    // 使用 prepare 方法准备 SQL 查询语句
    sql_query.prepare(insert_sql);
    // 使用 addBindValue 方法绑定具体的值
    sql_query.addBindValue(1);
    sql_query.addBindValue("Rick");
    sql_query.addBindValue(10);
    // 执行 SQL 查询
    if(!sql_query.exec())
    {
        qDebug() << sql_query.lastError();
    }
    else
    {
        qDebug() << "Insert Student No.1!";
    }

    sql_query.prepare(insert_sql);
    sql_query.addBindValue(2);
    sql_query.addBindValue("Jack");
    sql_query.addBindValue(11);
    if(!sql_query.exec())
    {
        qDebug() << sql_query.lastError();
    }
    else
    {
        qDebug() << "Insert Student NO.2!";
    }


    // 查找
    // 从名为 student 的表中检索所有的记录（* 通配符表示所有列）
    QString select_all_sql = "select * from student";
    sql_query.prepare(select_all_sql);
    if(!sql_query.exec())
    {
        qDebug() << sql_query.lastError();
    }
    else
    {
        // 通过 next 方法逐行遍历查询结果
        while(sql_query.next())
        {
            int id = sql_query.value(0).toInt();
            QString name = sql_query.value(1).toString();
            int age = sql_query.value(2).toInt();
            qDebug() << "id:" << id << "   name:" << name << "    age:" << age;
        }
    }
}

Widget::~Widget()
{
    delete ui;
}

