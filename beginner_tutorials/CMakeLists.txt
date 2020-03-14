cmake_minimum_required(VERSION 2.8.3)
project(beginner_tutorials)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
)


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES beginner_tutorials
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(my_publisher src/my_publisher.cpp)

add_executable(my_subscriber src/my_subscriber.cpp)




add_dependencies(my_publisher ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_dependencies(my_subscriber ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})





target_link_libraries(my_publisher 
	${catkin_LIBRARIES}
)

target_link_libraries(my_subscriber 
	${catkin_LIBRARIES}
)



