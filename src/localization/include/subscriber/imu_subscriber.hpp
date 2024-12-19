/**
 * ************************************************************************
 * 
 * @file imu_subscriber.hpp
 * @author Zhang Jiaqi (zhangiaii97@gmail.com)
 * @brief 
 * 
 * ************************************************************************
 * @copyright Copyright (c) 2024 
 * For study and research only, no reprinting
 * ************************************************************************
 */

#pragma once 

#include <mutex>
#include <deque>
#include <thread>

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/imu.hpp>

#include "sensor_data/imu_data.hpp"

namespace localization {
class IMUSubscriber {
  IMUSubscriber(rclcpp::Node::SharedPtr node, const char* topic_name, size_t buff_size);
  IMUSubscriber() = default;
  void ParseData(std::deque<IMUData>& deque_imu_data);

private:
  void msg_callback(const sensor_msgs::msg::Imu::SharedPtr imu_msg_ptr);

public:
  typedef std::shared_ptr<IMUSubscriber> SharedPtr;

private:
  rclcpp::Node::SharedPtr node_;
  rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr subscriber_;
  std::deque<IMUData> new_imu_data_;

  std::mutex buff_mutex_;
};
} //namespace localization