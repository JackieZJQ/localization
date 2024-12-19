/**
 * ************************************************************************
 * 
 * @file velocity_data.hpp
 * @author Zhang Jiaqi (zhangiaii97@gmail.com)
 * @brief 
 * 
 * ************************************************************************
 * @copyright Copyright (c) 2024 
 * For study and research only, no reprinting
 * ************************************************************************
 */

#pragma once 

#include <deque>
#include <Eigen/Dense>

namespace localization {
class VelocityData {
public:
  struct LinearAcceleration 
  {
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
  };

  struct AngularVelocity
  {
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
  };

  double time = 0.0;
  LinearAcceleration linear_acceleration;
  AngularVelocity angular_velocity;

public:
  void TransformCoordinate(Eigen::Matrix4f transform_matrix);
  static bool SyncData(std::deque<VelocityData>& UnsyncedData, std::deque<VelocityData>& SyncedData, double sync_time);
};
} //namespace localization