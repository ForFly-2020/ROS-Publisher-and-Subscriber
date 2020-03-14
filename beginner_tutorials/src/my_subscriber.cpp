#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Point.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}


/**
ConstPtr คือ constant pointer 
**/
void pointCallback(const geometry_msgs::Point::ConstPtr& msg)
{

  //เราสามารถใช้ ROS_WARN เพื่อ highligh สีส้มได้ ROS_ERROR ก็สีแดง
  ROS_WARN("Point x=%.2f, y=%.2f, z=%.2f", msg->x, msg->y, msg->z);

  //เราสามารถใช้ THROTTLE เป็นตัวบอกความถี่ของการปล่อยข้อความลงบน console ได้ด้วย ช่วยให้หน้าจอไม่ดูรก
  ROS_ERROR_THROTTLE(3, "This msg run every 3 sec");
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
  ros::Subscriber pointsub = n.subscribe("point", 1000, pointCallback);

  //ros spin คือคำสั่งที่ไว้อัพเดทค่ากับทาง roscore ว่ามี topic ไหนอัพเดทบ้าง หากลืมใส่ เราจะไม่ได้รับข้อมูล topic รอบใหม่
  //ros spin มีสองแบบคือ ros spin ธรรมดา กับ ros spin once 
  //ros::spinOnce(); vs ros::spin();
  //แบบ spinOnce คืออัพเดทครั้งเดียวแล้วไปต่อบรรทัดต่อไป ros spin คืออัพเดทเรื่อยๆ จะไม่ทำบันทัดต่อไปจนกว่าจะ kill node 
  ros::spin();
  ROS_WARN("This msg should not show up until it should end.");
  return 0;
}
