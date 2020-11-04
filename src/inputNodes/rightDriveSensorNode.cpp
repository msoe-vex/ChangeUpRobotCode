#include "RightDriveSensorNode.h"

RightDriveSensorNode::RightDriveSensorNode():V5Publisher() {
    _encoder_pos = new std_msgs::Int16();
    _encoder_vel = new std_msgs::Int16();
}

void RightDriveSensorNode::setup() {
    // Create a new handle
    ros::NodeHandle handle;

    // Define a topic we will publish to, and where the value
    // will be stored
    ros::Publisher pos_msg("RightDriveSensorPos", _encoder_pos);

    // Define a topic we will publish to, and where the value
    // will be stored
    ros::Publisher vel_msg("RightDriveSensorVel", _encoder_vel);

    // Initialize the handler, and set up data relating to what this node publishes
    handle.initNode();
    handle.advertise(pos_msg);
    handle.advertise(vel_msg);

    // Add the corresponding publishers to the memory locations that hold their data
    addMessageHolder(&pos_msg, _encoder_pos);
    addMessageHolder(&vel_msg, _encoder_vel);

    while (1) {
        // Put our value(s) into memory where the publisher is told to look
        _encoder_pos->data = 0;
        _encoder_vel->data = 0;

        // Run the publisher loop (automatically handles our wait loop)
        loop(handle);
    }
}

RightDriveSensorNode::~RightDriveSensorNode() {
    delete _encoder_pos;
    delete _encoder_vel;
}