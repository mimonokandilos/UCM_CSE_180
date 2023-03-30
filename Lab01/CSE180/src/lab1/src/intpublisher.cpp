/*
Copyright 2023 Stefano Carpin

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <rclcpp/rclcpp.hpp> // needed for basic functions
#include <std_msgs/msg/int32.hpp> // needed because we publish strings

int main(int argc,char **argv) {

  rclcpp::init(argc,argv); // initialize the ROS subsystem

  rclcpp::Node::SharedPtr nodeh;
  //::Node::SharedPtr inttopic;
  rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr pub;
  //rclcpp::Publisher<std_msgs::msg::int32>::SharedPtr pubTopic;
  rclcpp::Rate rate(1); // create rate object
  
  nodeh = rclcpp::Node::make_shared("intpublisher"); // create node instance
 //inttopic = rclcpp::Node::make_shared("inttopic"); // create node instance
  // create publisher to topic "message" of int32
  pub = nodeh->create_publisher<std_msgs::msg::Int32>("inttopic",1);
  //pubTopic = inttopic->create_publisher<std_msgs::msg::int32>("message",1);
  
  int counter = 0;
 // int zero = 0;
  while ( (counter++ < 100) && (rclcpp::ok())  ) {
    RCLCPP_INFO(nodeh->get_logger(),"Counter: %d", counter);
    std_msgs::msg::Int32 stringtosend;

    // prepare message to send
    stringtosend.data  = counter;
    pub->publish(stringtosend); // publish message
    
    //if( zero ==1){
       //add log extreaction with another extractio
    //  RCLCPP_INFO(inttopic->get_logger(),"Sending message #%d",zero);
   // std_msgs::msg::String stringtosend2;
    //newaddition
      // prepare message to send
    //stringtosend2.data = "Message # 2with the new counter: " + std::to_string(zero);
   //pubTopic->publish(stringtosend2); // publish message
    
   // }
    
    rate.sleep(); // wait
  } 
  rclcpp::shutdown(); // shutdown ROS
  return 0;
}
