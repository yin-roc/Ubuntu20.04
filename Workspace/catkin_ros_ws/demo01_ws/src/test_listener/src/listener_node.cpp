#include "ros/ros.h"
#include "std_msgs/String.h"

void CallBack(std_msgs::String msg){
    ROS_INFO("订阅者订阅到的数据：%s", msg.data.c_str());
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "listener_node");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe<std_msgs::String>("/talker", 10, &CallBack); 
    ros::spin();

    return 0;
}
