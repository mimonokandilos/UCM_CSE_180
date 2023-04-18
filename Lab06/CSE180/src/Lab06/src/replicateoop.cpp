//mike monokandilos
//Intro to Robotics
//lab06

#include <rclcpp/rclcpp.hpp>
#include <turtlesim/msg/pose.hpp>
#include <geometry_msgs/msg/twist.hpp>

class ReplicateOop : public rclcpp::Node {
public:
  ReplicateOop() : Node("replicateoop") {
    m_subscribe = this->create_subscription<turtlesim::msg::Pose>("turtle1/pose", 10, std::bind(&ReplicateOop::control, this, std::placeholders::_1));
    m_publish = this->create_publisher<geometry_msgs::msg::Twist>("p2dx/cmd_vel", 10);
  }

  ~ReplicateOop() {}

private:
  void control(const turtlesim::msg::Pose::SharedPtr msg) {
    auto pioneer_vel = geometry_msgs::msg::Twist();
    pioneer_vel.linear.x = msg->linear_velocity;
    pioneer_vel.angular.z = msg->angular_velocity;

    RCLCPP_INFO(this->get_logger(), "publishing: %lf %lf ", pioneer_vel.linear.x, pioneer_vel.angular.z);

    m_publish->publish(pioneer_vel);
  }

  rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr m_subscribe;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr m_publish;
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ReplicateOop>());
  rclcpp::shutdown();
  return 0;
}
