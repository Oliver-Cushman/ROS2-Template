#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "interfaces/msg/example.hpp"

using namespace std::chrono_literals;

class PubNode : public rclcpp::Node
{
public:
  PubNode() : Node("pub_node")
  {
    publisher_ = this->create_publisher<interfaces::msg::Example>("ExampleTopic", 10);
    timer_ = this->create_wall_timer(500ms, std::bind(&PubNode::timer_callback, this));
    count_ = 0;
  }

private:
  void timer_callback()
  {
    count_++;
    auto example = interfaces::msg::Example();
    example.message = count_;
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", example.message);
    publisher_->publish(example);
  }
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<interfaces::msg::Example>::SharedPtr publisher_;
  int count_;
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PubNode>());
  rclcpp::shutdown();
  return 0;
}