/**
 * ************************************************************************
 * 
 * @file timer.hpp
 * @author Zhang Jiaqi (zhangiaii97@gmail.com)
 * @brief 
 * 
 * ************************************************************************
 * @copyright Copyright (c) 2024 
 * For study and research only, no reprinting
 * ************************************************************************
 */

#pragma once

#include <iostream>
#include <chrono>

class Timer {
public:
  Timer(const char* name) : m_Name(name), m_Stop(false)
  {
    m_StartTimepoint = std::chrono::high_resolution_clock::now();
  }

  void Stop()
  {
    auto endTimePoint = std::chrono::high_resolution_clock::now();

    long long start = std::chrono::time_point_cast<std::chrono::milliseconds>(m_StartTimepoint).time_since_epoch().count();
    long long end = std::chrono::time_point_cast<std::chrono::milliseconds>(endTimePoint).time_since_epoch().count();

    std::cout << m_Name << ":" << (end - start) << "ms\n";
    m_Stop = true;
  }

  ~Timer()
  {
    if (!m_Stop)
      Stop();
  }

private:
  const char* m_Name;
  std::chrono::time_point<std::chrono::steady_clock> m_StartTimepoint;
  bool m_Stop;
};