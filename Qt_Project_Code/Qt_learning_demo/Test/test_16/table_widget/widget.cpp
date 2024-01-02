#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 设置行数与列数
    ui->tableWidget->setRowCount(3);
    ui->tableWidget->setColumnCount(3);

    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Name" << "Sex" << "Age");

//    QTableWidgetItem * item1 = new QTableWidgetItem(QString("Ricker"));
//    ui->tableWidget->setItem(0, 0, item1);

//    ui->tableWidget->setItem(0, 0, new QTableWidgetItem("Jack"));

    QStringList NameList;
    NameList << "Rick" << "Jack" << "Nichael";

    QStringList SexList;
    SexList << "Male" << "Male" << "Male";

    for(int row = 0; row < 3; row++)
    {
        int col = 0;
        ui->tableWidget->setItem(row, col++, new QTableWidgetItem(NameList[row]));
        ui->tableWidget->setItem(row, col++, new QTableWidgetItem(SexList[row]));
        ui->tableWidget->setItem(row, col++, new QTableWidgetItem(QString::number(20))); // int --> string，单纯int类型在里面是

    }
}

Widget::~Widget()
{
    delete ui;
}

