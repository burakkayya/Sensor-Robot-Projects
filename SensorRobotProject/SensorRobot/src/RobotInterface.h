#pragma once
#include"Pose.h"
/**
 * @file RobotInterface.h
 * @Author Melih Bucak (bckmelih@gmail.com)
 * @date ,January 2021
 * @brief this is abstract base class with pure virtual functions.
 *
 */
class RobotInterface
{
private:
	Pose* position;
	int state;
public:
	virtual void turnLeft() = 0; /*!< robot turn left */
	virtual void turnRight() = 0;  /*!< robot turn right */
	virtual void forward(float) = 0; /*!< robot move forward */
	virtual void backward(float) = 0; /*!< robot moving backward */
	virtual void print() = 0; /*!< print robot state */
	virtual Pose getPose() = 0;
	virtual void setPose(Pose) = 0;
	virtual void stopTurn() = 0; /*!< robot stop turning  */
	virtual void stopMove() = 0; /*!< robot stop moving*/
	virtual void updateSensor() = 0;
};

