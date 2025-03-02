#ifndef _ROS_sensor_msgs_RelativeHumidity_h
#define _ROS_sensor_msgs_RelativeHumidity_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros_lib/ros/msg.h"
#include "ros_lib/std_msgs/Header.h"

namespace sensor_msgs
{

  class RelativeHumidity : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _relative_humidity_type;
      _relative_humidity_type relative_humidity;
      typedef float _variance_type;
      _variance_type variance;

    RelativeHumidity():
      header(),
      relative_humidity(0),
      variance(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->relative_humidity);
      offset += serializeAvrFloat64(outbuffer + offset, this->variance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->relative_humidity));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->variance));
     return offset;
    }

    virtual const char * getType() override { return "sensor_msgs/RelativeHumidity"; };
    virtual const char * getMD5() override { return "8730015b05955b7e992ce29a2678d90f"; };

  };

}
#endif
