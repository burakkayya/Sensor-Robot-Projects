
/**
 * @file Robotcontrol.h
 * @Author  Eþref Burak KAYA (ebkaya.0637@gmail.com)
 * @Author Gamze Bilmez (gamzebilmezz@gmail.com)
 * @date January, 2021
 * @brief Robot Menu app
 *
 */

#pragma once
#include"PioneerRobotInterface.h"
#include"Path.h"
#include"Record.h"
#include"RobotOperator.h"
#include"RobotInterface.h"
#include"PioneerRobotAPI.h"
#include"RangeSensor.h"
#include"LaserSensor.h"
#include"SonarSensor.h"
class RobotControl
{
private:
	RobotInterface* robotAPI;
	PioneerRobotInterface inter;
	Path* path;
	Record rec;
	RobotOperator operat;
	bool access;
	int state;
	RangeSensor* sonar;
	RangeSensor* laser;
	LaserSensor lasersensor;
	SonarSensor sonarsensor;
	float ranges[16];
	float range[181];

public:

	RobotControl();
	void turnLeft();/*!< robot turn left */
	void turnRight();/*!< robot turn right */
	void forward(float);/*!< robot move forward */
	void backward(float);/*!< robot moving backward */
	void print(); /*!< print robot state */
	Pose getPose();/*!<get robot pose*/
	void setPose(Pose);/*!< set robot pose */
	void stopTurn();/*!< robot stop turning  */
	void stopMove();/*!< robot stop moving*/
	bool addToPath(); /*!< pose added to path*/
	bool clearPath();/*!< path is clear*/
	bool recordPathtoFile(); /*!< record robot path*/
	bool openAccess(); /*!< allow operator access*/
	bool closeAccess(); /*!< don t allow operator access*/
	void sonarSENSOR();/*!< write robot's sonar sensor*/
	void laserSENSOR();/*!< write robot's laser sensor*/
};

