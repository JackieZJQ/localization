/**
 * ************************************************************************
 * 
 * @file gnss_subscriber.cpp
 * @author Zhang Jiaqi (zhangiaii97@gmail.com)
 * @brief 
 * 
 * ************************************************************************
 * @copyright Copyright (c) 2024 
 * For study and research only, no reprinting
 * ************************************************************************
 */

#include "subscriber/gnss_subscriber.hpp"

namespace localization {
GNSSSubscriber::GNSSSubscriber(rclcpp::Node::SharedPtr node, const char* topic_name, size_t buff_size)
  :node_(node)
{
  subscriber_ = node_->create_subscription<sensor_msgs::msg::NavSatFix>(topic_name, buff_size, std::bind(&GNSSSubscriber::msg_callback, this, std::placeholders::_1));

}

void GNSSSubscriber::msg_callback(const sensor_msgs::msg::NavSatFix::SharedPtr nav_sat_fix_ptr)
{
  std::lock_guard<std::mutex> lock(buff_mutex_);

  GNSSData gnss_data;
  gnss_data.time = nav_sat_fix_ptr->header.stamp.sec + nav_sat_fix_ptr->header.stamp.nanosec*1e-9;
  gnss_data.latitude = nav_sat_fix_ptr->latitude;
  gnss_data.longitude = nav_sat_fix_ptr->longitude;
  gnss_data.altitude = nav_sat_fix_ptr->altitude;
  gnss_data.status = nav_sat_fix_ptr->status.status;
  gnss_data.service = nav_sat_fix_ptr->status.service;

  new_gnss_data_.push_back(gnss_data);
}

void GNSSSubscriber::ParseData(std::deque<GNSSData>& deque_gnss_data)
{
  std::lock_guard<std::mutex> lock(buff_mutex_);

  if (new_gnss_data_.size() > 0) 
  {
    deque_gnss_data.insert(deque_gnss_data.end(), new_gnss_data_.begin(), new_gnss_data_.end());
    new_gnss_data_.clear();
  }
}
} //namespace localization