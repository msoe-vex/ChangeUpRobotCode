#ifndef _ROS_geometry_msgs_AccelWithCovarianceStamped_h
#define _ROS_geometry_msgs_AccelWithCovarianceStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros_lib/ros/msg.h"
#include "ros_lib/std_msgs/Header.h"
#include "ros_lib/geometry_msgs/AccelWithCovariance.h"

namespace geometry_msgs
{

  class AccelWithCovarianceStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::AccelWithCovariance _accel_type;
      _accel_type accel;

    AccelWithCovarianceStamped():
      header(),
      accel()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->accel.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->accel.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "geometry_msgs/AccelWithCovarianceStamped"; };
    virtual const char * getMD5() override { return "96adb295225031ec8d57fb4251b0a886"; };

  };

}
#endif
