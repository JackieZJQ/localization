/**
 * ************************************************************************
 * 
 * @file gnss_data.cpp
 * @author Zhang Jiaqi (zhangiaii97@gmail.com)
 * @brief 
 * 
 * ************************************************************************
 * @copyright Copyright (c) 2024 
 * For study and research only, no reprinting
 * ************************************************************************
 */

#include <iostream>

#include "sensor_data/gnss_data.hpp"

//静态成员变量必须在类外定义(初始化)
double localization::GNSSData::origin_longitude = 0.0;
double localization::GNSSData::origin_latitude = 0.0;
double localization::GNSSData::origin_altitude = 0.0;
bool localization::GNSSData::origin_position_inited = false;
GeographicLib::LocalCartesian localization::GNSSData::geo_converter;

namespace localization {
void GNSSData::InitOriginPosition() 
{
  geo_converter.Reset(latitude, longitude, altitude);

  origin_longitude = longitude;
  origin_latitude = latitude;
  origin_altitude = altitude;

  origin_position_inited = true;
}

void GNSSData::UpdateXYZ() 
{
  if (!origin_position_inited) 
  {
    std::cout << "GeoConverter has not set origin position";
  }

  geo_converter.Forward(latitude, longitude, altitude, local_E, local_N, local_U);
}

bool GNSSData::SyncData(std::deque<GNSSData>& UnsyncedData, std::deque<GNSSData>& SyncedData, double sync_time)
{
  // 传感器数据按时间序列排列，在传感器数据中为同步的时间点找到合适的时间位置
  // 即找到与同步时间相邻的左右两个数据
  // 需要注意的是，如果左右相邻数据有一个离同步时间差值比较大，则说明数据有丢失，时间离得太远不适合做差值

  //todo

  return true;
}

} //namespace lidar_localization