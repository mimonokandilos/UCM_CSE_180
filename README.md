# Intro To Robotics
### UCM_CSE_180
### Author: Mike Monokandilos
### Instructor: StefanoCarpin

# Creating a Workspace
- 
    mkdir -p CSE180/src
    colcon build
    . install/local_setup.bash

# Creating a Package
-  
    ros2 pkg create [name_of_pkg]
    ros2 pkg create --build-type ament_cmake [name_of_pkg]


