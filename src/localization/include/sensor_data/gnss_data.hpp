/**
 * ************************************************************************
 * 
 * @file gnss_data.hpp
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

#include <GeographicLib/LocalCartesian.hpp>

namespace localization {
class GNSSData {
public:
  double time = 0.0;
  double longitude = 0.0;
  double latitude = 0.0;
  double altitude = 0.0;
  double local_E = 0.0;
  double local_N = 0.0;
  double local_U = 0.0;
  int status = 0;
  int service = 0;

  static double origin_longitude;
  static double origin_latitude;
  static double origin_altitude;

private:
  static GeographicLib::LocalCartesian geo_converter;
  static bool origin_position_inited;

public:
  void InitOriginPosition();
  void UpdateXYZ();
  static bool SyncData(std::deque<GNSSData>& UnsyncedData, std::deque<GNSSData>& SyncedData, double sync_time);
};
} //namespace localization