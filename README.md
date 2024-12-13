# 1.关于这个项目
这个项目在参考了任乾​大佬写的”从零开始做自动驾驶定位“，和高翔大佬写的“自动驾驶中的slam技术”，实现一种多传感器融合定位，包含IMU,GNSS,NDT,轮速的信息。
高翔大佬github地址: https://github.com/gaoxiang12/slam_in_autonomous_driving
任乾​大佬博客地址：https://zhuanlan.zhihu.com/c_1114864226103037952

# 2.调试环境
- ubuntu 20.04
- ros foxy
- pcl 1.10
- glog

# 3.测试数据
开源程序最好使用开放数据集，所以我们选择了KITTI，并且把RawData里的"2011_10_03_drive_0027_sync"做成了bag文件，
后面所有程序的测试都是在这个bag基础上做的。
