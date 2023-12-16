#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // QMenuBar
    resize(700, 600); // 限定刚出现窗口大小
    QMenuBar * menubar = new QMenuBar(this);
    setMenuBar(menubar);

    QMenu * filename = menubar->addMenu("文件(&F)"); // 添加菜单栏选项
    QMenu * editmenu = menubar->addMenu("编辑(&E)");
    QMenu * buildname = menubar->addMenu("构建(&B)");

    // 下拉菜单添加可选项：新建文件、打开文件、关闭文件
    // 使用快捷键alt + 具体快捷键 打开
    filename->addAction("新建文件(&N)");
    filename->addSeparator(); // 分割符，界面看起来更美观
    filename->addAction("打开文件(&O)");
    filename->addSeparator(); // 分割符，界面看起来更美观
    filename->addAction("关闭文件(&C)");

    editmenu->addAction("恢复(&U)");
    buildname->addAction("构建所有项目(&R)");


    // QToolBar
    QToolBar * toolbar = new QToolBar(this);
    addToolBar(Qt::TopToolBarArea, toolbar); // 创建完，工具栏首先出现在顶层，但可变换位置，比如LeftToolBarArea
    toolbar->addAction("测试");
    toolbar->addSeparator();
}

MainWindow::~MainWindow()
{
}

