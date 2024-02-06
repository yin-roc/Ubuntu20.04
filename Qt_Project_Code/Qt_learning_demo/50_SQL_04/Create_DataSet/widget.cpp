#include "widget.h"
#include "ui_widget.h"
#include <QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    /*
    // 获取当前系统支持的数据库驱动程序的列表
    QStringList drivers = QSqlDatabase::drivers();

    foreach(QString driver, drivers) {
        qDebug() << driver;
    }
    */

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
    // create table tabname(col1 type1 [not null] [primary key],col2 type2 [not null],..)
    //              表格名称  列   类型
    QString create_sql = "create table student(id int, name varchar(30), age int)";
//    sql_query.prepare(create_sql); // 将传递给它的 SQL 查询语句进行预编译
//    if(!sql_query.exec())
//    {
//        qDebug() << "Error, Failed to create table." << sql_query.lastError();
//    }
//    else
//    {
//        qDebug() << "Table created";
//    }


//    // 插入：insert into table1(field1,field2) values(value1,value2)
//    // 报错：QSqlError("", "Parameter count mismatch", "")；
//    // 可能是因为没有建立表格，上面注释语句取消注释即可。

//    // 创建 SQL 查询语句
//    // 使用了占位符"?"，表示后续会通过绑定参数的方式为这些占位符提供具体的值
//    QString insert_sql = "insert into student values(?, ?, ?)";
//    // 使用 prepare 方法准备 SQL 查询语句
//    sql_query.prepare(insert_sql);
//    // 使用 addBindValue 方法绑定具体的值
//    sql_query.addBindValue(1);
//    sql_query.addBindValue("Rick");
//    sql_query.addBindValue(10);
//    // 执行 SQL 查询
//    if(!sql_query.exec())
//    {
//        qDebug() << sql_query.lastError();
//    }
//    else
//    {
//        qDebug() << "Insert Student NO.1!";
//    }

//    sql_query.prepare(insert_sql);
//    sql_query.addBindValue(2);
//    sql_query.addBindValue("Jack");
//    sql_query.addBindValue(11);
//    if(!sql_query.exec())
//    {
//        qDebug() << sql_query.lastError();
//    }
//    else
//    {
//        qDebug() << "Insert Student NO.2!";
//    }


//    // 查找：select * from table1
//    // 从名为 student 的表中检索所有的记录（* 通配符表示所有列）
//    QString select_all_sql = "select * from student";
//    sql_query.prepare(select_all_sql);
//    if(!sql_query.exec())
//    {
//        qDebug() << sql_query.lastError();
//    }
//    else
//    {
//        // 通过 next 方法逐行遍历查询结果
//        while(sql_query.next())
//        {
//            int id = sql_query.value(0).toInt();
//            QString name = sql_query.value(1).toString();
//            int age = sql_query.value(2).toInt();
//            qDebug() << "id:" << id << "   name:" << name << "    age:" << age;
//        }
//    }


//    // 更新：update table1 set field1=value1 where 范围
//    QString update_sql = "update student set name = :nm where id = :n";
//    sql_query.prepare(update_sql);
//    sql_query.bindValue(":nm", "Michael");
//    sql_query.bindValue(":n", "1");
//    if(!sql_query.exec())
//    {
//        qDebug() << sql_query.lastError();
//    }
//    else
//    {
//        qDebug() << "Updated";
//    }
//    // 显示
//    select_all_sql = "select * from student";
//    sql_query.prepare(select_all_sql);
//    if(!sql_query.exec())
//    {
//        qDebug() << sql_query.lastError();
//    }
//    else
//    {
//        // 通过 next 方法逐行遍历查询结果
//        while(sql_query.next())
//        {
//            int id = sql_query.value(0).toInt();
//            QString name = sql_query.value(1).toString();
//            int age = sql_query.value(2).toInt();
//            qDebug() << "id:" << id << "   name:" << name << "    age:" << age;
//        }
//    }


//    // 删除：delete from table1 where 范围
//    QString delete_sql = "delete from student where id = ?";
//    sql_query.prepare(delete_sql);
//    sql_query.addBindValue(1);
//    if(!sql_query.exec())
//    {
//        qDebug() << sql_query.lastError();
//    }
//    else
//    {
//        qDebug() << "Deleted";
//    }
//    // 显示
//    select_all_sql = "select * from student";
//    sql_query.prepare(select_all_sql);
//    if(!sql_query.exec())
//    {
//        qDebug() << sql_query.lastError();
//    }
//    else
//    {
//        // 通过 next 方法逐行遍历查询结果
//        while(sql_query.next())
//        {
//            int id = sql_query.value(0).toInt();
//            QString name = sql_query.value(1).toString();
//            int age = sql_query.value(2).toInt();
//            qDebug() << "id:" << id << "   name:" << name << "    age:" << age;
//        }
//    }


//    // 删除: delete from table1
//    QString clear_sql = "delete from student";
//    sql_query.prepare(clear_sql);
//    if(!sql_query.exec())
//    {
//        qDebug() << sql_query.lastError();
//    }
//    else
//    {
//        qDebug() << "Table cleared";
//    }

    // Qt 窗口中显示
    model = new QSqlTableModel(this);
    ui->tableView->setModel(model);
    model->setTable("student");
    model->select();

    // 设置表头信息
    model->setHeaderData(0, Qt::Horizontal, "学号");
    model->setHeaderData(1, Qt::Horizontal, "姓名");
    model->setHeaderData(2, Qt::Horizontal, "年龄");

    model->setEditStrategy(QSqlTableModel::OnManualSubmit); // 所有的更改将被缓存在模型中，直到调用 submitAll() 或 revertAll() 为止
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    model->submitAll(); // 提交
}

void Widget::on_pushButton_2_clicked()
{
    model->revertAll(); // 撤销
    model->submitAll();
}

void Widget::on_pushButton_3_clicked()
{
    QString name = ui->lineEdit->text();
    QString nm = QString("name = '%1'").arg(name);
    // 使用 QString 的格式化功能，构建了一个字符串 nm。
    // 该字符串包含了一个 SQL 查询条件，形式为 "name = '用户输入的文本'"。
    // 其中 %1 是一个占位符，通过 arg(name) 将前面获取的用户输入文本 name 替换到占位符位置，从而形成最终的查询条件字符串

    model->setFilter(nm); // 将上述构建的查询条件字符串 nm 应用于 QSqlTableModel 的过滤器（filter）属性
    //    name = 'Jack' （三列对应的是id、name、edge（即使使用 setHeaderData 修改了表头信息））
    //    model->setFilter("name = 'Jack'"); // 限定死了，只能查找 Jack

    model->select(); // 执行数据库查询操作
}
