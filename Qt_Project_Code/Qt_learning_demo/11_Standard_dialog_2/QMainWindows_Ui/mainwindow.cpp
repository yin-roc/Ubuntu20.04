#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDialog>
#include <QPushButton>
#include <QColorDialog> // 颜色对话框
#include <QDebug>
#include <QFileDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QProgressDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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


void MainWindow::on_pushButton_clicked()
{
//    QColorDialog dialog(this);

//    换一种方式来实现
    QColor color = QColorDialog::getColor(Qt::red, this);
    qDebug() << "color: " << color;
}

void MainWindow::on_pushButton_2_clicked()
{
//    QString filename = QFileDialog::getOpenFileName(this, "Open File", "/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/10_Standard_dialog_1/QMainWindows_Ui");
    //                                       参数1：父对象；参数2：对话框标题；参数3：具体地址；
    QString filename = QFileDialog::getOpenFileName(this, "Open File", "/home/yin-roc/1_Code/Ubuntu20.04/Qt_Project_Code/10_Standard_dialog_1/QMainWindows_Ui", "图片文件(*.png *.jpg)");
//                                                                                                                                                                参数4：要检索的文件名称+文件格式
    qDebug() << "filename: " << filename;
}

void MainWindow::on_pushButton_3_clicked()
{
    bool ok;

    QFont font = QFontDialog::getFont(&ok, this);
    if(ok)
    {
        ui->pushButton_3->setFont(font);
    }
    else
    {
        qDebug() << "没有选择任何字体" << endl;
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    bool ok;
    QString string = QInputDialog::getText(this, "输入字符串对话框", "请输入用户名", QLineEdit::Normal, "Hello world", &ok);
//    QLineEdit::Password 在输入密码时，显示的字符是平台依赖的密码掩码字符，而不是用户实际输入的字符
    if(ok)
        qDebug() << "string: " << string;

    int value = QInputDialog::getInt(this, "输入整数对话框", "请输入0～100的整数", 0, 0, 100, 1, &ok);
    if(ok)
        qDebug() << "Value = " << value;
}

void MainWindow::on_pushButton_5_clicked()
{
    // 问题对话框
    int ret1 = QMessageBox::question(this, "问题对话框", "你是否使用Qt", QMessageBox::Yes, QMessageBox::No);
    if(ret1 == QMessageBox::Yes)
        qDebug() << "Great";

    // 提示对话框
    QMessageBox::information(this, "提示对话框", "你最好使用Qt", QMessageBox::Ok);

    // 警告对话框
    QMessageBox::warning(this, "警告对话框", "请停止使用其他GUI", QMessageBox::Ok);

    // 错误对话框
    QMessageBox::critical(this, "错误对话框", "重大错误", QMessageBox::Retry);

    // 关于对话框
    QMessageBox::about(this, "关于对话框", "我爱Rick");

}

void MainWindow::on_pushButton_6_clicked()
{
//    QProgressDialog * prodlg = new QProgressDialog(); // 指针存放在栈区，只要主窗口不关闭，随时可用
    QProgressDialog prodlg("复制内容", "取消", 0, 1000000, this); // 直接创建类对象，对象存放在堆，函数结束就会释放内存
    prodlg.setWindowTitle("复制文件");
    prodlg.setWindowModality(Qt::WindowModal); // 设置该进度窗口为模态，中途不可打断
    prodlg.show();

    for(int i = 0; i < 1000000; i++)
    {
        prodlg.setValue(i);

        QCoreApplication::processEvents();

        if(prodlg.wasCanceled())
            break;
    }
    prodlg.setValue(1000000); // 范围是0～49999，可能显示不了50000
    qDebug() << "拷贝完成";

}

void MainWindow::on_pushButton_7_clicked()
{

}

void MainWindow::on_pushButton_8_clicked()
{

}
