/**
 * ************************************************************************
 * 
 * @file cloud_data.hpp
 * @author Zhang Jiaqi (zhangiaii97@gmail.com)
 * @brief 
 * 
 * ************************************************************************
 * @copyright Copyright (c) 2024 
 * For study and research only, no reprinting
 * ************************************************************************
 */

#pragma once

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>

namespace localization {
class CloudData {
public:
  using POINT = pcl::PointXYZ;
  using CLOUD = pcl::PointCloud<POINT>;
  using CLOUD_PTR = CLOUD::Ptr;

public:
  CloudData():cloud_ptr(new CLOUD){}

public:
  double time = 0.0;
  CLOUD_PTR cloud_ptr;
};
} //namespace localization