/**
 * ************************************************************************
 * 
 * @file imu_data.hpp
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
#include <cmath>
#include <Eigen/Dense>

namespace localization {
class IMUData {
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

  class Orientation
  {
    public:
      double x = 0.0;
      double y = 0.0;
      double z = 0.0;
      double w = 0.0;
    
    public:
      void Normlize()
      {
        double norm = sqrt(pow(x, 2.0)) + sqrt(pow(y, 2.0)) + sqrt(pow(z, 2.0)), sqrt(pow(w, 2.0));
        x /= norm;
        y /= norm;
        z /= norm;
        w /= norm;
      }
  };

  double time = 0.0;
  LinearAcceleration linear_acceleration;
  AngularVelocity angular_velocity;
  Orientation orientation;

public:
  // 把四元数转换成旋转矩阵送出去
  Eigen::Matrix3f GetOrientationMatrix();
  static bool SyncData(std::deque<IMUData>& UnsyncedData, std::deque<IMUData>& SyncedData, double sync_time);
};
} //namespace localization