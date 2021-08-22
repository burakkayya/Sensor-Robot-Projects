#pragma once
#include"Pose.h"
#include"PioneerRobotAPI.h"
#include"RobotInterface.h"
#include"RangeSensor.h"
/**
 * @file PioneerRobotInterface.h
 * @Author Melih Bucak (bckmelih@gmail.com)
 * @date ,January 2021
 * @brief this is derived class from abstract RobotInterface class.
 *
 */
class PioneerRobotInterface : public RobotInterface
{
private:
	float SonarSensorBilgileri[16];
	float LaserSensorBilgileri[181];
	Pose* position;
	PioneerRobotAPI* robotAPI;
	int state;
public:
	PioneerRobotInterface(); /*!< RobotControl constructor */
	void turnLeft(); /*!< robot turn left */
	void turnRight();  /*!< robot turn right */
	void forward(float); /*!< robot move forward */
	void backward(float); /*!< robot moving backward */
	void print(); /*!< print robot state */
	Pose getPose();
	void setPose(Pose);
	void stopTurn(); /*!< robot stop turning  */
	void stopMove(); /*!< robot stop moving*/
	void updateSensor();
};
