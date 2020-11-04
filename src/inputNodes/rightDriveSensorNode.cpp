#include "RightDriveSensorNode.h"

void RightDriveSensorNode::setup() {
    // Create a new handle
    ros::NodeHandle handle;

    // Create a place in memory to hold our encoder position, and the corresponding topic
    // to publish the value to
    auto encoder_pos = std::make_shared<std_msgs::Int16>();
    ros::Publisher pos_msg("RightDriveSensorPos", encoder_pos.get());

    // Create a place in memory to hold our encoder velocity, and the corresponding topic
    // to publish the value to
    auto encoder_vel = std::make_shared<std_msgs::Int16>();
    ros::Publisher vel_msg("RightDriveSensorVel", encoder_vel.get());

    // Initialize the handler, and set up data relating to what this node publishes
    handle.initNode();
    handle.advertise(pos_msg);
    handle.advertise(vel_msg);

    // Add the corresponding publishers to the memory locations that hold their data
    addMessageHolder(&pos_msg, encoder_pos);
    addMessageHolder(&vel_msg, encoder_vel);

    while (1) {
        // Put our value(s) into memory where the publisher is told to look
        encoder_pos->data = 0;
        encoder_vel->data = 0;

        // Run the publisher loop (automatically handles our wait loop)
        loop(handle);
    }
}