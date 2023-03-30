//Current Folder: posesensor.cpp
//required: moveturtle.cpp(for circular movement)
//and turtlesim turtlesim_node to provide the environment, for where the turtle is created

#include <rclcpp/rclcpp.hpp>
#include <turtlesim/msg/pose.hpp>
#include <std_msgs/msg/float32.hpp>

rclcpp::Node::SharedPtr nodeh;
rclcpp::Rate rate(1);
//float x, y, theta;

void poseRecieved(const turtlesim::msg::Pose::SharedPtr msg) {
    // given we need to get these coords:x,y,theta
    //x = msg->x;
    //y = msg->y;
    //theta = msg->theta;    
    //make sure we format type as float or double to get as many sig figs as possible
    RCLCPP_INFO(nodeh->get_logger(), "POST X-Cordinate: %f", msg->x);
    RCLCPP_INFO(nodeh->get_logger(), "POST Y-oordinate: %f", msg->y);
    RCLCPP_INFO(nodeh->get_logger(), "POST Orientation: %f", msg->theta);
    rate.sleep();
}

int main(int argc, char **argv) {
// we need to make this node publish the xyz which will be picked up by the listner
//look at republish.pose to use the subscriber logic
   
    rclcpp::init(argc, argv);
    nodeh = rclcpp::Node::make_shared("posesensor");
    auto sub = nodeh->create_subscription<turtlesim::msg::Pose>("turtle1/pose", 10, &poseRecieved);
    
//send msg and shutdown    
    rclcpp::spin(nodeh);
    rclcpp::shutdown();
    return 0;
}
