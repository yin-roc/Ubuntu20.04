#!/bin/zsh

# 清除 ROS_MASTER_URI 环境变量
#unset ROS_MASTER_URI

# 启动 roscore
echo "Starting roscore..."
#roscore &

# 等待一段时间以确保 roscore 启动完全
sleep 5

# 启动 turtlesim 节点
echo "Starting turtlesim node..."
rosrun turtlesim turtlesim_node &

# 等待一段时间以确保 turtlesim 启动完全
sleep 5

# 切换到指定目录并运行 demo01_Dir_Control，确保它在后台运行
echo "Starting demo01_Dir_Control..."
cd /home/yin-roc/1_Code/Ubuntu20.04/Workspace/qt_ros_ws/catkin_demo01_ws/devel/lib/demo01_Dir_Control
./demo01_Dir_Control >/dev/null 2>&1 &

# 提示所有节点都已启动
echo "All nodes started."

