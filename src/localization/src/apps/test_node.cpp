#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/nav_sat_fix.hpp>

class TestNode : public rclcpp::Node {
public:
  TestNode(const char* name):Node(name)
  {
    sub_ = this->create_subscription<sensor_msgs::msg::NavSatFix>("/kitti/oxts/gps/fix", 10, std::bind(&TestNode::callback, this, std::placeholders::_1));

  }

  void callback(const sensor_msgs::msg::NavSatFix::SharedPtr msg)
  {
    std::cout << "TestNode::callback" <<std::endl;
  }

public:
  rclcpp::Subscription<sensor_msgs::msg::NavSatFix>::SharedPtr sub_;
};

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TestNode>("test_node"));
  rclcpp::shutdown();

  return 0;
}