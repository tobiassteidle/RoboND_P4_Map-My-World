[![Udacity - Robotics NanoDegree Program](https://s3-us-west-1.amazonaws.com/udacity-robotics/Extra+Images/RoboND_flag.png)](https://www.udacity.com/robotics)

# RoboND_P3_Where-Am-I
Robotics Software Engineer Project "Where Am I"

### Used Packages
[AMCL Package](http://wiki.ros.org/amcl)
[PGM Map Creator](https://github.com/udacity/pgm_map_creator.git)

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
```

### Output
![alt text](images/output.png)
