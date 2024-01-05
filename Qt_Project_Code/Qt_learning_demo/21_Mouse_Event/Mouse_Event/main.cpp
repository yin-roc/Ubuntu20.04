#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();


    return a.exec(); // 捕获事件是否产生、触发，可在其中设置时间过滤、时间分发和事件处理
}
