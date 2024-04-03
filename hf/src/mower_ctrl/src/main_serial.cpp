#include "ros/ros.h"
#include "mower_ctrl/hfserial.h"

int main(int argc, char *argv[])
{
    // 初始化节点，加上随机前缀，保证不会与同名节点发生冲突
    ros::init(argc, argv, "hf_serial", ros::init_options::AnonymousName);

    Serialctrl ser1;
    int serial_rate = ser1.Return_control_rate_();
    ros::Rate rate(serial_rate);

    return 0;
}
