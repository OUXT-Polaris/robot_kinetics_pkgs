#ifndef FAKE_COG_PUBLISHER_H_INCLUDED
#define FAKE_COG_PUBLISHER_H_INCLUDED

//headers for standard library
#include <vector>

//headers for ROS
#include <ros/ros.h>

// publish message
#include <geometry_msgs/PointStamped.h>

class fake_cog_publisher
{
public:
  fake_cog_publisher();
  
  //publish CoG
  void publish();
  //parameter getter
  inline int get_publish_rate(void) const {return this->publish_rate;};
  inline double get_robot_total_mass(void) const {return this->robot_total_mass;};
 
private:
  ros::NodeHandle nh;
  //ros publisher and subscriber
  ros::Publisher fake_cog_point_pub;

  //parameters
  int publish_rate;
  double robot_total_mass;
  // following message is specialized for fake_cog_publisher
  geometry_msgs::PointStamped fake_cog_point;
};
#endif
