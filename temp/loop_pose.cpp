/**
 * ************************************************************************
 * 
 * @file loop_pose.cpp
 * @author Zhang Jiaqi (zhangiaii97@gmail.com)
 * @brief 
 * 
 * ************************************************************************
 * @copyright Copyright (c) 2024 
 * For study and research only, no reprinting
 * ************************************************************************
 */

#include "sensor_data/loop_pose.hpp"

namespace localization {
Eigen::Quaternionf LoopPose::GetQuaternion()
{
  Eigen::Quaternionf q;
  q = pose.block<3,3>(0,0);

  return q;
}

} //namespace lidar_localization