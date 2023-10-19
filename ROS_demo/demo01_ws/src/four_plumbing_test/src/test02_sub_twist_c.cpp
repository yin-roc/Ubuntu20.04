#include "ros/ros.h"
#include "turtlesim/Pose.h"

/*
    订阅小乌龟的位姿：实时获取小乌龟在窗体中的坐标并打印
    准备工作：
        1、获取话题名称 /turtle1/pose
        2、获取消息类型 turtlesim/Pose
        3、运行前启动 turtlesim_node 与 turtle_teleop_key 节点

    实现流程：
        1、包含头文件
        2、初始化ROS节点
        3、创建ROS句柄
        4、创建订阅者对象
        5、回调函数处理订阅的数据
        6、spin()
*/

void doPose(const turtlesim::PoseConstPtr& p)
{
    ROS_INFO("乌龟位姿信息：坐标(%.2f, %.2f), 朝向(%.2f), 线速度(%.2f), 角速度(%.2f)", 
                        p->x, p->y, p->theta, p->linear_velocity, p->angular_velocity);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");

    // 2、初始化ROS节点
    ros::init(argc, argv, "sub_pose");

    // 3、创建ROS句柄
    ros::NodeHandle nh;

    // 4、创建订阅者对象
    ros::Subscriber sub = nh.subscribe<turtlesim::Pose>("/turtle1/pose", 1000, doPose);
    // 5、回调函数处理订阅的数据
    // 6、spin()
    ros::spin();
    return 0;
}
