#include "ros/ros.h"
#include "std_msgs/String.h"
/*
    需求:演示不同类型的话题名称设置
        设置话题名称与命名空间
*/ 
int main(int argc, char  *argv[])
{
    ros::init(argc,argv,"hello");
    // ros::NodeHandle nh;

    //核心:设置不同类型的话题
    //1.全局 --- 话题名称需要以斜杠开头。这种情况下和节点(命名空间以及名称)没有关系
    // ros::Publisher pub = nh.advertise<std_msgs::String>("/chatter",1000);
    // ros::Publisher pub = nh.advertise<std_msgs::String>("/yyy/chatter",1000);

    //2.相对 ---非斜杠开头
    // ros::Publisher pub = nh.advertise<std_msgs::String>("yyy/chatter",1000);

    //3.私有 ---需要创建特定NodeHandle
    //rosnode  /xxx/hello/chatter
    //rostopic /xxx/hello/yyy/chatter
    ros::NodeHandle nh("~");
    //注意:如果私有的nh创建的话题以 / 开头(全局话题)，生成的话题是全局的非私有
    //全局话题优先级更高
    ros::Publisher pub = nh.advertise<std_msgs::String>("yyy/chatter",1000);

    while(ros::ok())
    {

    }

    return 0;
}
