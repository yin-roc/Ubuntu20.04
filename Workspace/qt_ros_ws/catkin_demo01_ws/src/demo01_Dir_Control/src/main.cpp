#include "mainwindow.h"
#include <QApplication>
#include "ros_node_1.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "your_node_name");

    // Qt
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("小车控制界面");
    w.resize(272, 164);
    w.show();
    return a.exec();
}
