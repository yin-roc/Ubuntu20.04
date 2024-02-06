#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

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

    QSqlQuery sql_query;


//    QString create_sql = "create table student(id int, name varchar(30), age int)";
//    sql_query.prepare(create_sql); // 将传递给它的 SQL 查询语句进行预编译
//    if(!sql_query.exec())
//    {
//        qDebug() << "Error, Failed to create table." << sql_query.lastError();
//    }
//    else
//    {
//        qDebug() << "Table created";
//    }


//    // 插入
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


    // Qt 窗口中显示
    model = new QSqlTableModel(this); //
    ui->tableView->setModel(model); // 将对象与 QTableView 控件关联，TableView 将显示 model 中的数据，并在表数据发生变化时自动更新。
    model->setTable("student"); // model 连接到名为 student 的数据库
    model->select(); // 从数据库中检索数据并将其加载到 QSqlTableModel 中

    // 设置表头信息
    model->setHeaderData(0, Qt::Horizontal, "学号");
    model->setHeaderData(1, Qt::Horizontal, "姓名");
    model->setHeaderData(2, Qt::Horizontal, "年龄");

    // 设置编辑策略
    // 所有的更改将被缓存在模型中，直到调用 submitAll() 或 revertAll() 为止
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

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
