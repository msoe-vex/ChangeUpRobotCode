#ifndef _ROS_nav_msgs_GetMapGoal_h
#define _ROS_nav_msgs_GetMapGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros_lib/ros/msg.h"

namespace nav_msgs
{

  class GetMapGoal : public ros::Msg
  {
    public:

    GetMapGoal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return "nav_msgs/GetMapGoal"; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif
