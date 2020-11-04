#ifndef _CHASSIS_H_
#define _CHASSIS_H_

#include "api.h"

class chassis {
public:
  pros::Motor *leftFrontDriveMotor, *leftRearDriveMotor,
              *rightFrontDriveMotor, *rightRearDriveMotor;

  chassis(int leftFrontDriveMotorPort, int leftRearDriveMotorPort,
          int rightFrontDriveMotorPort, int rightRearDriveMotorPort);

  void setSpeed(int leftDriveSpeed, int rightDriveSpeed);

  ~chassis();
};

#endif