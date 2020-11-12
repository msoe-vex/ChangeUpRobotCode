#ifndef _GAME_STATE_NODE_H_
#define _GAME_STATE_NODE_H_

#include "api.h"
#include "constants.h"
#include "ros_lib/ros.h"
#include "ros_lib/std_msgs/UInt8.h"
#include "ros_lib/V5Publisher.h"

class GameStateNode : public V5Publisher<std_msgs::UInt8> {
private:
    ros::NodeHandle* _handle;
    std_msgs::UInt8* _game_state;
public:
    GameStateNode();

    void setup();

    void publish();

    ~GameStateNode();
};

#endif