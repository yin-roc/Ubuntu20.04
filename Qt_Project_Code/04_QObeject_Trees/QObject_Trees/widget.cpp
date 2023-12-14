#include "widget.h"
#include <QLabel>
#include <QPushButton>
#include "qmyclass.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
//    QLabel * label = new QLabel;
    QLabel * label = new QLabel(this); // 3.修改代码，代替注释1和2
    label->setText("I love you, Rock!"); // 标签内容填写
    label->move(150, 100); // 6.设置标签在框内的出现位置

    QPushButton * button = new QPushButton(this);
    button->setText("Close");
    button->move(150, 180);

//    label->show();  // 1.展示新建标签
//    label->setParent(this); // 2.设置标签的从属关系，防止各自成户
//    resize(400, 300); // 4.预设了大小，但是鼠标可以修改大小
    setFixedSize(400, 300); // 5.锁定大小
    setWindowTitle("My first NO UI"); // 7.修改框体名称

    QMyClass * myclass = new QMyClass(this);

}

Widget::~Widget()
{
}
