cmake_minimum_required(VERSION 3.5)
project(localization)

# Default to C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE "Release")

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(GeographicLib REQUIRED)
find_package(Eigen3 REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/include
                    ${GeographicLib_INCLUDE_DIRS}
                    ${EIGEN3_INCLUDE_DIR})         

## Files ##
file(GLOB_RECURSE ALL_SRCS "*.cpp")
file(GLOB_RECURSE NODE_SRCS "src/apps/*_node.cpp")
list(REMOVE_ITEM ALL_SRCS ${NODE_SRCS})

## Build ##
# test_frame_node.cpp
add_executable(test_frame_node ${PROJECT_SOURCE_DIR}/src/apps/test_frame_node.cpp ${ALL_SRCS})
ament_target_dependencies(test_frame_node rclcpp sensor_msgs)
target_link_libraries(test_frame_node ${GeographicLib_LIBRARIES})

## Install ##
install(TARGETS
  test_frame_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
