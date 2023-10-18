/*
参数服务器删除实现：
    ros::NodeHandle
        deleteParam("键")
        删除成功返回true，否则返回false
    
    ros::param
        del("键")
        删除成功返回true，否则返回false
*/

#include "ros/ros.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "delete_param");

    ros::NodeHandle nh;
    bool r1 = nh.deleteParam("nh_int");
    ROS_INFO("nh 删除结果：%d", r1);

    bool r2 = nh.deleteParam("param_int");
    ROS_INFO("nh 删除结果：%d", r2);

    return 0;
}
