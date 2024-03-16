#!/bin/zsh

# 启动 roscore 节点
source /opt/ros/noetic/setup.zsh
gnome-terminal -- zsh -c "roscore"
gnome-terminal -- zsh -c "cd /home/yin-roc/1_Code/Ubuntu20.04/ROS_demo/demo01_ws; source devel/setup.zsh; rosrun plumbing_pub_sub demo01_pub_c"
gnome-terminal -- zsh -c "sleep 2; cd /home/yin-roc/1_Code/Ubuntu20.04/ROS_demo/demo01_ws; source devel/setup.zsh; rosrun plumbing_pub_sub demo02_sub_c"


