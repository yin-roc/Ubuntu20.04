#include "hfserial.h"
#include "sstream"

Serialctrl::Serialctrl(){
    // 初始化节点，加上随机前缀，保证不会与同名节点发生冲突
    ros::init(argc, argv, "hf_serial", ros::init_options::AnonymousName);
    // 私有空间
    ros::NodeHandle nh("~");
    serial_port_ = nh.param<std::string>("serial_port", "/dev/ttyTHS1");  
    serial_baudrate_ = nh.param<int>("serial_baudrate", 115200);                                        
    control_rate_ = nh.param<int>("control_rate", 10);                                        
    ros::Rate rate(control_rate_); 

    tx_command = {
        "#camera,ERROR*\n", 
        "#jeston_check,OK*\n", 
        "set_mode TS\n",
        "set_mode VT\n",
        "alignment_ready\n",
        "alignment_error\n",
        "read_carinfo\n",
        "#work_start,OK*\n",
        "distance_reset\n",
        "#work_stop,OK*\n",
        "#work_warning,OK*\n",
        "#work_continue,OK*\n"
    };

    state = AUTOState::START;

    // 初始化串口
    try
    {
        ser = new serial::Serial(serial_port_, serial_baudrate_, 0.5/control_rate_);
    }
    catch(const std::exception& e)
    {
        ROS_WARN("ERROR: fail to open control serial port!");
        std::cerr << e.what() << '\n';
    }
    
    // 发送话题
    ros::NodeHandle n;
    ros::Publisher RX_num_publisher = n.advertise<std_msgs::Int8>("RX_num", 1);
    ros::Publisher RX_info_publisher = n.advertise<mower_ctrl::SensorValue>("RX_info", 1);
    ros::Publisher carinfo_publisher = n.advertise<std_msgs::String>("car_info", 1);

    // 接收话题
    ros::Subscriber TX_num_subscriber = n.subscribe("TX_num", 1, &TXHandler);
    ros::Subscriber ctrl_subscriber = n.subscribe("ctrl_command", 1, &CtrlCommandHandler);

    double last_speed = 0;
    double last_angle = 0;
    double last_rspeed = 0;
    double last_wateren = 0;
    double driving_speed = 0;
    double steering_angle = 0;
    double roll_speed = 0;
    double water_en = 0;
}

void Serialctrl::del(){
    try {
            if (ser->isOpen) {
                ser->close;
            }
        } catch (...) {
            // 忽略关闭串口时可能出现的异常
        }
}

void Serialctrl::TXHandler(int m_tx_num){
    if(tx_num != m_tx_num){
        tx_num = m_tx_num;
        tx_count = 0;
    }
    if((m_tx_num > 0) && (tx_count == 0)){
        ROS_INFO("%s", tx_command[tx_num-1].c_str());
        ser->write(tx_command[tx_num-1]);
        CLTtime = 9;
        tx_count = 0;
    }
}

void  Serialctrl::CtrlCommandHandler(const mower_ctrl::CtrlCommand::constPtr & ctrl_msg){
    if((ctrl_count_down == 0) && (state == AUTOState::WORK))
    {
        float32 driving_speed = round(msg->driving_speed, 2);
        float32 steering_angle = round(msg->steering_angle, 2);
        std::stringstream ss_ctrl_command_str;
        ss_ctrl_command_str << "move " << std::fixed << std::setprecision(2) << driving_speed << " " << steering_angle << std::endl;
        std::string ctrl_command_str = ss_ctrl_command_str.str();
        ROS_INFO("TX: %s", ctrl_command_str.c_str());
        ser->write(ctrl_command_str);
        CLTtime = 9;
        ctrl_count_down = 1;
    }
}





  