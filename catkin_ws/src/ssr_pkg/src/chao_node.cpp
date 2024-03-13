#include <ros/ros.h>
#include <iostream>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "Chao_node");

    std::cout << "我的枪去而不反！\n";
    
    while(ros::ok())
    {
        std::cout << "别投，我还能秀！\n";
    }
    return 0;
}
