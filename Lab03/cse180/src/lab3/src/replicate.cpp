//mike monokandilos
//Intro to Robotics
//lab3

#include <rclcpp/rclcpp.hpp>
#include <turtlesim/msg/pose.hpp>
#include <geometry_msgs/msg/twist.hpp>

rclcpp::Node::SharedPtr nodeh;

float velocity = 0;
float angvelocity = 0;

void poseReceived(const turtlesim::msg::Pose::SharedPtr msg) {
  //rclcpp::Rate rate(6) :: rate of messages being recieved //rate sleep???]
  velocity = msg->linear_velocity;
  angvelocity = msg->angular_velocity;
}

int main(int argc,char ** argv) {

  //initialize ros
  rclcpp::init(argc,argv); 
  //create new node,subscribe to turtle node/pose,and finally the gaazeebo robot
  nodeh = rclcpp::Node::make_shared("replicate"); 
  auto sub = nodeh->create_subscription<turtlesim::msg::Pose>("turtle1/pose",10,&poseReceived); 
  auto pub = nodeh->create_publisher<geometry_msgs::msg::Twist>("p2dx/cmd_vel",100); 

  geometry_msgs::msg::Twist pioneer_vel;
  while (rclcpp::ok()) {
    rclcpp::spin_some(nodeh);
    pioneer_vel.linear.x = velocity;
    pioneer_vel.angular.z = angvelocity;
    pub->publish(pioneer_vel);
  }

  return 0;
}
