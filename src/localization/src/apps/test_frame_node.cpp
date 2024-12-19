/**
 * ************************************************************************
 * 
 * @file test_frame_node.cpp
 * @author Zhang Jiaqi (zhangiaii97@gmail.com)
 * @brief 
 * 
 * ************************************************************************
 * @copyright Copyright (c) 2024 
 * For study and research only, no reprinting
 * ************************************************************************
 */

#include <rclcpp/rclcpp.hpp>

#include "subscriber/gnss_subscriber.hpp"
#include "subscriber/imu_subscriber.hpp"

using namespace localization;

class TestFrameNode {
public:
  TestFrameNode(const char* name) 
    :node_(std::make_shared<rclcpp::Node>(name))
  {
    gnss_subscriber_ = std::make_shared<GNSSSubscriber>(node_, "/kitti/oxts/gps/fix", 10);
    imu_subscriber_ = std::make_shared<IMUSubscriber>(node_, "/kitti/oxts/imu", 10);
    
  }

  void Start()
  {
    rclcpp::spin(node_);
  }

public:
  rclcpp::Node::SharedPtr node_;  
  GNSSSubscriber::SharedPtr gnss_subscriber_;
  IMUSubscriber::SharedPtr imu_subscriber_;
};


int main(int argc, char** argv)
{
  rclcpp::init(argc, argv); 
  auto test_frame_node = std::make_shared<TestFrameNode>("test_frame_node");
  test_frame_node->Start();

  rclcpp::shutdown();
  return 0;
}