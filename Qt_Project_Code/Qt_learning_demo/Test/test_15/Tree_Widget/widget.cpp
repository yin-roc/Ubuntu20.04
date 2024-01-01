#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    QStringList list;
//    list << "Name" << "Address";
//    ui->treeWidget->setHeaderLabels(list);

    // 设置Tree Widget的一级分支
    ui->treeWidget->setHeaderLabels(QStringList() << "Name" << "Address");

    QTreeWidgetItem * treeitem1 = new QTreeWidgetItem(QStringList("Bookmarks Toolbar"));
    ui->treeWidget->addTopLevelItem(treeitem1);
    QTreeWidgetItem * treeitem2 = new QTreeWidgetItem(QStringList("Bookmarks Menu"));
    ui->treeWidget->addTopLevelItem(treeitem2);

    // 添加图像
    treeitem1->setIcon(0, QIcon(":/Images/Image/folder.png"));
    treeitem2->setIcon(0, QIcon(":/Images/Image/folder.png"));

    // 给一级分支下添加二级分支
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

