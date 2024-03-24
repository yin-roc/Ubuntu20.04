#include "ros_node_1.h"
#include "std_msgs/String.h"
#include "sstream"

ROS_Node_1::ROS_Node_1(int argc, char ** argv) {

    setlocale(LC_ALL, "");
    ros::init(argc, argv, "ros_node_1");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<std_msgs::String>("talker", 10);

    int count = 1;
    ros::Rate r(1);
    while(ros::ok())
    {
        std::stringstream ss;
        std_msgs::String msg;
        ss << "hello world----> " << count;
        msg.data = ss.str();
        pub.publish(msg);
        count++;
        r.sleep();
        ros::spinOnce();
    }

}
