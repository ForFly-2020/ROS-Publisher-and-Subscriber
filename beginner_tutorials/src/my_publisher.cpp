#include "ros/ros.h" //อันนี้คือ header มาตรฐานของ ros ทุกไฟล์ main ต้องมี

//อันนี้คือ msg ที่เคยพูดถึง ลองมาดูกันว่าไฟล์นี้มีอะไรบ้าง
//จะเห็นว่ามีตัวแปร String ชื่อ data
//ทีนี้หากเราต้องการเพิ่ม topic ที่ส่ง msg โดยใช้ structure อื่น
//ตัวอย่างเช่น ส่งค่า position ลองมาดูว่ามี structure ไหนน่าใช้บ้าง
#include "std_msgs/String.h"
#include "geometry_msgs/Point.h"
#include <sstream>


//สร้างตัวแปร
geometry_msgs::Point testPoint;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;

  //สร้างตัวส่งข้อมูลขึ้น topic [ชื่อ] = nodehandle....<ชื่อตัวmsg>("ชื่อ topic", จำนวนที่คิวข้อมูลไว้)
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  ros::Publisher point_pub = n.advertise<geometry_msgs::Point>("point", 3);

  ros::Rate loop_rate(10);
  int count = 0;
  while (ros::ok())
  {


    //สร้าง msg String
    std_msgs::String msg;

    //ใส่ค่า msg String
    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();

    // //แสดงออกทาง console
    // ROS_INFO("%s", msg.data.c_str());

    //ส่งค่าขึ้น topic  chatter_pub
    chatter_pub.publish(msg);





    //////////////////////////////////////////


    //ใส่ค่า msg testPoint

    testPoint.x = 1.0;
    testPoint.y = 0.0;
    testPoint.z = 5.0;

    //แสดงออกทาง console x,y,z
    ROS_INFO("%.2f,%.2f,%.2f", testPoint.x, testPoint.y, testPoint.z);

    //ส่งค่าขึ้น topic  point_pub
    point_pub.publish(testPoint);

    
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }
  return 0;
}
