//headers in this package
#include <fake_cog_publisher.h>

//headers for ROS
#include <ros/ros.h>

int main(int argc, char *argv[])
{
  ros::init(argc, argv, "fake_cog_publisher");
  fake_cog_publisher fake_cog_pub;
  ros::Rate rate(fake_cog_pub.get_publish_rate());
  while(ros::ok())
  {
    fake_cog_pub.publish();
    rate.sleep();
  }
  return 0;
}
