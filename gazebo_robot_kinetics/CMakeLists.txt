cmake_minimum_required(VERSION 2.8.3)
project(gazebo_robot_kinetics)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  gazebo_ros
  geometry_msgs
  roscpp
  roslib
  rospy
  sensor_msgs
  tf2
)

###################################
## catkin specific configuration ##
###################################
catkin_package(
  INCLUDE_DIRS include
)

###########
## Build ##
###########
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

set(FROM_CONTACT_STATE_TO_WRENCH_STAMPED_NODE_SRC
  src/from_contact_state_to_wrench_stamped_node.cpp
  src/wrench_stamped_converter.cpp
)

add_executable(from_contact_state_to_wrench_stamped_node ${FROM_CONTACT_STATE_TO_WRENCH_STAMPED_NODE_SRC})


target_link_libraries(from_contact_state_to_wrench_stamped_node ${catkin_LIBRARIES})

#############
## Install ##
#############
# CPP Execution programs
set(CPP_EXEC_NAMES
  from_contact_state_to_wrench_stamped_node
)
foreach(cpp_exec_names ${CPP_EXEC_NAMES})
  install(TARGETS ${cpp_exec_names}
    RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
    )
endforeach(cpp_exec_names)
# include header files
install(DIRECTORY include/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)


# Install all files
foreach(dir launch)
  install(DIRECTORY ${dir}/
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/${dir})
endforeach(dir)
#############
## Testing ##
#############
if (CATKIN_ENABLE_TESTING)
  find_package(roslaunch REQUIRED)
  roslaunch_add_file_check(launch)
endif()
