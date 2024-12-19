/**
 * ************************************************************************
 * 
 * @file imu_data.cpp
 * @author Zhang Jiaqi (zhangiaii97@gmail.com)
 * @brief 
 * 
 * ************************************************************************
 * @copyright Copyright (c) 2024 
 * For study and research only, no reprinting
 * ************************************************************************
 */

#include "sensor_data/imu_data.hpp"

namespace localization {
Eigen::Matrix3f IMUData::GetOrientationMatrix()
{
  Eigen::Quaterniond q(orientation.w, orientation.x, orientation.y, orientation.z);
  Eigen::Matrix3f matrix = q.matrix().cast<float>();

  return matrix;
}

bool IMUData::SyncData(std::deque<IMUData>& UnsyncedData, std::deque<IMUData>& SyncedData, double sync_time)
{
  // 传感器数据按时间序列排列，在传感器数据中为同步的时间点找到合适的时间位置
  // 即找到与同步时间相邻的左右两个数据
  // 需要注意的是，如果左右相邻数据有一个离同步时间差值比较大，则说明数据有丢失，时间离得太远不适合做差值



  return true;
}

} //namespace lidar_localization