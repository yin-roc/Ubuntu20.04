#include "ros/ros.h"
#include "std_msgs/String.h"

/*
    需求：演示不同类型的话题名称设置：设置话题名称与命名空间
        启动节点时，传递一个命名空间： __ns:=xxx ；
        节点启动后，使用 rostopic 查看话题信息 
    
*/
int main(int argc, char *argv[])
{
    ros::init(argc, argv, "hello");
    // ros::NodeHandle nh;  // 全局和相对需要取消注释


    // 1、全局 ----- 话题名称设置需要以 / 开头（也可以自己设置自己的命名空间），这种情况下和节点（命名空间以及名称）没有关系
    // ros::Publisher pub = nh.advertise<std_msgs::String>("/chatter", 1000);
    // ros::Publisher pub = nh.advertise<std_msgs::String>("/yyy/chatter", 1000);
    // rostopic list: /chatter
    // risnode list: /xxx/hello

    // ros::Publisher pub = nh.advertise<std_msgs::String>("/yyy/chatter", 1000);
    // rostopic list: /yyy/chatter
    // risnode list: /xxx/hello


    // 2、相对 ---- 非 / 开头的名称，参考命名空间（与节点名称平级）来确定话题名称
    // ros::Publisher pub = nh.advertise<std_msgs::String>("chatter", 1000);
    // rostopic list: /xxx/chatter
    // risnode list: /xxx/hello

    // ros::Publisher pub = nh.advertise<std_msgs::String>("yyy/chatter", 1000);
    // rostopic list: /xxx/yyy/chatter
    // risnode list: /xxx/hello


    // 3、私有 ----- 需要创建特定 NodeHandle
    ros::NodeHandle nh("~");
    // ros::Publisher pub = nh.advertise<std_msgs::String>("chatter", 1000); 
    // rostopic list: /xxx/hello/chatter
    // risnode list: /xxx/hello

    // ros::Publisher pub = nh.advertise<std_msgs::String>("chatter/money", 1000); 
    // rostopic list: /xxx/hello/chatter/money
    // risnode list: /xxx/hello

    ros::Publisher pub = nh.advertise<std_msgs::String>("/chatter/money", 1000); 


    while(ros::ok())
    {}

    return 0;
}
