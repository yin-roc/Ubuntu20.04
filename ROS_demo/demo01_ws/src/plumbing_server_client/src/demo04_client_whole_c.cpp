/*
需求：
    编写两个节点实现服务通信，客户端节点需要提交两个整数到服务器
    服务器需要解析客户端提交的数据，相加后，将结果响应回客户端
    客户端再解析

    服务端实现：
        1、包含头文件
        2、初始化ros节点
        3、创建节点句柄
        4、创建服务端对象
        5、请求服务，接收响应
*/

#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "");

    // 调用时动态传参，如果通过launch的args传参，需要传递的参数个数 +3
    if(argc != 3)
    // if(argc != 5) // launch传参（0-文件路径 1-传入的参数 2-传入的参数 3-节点名称 4-日志路径）
    {
        ROS_ERROR("请提交两个整数：");
        return 1;
    }

    // 2、初始化ros节点
    ros::init(argc, argv, "AddInts_Client");
    // 3、创建节点句柄
    ros::NodeHandle nh;
    // 4、创建服务端对象
    ros::ServiceClient client = nh.serviceClient<plumbing_server_client::AddInts>("AddInts");

    //等待服务启动成功
    // 方式1
    ros::service::waitForService("AddInts");

    // 方式2
    // client.waitForExistence();
    // 5、请求服务，接收响应
    plumbing_server_client::AddInts ai;
    ai.request.num1 = atoi(argv[1]);
    ai.request.num2 = atoi(argv[2]);

    // 6、发送请求，返回bool值，标记是否成功
    bool flag = client.call(ai);

    // 7、处理响应
    if(flag)
    {
        ROS_INFO("请求正常，响应结果：%d", ai.response.sum);
    }
    else
    {
        ROS_ERROR("请求处理失败......");
        return 1;
    }

    return 0;
}
