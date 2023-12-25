#include "mainwindow.h"

#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

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


    // QToolBar 工具栏
    QToolBar * toolbar = new QToolBar(this);
    addToolBar(Qt::TopToolBarArea, toolbar); // 创建完，工具栏首先出现在顶层，但可变换位置，比如LeftToolBarArea
    toolbar->addAction("测试");
    toolbar->addSeparator();


    // QStatusBar 状态栏
    QStatusBar *stbar = new QStatusBar(this);
    setStatusBar(stbar);
    QLabel * label = new QLabel(this);
    label->setText("状态栏");
    stbar->addWidget(label);


    // QDockWidget 浮动窗口
    //    QDockWidget *dockwidget = new QDockWidget(this);
    QDockWidget *dockwidget = new QDockWidget("小窗口",this); // 给停靠窗口加个名称

    // 放在中心部件的左(Left)/右(Right)/上(Top)/下(Buttom)位置，但是若没有中心部件则无论如何规划DockWidget的位置，都无法体现出方位
    addDockWidget(Qt::LeftDockWidgetArea, dockwidget);


    // Central Widget 中心组件
    QTextEdit * edit = new QTextEdit(this);
    setCentralWidget(edit);
}

MainWindow::~MainWindow()
{
}

