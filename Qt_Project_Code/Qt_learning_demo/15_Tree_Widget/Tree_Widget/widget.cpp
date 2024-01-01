#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    QStringList list; // 创建一个对象
//    list << "Name" << "Address";
//    ui->treeWidget->setHeaderLabels(list); // 添加一级分支

    ui->treeWidget->setHeaderLabels(QStringList() << "Name" << "Address"); // 使用构造函数创建出一个匿名的对象

    QTreeWidgetItem * treeitem1 = new QTreeWidgetItem(QStringList("Bookmarks Toolbar"));
    ui->treeWidget->addTopLevelItem(treeitem1);
    QTreeWidgetItem * treeitem2 = new QTreeWidgetItem(QStringList("Bookmarks Menu"));
    ui->treeWidget->addTopLevelItem(treeitem2);

    treeitem1->setIcon(0, QIcon(":/Image/Images/folder.png")); // 列数从第0列开始
    treeitem2->setIcon(0, QIcon(":/Image/Images/folder.png"));

    QTreeWidgetItem * childitem1 = new QTreeWidgetItem(QStringList() << "QWidget" << "Page10");
    treeitem1->addChild(childitem1);

    QTreeWidgetItem * childitem2 = new QTreeWidgetItem(QStringList() << "QMainWindow" << "Page20");
    treeitem1->addChild(childitem2);

    QTreeWidgetItem * childitem3 = new QTreeWidgetItem(QStringList() << "QPushButton" << "Page30");
    treeitem2->addChild(childitem3);

    QTreeWidgetItem * childitem4 = new QTreeWidgetItem(QStringList() << "QLabel" << "Page40");
    treeitem2->addChild(childitem4);
}

Widget::~Widget()
{
    delete ui;
}

