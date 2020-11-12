#include "GameStateNode.h"

GameStateNode::GameStateNode() {
    _handle = new ros::NodeHandle();
    _game_state = new std_msgs::UInt8();
}

void GameStateNode::setup() {
    // Define a topic we will publish to, and where the value
    // will be stored
    ros::Publisher game_msg("GameState", _game_state);

    // Initialize the handler, and set up data relating to what this node publishes
    _handle->initNode();
    _handle->advertise(game_msg);

    // Add the corresponding publishers to the memory locations that hold their data
    addMessageHolder(&game_msg, _game_state);
}

void GameStateNode::publish() {
    // Put our value(s) into memory where the publisher is told to look
    _game_state->data = 0;

    // Run the publisher loop (does not handle delay)
    V5Publisher::publish(*_handle);
} 

GameStateNode::~GameStateNode() {
    delete _handle;
    delete _game_state;
}