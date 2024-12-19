/**
 * ************************************************************************
 * 
 * @file gnss_subscriber.hpp
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
#include <sensor_msgs/msg/nav_sat_fix.hpp>

#include "sensor_data/gnss_data.hpp"

namespace localization {
class GNSSSubscriber {
public:
  GNSSSubscriber(rclcpp::Node::SharedPtr node, const char* topic_name, size_t buff_size);
  GNSSSubscriber() = default;
  void ParseData(std::deque<GNSSData>& deque_gnss_data);

private:
  void msg_callback(const sensor_msgs::msg::NavSatFix::SharedPtr nav_sat_fix_ptr);

public:
  typedef std::shared_ptr<GNSSSubscriber> SharedPtr;

private:
  rclcpp::Node::SharedPtr node_;
  rclcpp::Subscription<sensor_msgs::msg::NavSatFix>::SharedPtr subscriber_;
  std::deque<GNSSData> new_gnss_data_;

  std::mutex buff_mutex_;
};
} //namespace localization