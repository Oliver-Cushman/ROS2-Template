#include "interfaces/msg/example.hpp"
#include "rclcpp/rclcpp.hpp"

class SubNode : public rclcpp::Node
{
public:
    SubNode() : Node("sub_node")
    {
        subscriber_ = this->create_subscription<interfaces::msg::Example>("ExampleTopic", 10, std::bind(&SubNode::subscriber_callback, this, std::placeholders::_1));
    }

private:
    void
    subscriber_callback(const interfaces::msg::Example::SharedPtr example)
    {
        RCLCPP_INFO(this->get_logger(), "Recieving: %i", example->message);
    }
    rclcpp::Subscription<interfaces::msg::Example>::SharedPtr subscriber_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SubNode>());
    rclcpp::shutdown();
    return 0;
}