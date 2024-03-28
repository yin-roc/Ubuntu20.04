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
    w.setWindowTitle("主选择界面");
    w.show();
    return a.exec();
}
