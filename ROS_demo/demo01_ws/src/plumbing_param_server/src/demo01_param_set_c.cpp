#include "ros/ros.h"
#include <string>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "set_update_param");

    std::vector<std::string> stus;
    stus.push_back("zhangsan");
    stus.push_back("李四");
    stus.push_back("王五");
    stus.push_back("孙大脑袋");

    std::map<std::string, std::string> friends;
    friends["guo"] = "huang";
    friends["yuang"] = "xiao";

    ros::NodeHandle nh;
    nh.setParam("nh_int", 10);
    nh.setParam("nh_double", 3.14);
    nh.setParam("nh_bool", true);
    nh.setParam("nh_string", "hello Nodehandle");
    nh.setParam("nh_vector", stus); // lists
    nh.setParam("nh_map", friends); // 字典

    // 修改
    nh.setParam("nh_int", 10000);

    // 调用ros::param来修改参数的值
    ros::param::set("param_int", 20);
    ros::param::set("param_double", 3.14);
    ros::param::set("param_string", "Hello Param");
    ros::param::set("param_bool", false);
    ros::param::set("param_vector", stus);
    ros::param::set("param_map", friends);

    // 修改
    ros::param::set("param_int", 20000);

    return 0;
}
