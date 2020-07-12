#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z)
{
    ball_chaser::DriveToTarget srv;
    srv.request.linear_x = lin_x;
    srv.request.angular_z = ang_z;

    // Call the command_robot service and pass the requested velocities
    if (!client.call(srv))
        ROS_ERROR("Failed to call service /ball_chaser/command_robot");
}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{
    int white_pixel = 255;

    // Loop through each pixel in the image and check if there's a bright white one
    // Identify if this pixel falls in the left, mid, or right side of the image
    // Depending on the white ball position, call the drive_bot function and pass velocities to it
    // Request a stop when there's no white ball seen by the camera
    bool ball_detected = false;
    int ball_pos_x = -1;
    const int column_width = img.step / 3;

    for(int idx = 0; idx < img.height * img.step; idx+=3)
    {
        const uint8_t r = img.data[idx];
        const uint8_t g = img.data[idx+1];
        const uint8_t b = img.data[idx+2];

        if ((r == 255) && (g == 255) && (b == 255))
        {
            ball_detected = true;
            ball_pos_x = idx % img.step;
            break;
        }
    }

    if(!ball_detected)
    {
	    // Stop Robot
        drive_robot(0.0, 0.0);
    }
    else
    {
        if (ball_pos_x < column_width)
        {
      		// Turn left
            drive_robot(0.0, 0.75);
    	}
    	else if (ball_pos_x > column_width && ball_pos_x < column_width * 2)
    	{
            // Drive Forward
            drive_robot(0.5, 0.0);
    	}
    	else
    	{
            // Turn right
            drive_robot(0.0, -0.75);
    	}
    }
}

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}
