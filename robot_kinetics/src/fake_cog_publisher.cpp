//headers in this package
#include <fake_cog_publisher.h>

//headers for standard library
#include<iostream>

//headers for ROS
#include <ros/ros.h>
#include <ros/package.h>

fake_cog_publisher::fake_cog_publisher()
{
  std::string robot_description_text;
  //get publish_freme parameter
  nh.param<std::string>(ros::this_node::getName()+"/publish_frame", fake_cog_point.header.frame_id, "base_link");
  //get publish_rate parameter
  nh.param<int>(ros::this_node::getName()+"/publish_rate", publish_rate, 50);

  /////////////////////////////////////////////////
  // get CoG information                        //
  // This part exists only in fake_cog_publisher //
  /////////////////////////////////////////////////
  nh.param<double>(ros::this_node::getName()+"/cog_x",
                   fake_cog_point.point.x, 0);
  nh.param<double>(ros::this_node::getName()+"/cog_y",
                   fake_cog_point.point.y, 0);
  nh.param<double>(ros::this_node::getName()+"/cog_z",
                   fake_cog_point.point.z, 0);
  /////////////////////////////////////////////////

  // advertise
  fake_cog_point_pub = nh.advertise<geometry_msgs::PointStamped>("/cog/robot", 1);
}
 

void fake_cog_publisher::publish()
{
  // get current time
  ros::Time now = ros::Time::now();

  //input robot cog data
  fake_cog_point.header.stamp = now;
  //publish cog point of robot (whole body)
  fake_cog_point_pub.publish(fake_cog_point);
}
