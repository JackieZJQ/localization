/**
 * ************************************************************************
 * 
 * @file key_frame.cpp
 * @author Zhang Jiaqi (zhangiaii97@gmail.com)
 * @brief 
 * 
 * ************************************************************************
 * @copyright Copyright (c) 2024 
 * For study and research only, no reprinting
 * ************************************************************************
 */

#include "sensor_data/key_frame.hpp"

namespace localization {
Eigen::Quaternionf KeyFrame::GetQuaternion()
{
  Eigen::Quaternionf q;
  q = pose.block<3,3>(0,0);

  return q;
}

} //namespace lidar_localization