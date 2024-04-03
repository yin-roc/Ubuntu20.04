#include "ros/ros.h"
#include <serial/serial.h>
 
//串口类
serial::Serial ser;
 
#define sBUFFERSIZE 1000 // send buffer size串口发送缓存长度
#define rBUFFERSIZE 1000 // receive buffer size 串口接收缓存长度
unsigned char s_buffer[sBUFFERSIZE]; //发送缓存
unsigned char r_buffer[rBUFFERSIZE]; //接收缓存
 
//下发数据函数
void data_redownload() 
{
  ser.write(s_buffer, sBUFFERSIZE);
}
 
int main(int argc, char **argv) {
  ros::init(argc, argv, "serial_node");
  ros::NodeHandle nh;
 
  //打开串口
  try {
    ser.setPort("/dev/ttyUSB0");
    ser.setBaudrate(115200);
    serial::Timeout to = serial::Timeout::simpleTimeout(1000);
    ser.setTimeout(to);
    ser.open();
  } catch (serial::IOException &e) {
    ROS_ERROR_STREAM("Unable to open port ");
    return -1;
  }
 
  if (ser.isOpen()) {
    ROS_INFO_STREAM("Serial Port initialized");
  } else {
    return -1;
  }
 
  // 10hz频率执行
  ros::Rate loop_rate(10);
  while (ros::ok()) {
    ros::spinOnce();
    if (ser.available()) {
      size_t bytes_read;
      bytes_read = ser.read(r_buffer, ser.available());
    //接收到数据后处理
    }
    loop_rate.sleep();
  }
}