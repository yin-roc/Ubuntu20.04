#ifndef __HFSERIAL_H__
#define __HFSERIAL_H__

#include "ros/ros.h"
#include "serial/serial.h"
#include "ros/time.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Pose2D.h"
#include "mower_ctrl/ModeSwitch.h"
#include "mower_ctrl/CtrlCommand.h"
#include "mower_ctrl/SensorValue.h"
#include "std_msgs/String.h"
#include "std_msgs/Int8.h"
#include "iostream"
#include "string"

enum class AUTOState{
    WAITING = 0,
    ALIGNMENT = 1,
    WORK = 2,
    START = 3
};

class Serialctrl{
public:
    
public:
    Serialctrl();
    ~Serialctrl();
    void TXHandler(int m_tx_num);
    void TXHandler(const std_msgs::Int8::ConstPtr & tx_num);
    void CtrlCommandHandler(const mower_ctrl::CtrlCommand& ctrl_msg);
    void RxCommand(int  num);
    void FreeCLITxCommand();
    int Return_control_rate_(){ return control_rate_;}

public:

private:
    serial::Serial * ser;
    std::string serial_port_;
    int serial_baudrate_;
    int control_rate_;
    double time = 0;
    int ctrl_count_down = 0;
    int tx_count = 0;
    int tx_num = 0;
    double CLTtime = 0;
    AUTOState state;
    std::vector<std::string> tx_command;
    std_msgs::Int8 RX_num;
    mower_ctrl::SensorValue RX_info;
    std::string carinfo;

    double last_speed = 0;
    double last_angle = 0;
    double last_rspeed = 0;
    double last_wateren = 0;
    double driving_speed = 0;
    double steering_angle = 0;
    double roll_speed = 0;
    double water_en = 0;

    ros::Publisher RX_num_publisher;
    ros::Publisher RX_info_publisher;
    ros::Publisher carinfo_publisher;
    ros::Subscriber TX_num_subscriber;
    ros::Subscriber ctrl_subscriber;

};

#endif // !__HFSERIAL_H__