/**
 * ************************************************************************
 * 
 * @file imu_subscriber.cpp
 * @author Zhang Jiaqi (zhangiaii97@gmail.com)
 * @brief 
 * 
 * ************************************************************************
 * @copyright Copyright (c) 2024 
 * For study and research only, no reprinting
 * ************************************************************************
 */

#include "subscriber/imu_subscriber.hpp"

namespace localization {
IMUSubscriber::IMUSubscriber(rclcpp::Node::SharedPtr node, const char* topic_name, size_t buff_size)
  :node_(node)
{
  subscriber_ = node_->create_subscription<sensor_msgs::msg::Imu>(topic_name, buff_size, std::bind(&IMUSubscriber::msg_callback, this, std::placeholders::_1));
  
}

void IMUSubscriber::msg_callback(const sensor_msgs::msg::Imu::SharedPtr imu_msg_ptr)
{
  std::lock_guard<std::mutex> lock(buff_mutex_);

  IMUData imu_data;
  imu_data.time = imu_msg_ptr->header.stamp.sec + imu_msg_ptr->header.stamp.nanosec*1e-9;
  
  imu_data.linear_acceleration.x = imu_msg_ptr->linear_acceleration.x;
  imu_data.linear_acceleration.y = imu_msg_ptr->linear_acceleration.y;
  imu_data.linear_acceleration.z = imu_msg_ptr->linear_acceleration.z;

  imu_data.angular_velocity.x = imu_msg_ptr->angular_velocity.x;
  imu_data.angular_velocity.y = imu_msg_ptr->angular_velocity.y;
  imu_data.angular_velocity.z = imu_msg_ptr->angular_velocity.z;

  imu_data.orientation.x = imu_msg_ptr->orientation.x;
  imu_data.orientation.y = imu_msg_ptr->orientation.y;
  imu_data.orientation.z = imu_msg_ptr->orientation.z;
  imu_data.orientation.w = imu_msg_ptr->orientation.w;

  new_imu_data_.push_back(imu_data);
}

void IMUSubscriber::ParseData(std::deque<IMUData>& deque_imu_data)
{
  std::lock_guard<std::mutex> lock(buff_mutex_);

  if (new_imu_data_.size() > 0)
  {
    deque_imu_data.insert(deque_imu_data.end(), new_imu_data_.begin(), new_imu_data_.end());
    new_imu_data_.clear();
  }
}
} //namespace localization