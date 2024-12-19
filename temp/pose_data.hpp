/**
 * ************************************************************************
 * 
 * @file pose_data.hpp
 * @author Zhang Jiaqi (zhangiaii97@gmail.com)
 * @brief 
 * 
 * ************************************************************************
 * @copyright Copyright (c) 2024 
 * For study and research only, no reprinting
 * ************************************************************************
 */

#pragma once 

#include <Eigen/Dense>

namespace localization {
class PoseData {
public:
  double time = 0.0;
  Eigen::Matrix4f pose = Eigen::Matrix4f::Identity();

public:
  Eigen::Quaternionf GetQuaternion();
};
} // namespace localization