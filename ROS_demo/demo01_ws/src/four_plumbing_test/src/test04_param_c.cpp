#include "ros/ros.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "haha");

    ros::NodeHandle nh("turtlesim");// 注意：此处与常规不同

    nh.setParam("background_r", 0);
    nh.setParam("background_g", 0);
    nh.setParam("background_b", 0);

    return 0;
}
