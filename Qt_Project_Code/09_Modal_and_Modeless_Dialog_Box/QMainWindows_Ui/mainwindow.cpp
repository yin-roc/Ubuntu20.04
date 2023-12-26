#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDialog * dialog = new QDialog(this);
    dialog->resize(200, 100);
//    dialog->show();     // 非模态对话框

//    dialog->exec(); // exec是一个阻塞函数，关掉该窗口才会出现主窗口 // 模态对话框 方式1

    dialog->setModal(true); // 模态对话框 方式2
    dialog->show();

//    问题：new开辟的不需要显式的使用delete，因为窗口MainWindow一关闭就会自动调用相应的内存释放函数
//    但极端情况下，出现模态的模态的......，内存总会占满，此时只能等到最后一个窗口关闭才能释放内存，因此需要改进措施
    dialog->setAttribute(Qt::WA_DeleteOnClose); // 只要模态窗口被关闭，就是释放内存


//    可以用但也比较麻烦，换台电脑可能就实现不了，需要添加相应的资源文件
//    ui->action_N->setIcon(QIcon("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/08_QMainWindows_Ui/QMainWindows_Ui/Images/new.png"));
//    ui->action_O->setIcon(QIcon("/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/08_QMainWindows_Ui/QMainWindows_Ui/Images/open.png"));

    //加载资源路径
    // 添加Qt资源文件是使用格式    "：+前缀+文件名"
    ui->action_N->setIcon(QIcon(":/Image/Images/new.png"));
    ui->action_O->setIcon(QIcon(":/Image/Images/open.png"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

