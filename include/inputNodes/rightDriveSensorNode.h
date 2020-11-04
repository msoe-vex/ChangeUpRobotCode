#ifndef _RIGHT_DRIVE_SENSOR_NODE_H_
#define _RIGHT_DRIVE_SENSOR_NODE_H_

#include "api.h"
#include "constants.h"
#include "ros_lib/ros.h"
#include "ros_lib/std_msgs/Int16.h"
#include "ros_lib/V5Publisher.h"
#include <vector>

class RightDriveSensorNode : public V5Publisher<std_msgs::Int16> {
private:
public:
    RightDriveSensorNode():V5Publisher() {};

    void setup();

    ~RightDriveSensorNode() {};
};

#endif