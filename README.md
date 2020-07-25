[![Udacity - Robotics NanoDegree Program](https://s3-us-west-1.amazonaws.com/udacity-robotics/Extra+Images/RoboND_flag.png)](https://www.udacity.com/robotics)

# RoboND_P4_Map-My-World
Robotics Software Engineer Project "Map My World"

### Used Packages
[rtabmap_ros](http://wiki.ros.org/rtabmap_ros)

# PROJECT IS IN PROGRESS - DOCUMENTATION IS NOT READY

### Output Video
## Video
[![MCL](http://img.youtube.com/vi/SGKF_wKkWKs/0.jpg)](http://www.youtube.com/watch?v=SGKF_wKkWKs "MPC")

### Steps to launch the simulation

#### Step 1 Update and upgrade the Workspace image
```sh
$ sudo apt-get update
$ sudo apt-get upgrade -y
```

#### Step 2 Install dependencies
```sh
$ sudo apt-get install libignition-math2-dev protobuf-compiler
```

#### Step 3 Clone the lab folder in /home/workspace/
```sh
$ cd /home/workspace/
$ git clone https://github.com/tobiassteidle/RoboND_P3_Where-Am-I
```

#### Step 3 Compile the code
```sh
$ cd /home/workspace/RoboND_P3_Where-Am-I/catkin_ws
$ catkin_make
```

#### Step 4 Source ROS in this workspace
```sh
$ source devel/setup.bash
```

#### Step 5 Run the Simulation  
```sh
$ roslaunch my_robot world.launch
$ roslaunch my_robot amcl.launch 
$ rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```

### Output
![alt text](images/output_1.png)
![alt text](images/output_2.png)


