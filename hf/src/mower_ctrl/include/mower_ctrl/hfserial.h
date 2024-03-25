#ifndef __HFSERIAL_H__
#define __HFSERIAL_H__

#include "ros/ros.h"
#include "serial/serial.h"
#include "ros/time.h"
#include "iostream"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Pose2D.h"
#include "mower_ctrl/CtrlCommand"
#include "mower_ctrl/ModeSwitch"
#include "mower_ctrl/SensorValue"
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
    Serialctrl();
    void del();
    void TXHandler(int m_tx_num);
    void CtrlCommandHandler(const mower_ctrl::CtrlCommand::constPtr & msg);

private:
    double time = 0;
    int ctrl_count_down = 0;
    int tx_count = 0;
    int tx_num = 0;
    double CLTtime = 0;
    AUTOState state;
    serial::Serial * ser;
    std::vector<std::string> tx_command;
}

#endif // !__HFSERIAL_H__
