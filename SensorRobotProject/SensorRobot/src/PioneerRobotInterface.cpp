#include"PioneerRobotInterface.h"
#include"Pose.h"
#include"RangeSensor.h"
#include"SonarSensor.h"
#include"LaserSensor.h"
using namespace std;
/**
 * @file PioneerRobotInterface.cpp
 * @Author Melih Bucak (bckmelih@gmail.com)
 * @date ,January 2021
 * @brief this is derived class from abstract RobotInterface class.
 *
 */

//! PioneerRobotInterface constructor. 
PioneerRobotInterface::PioneerRobotInterface() {
	robotAPI = new PioneerRobotAPI;
	state = 0;
	position = new Pose;
	if (!robotAPI->connect()) {
		cout << "Could not connect..." << endl;
	}
	else
		cout << "Could connect..." << endl;
}
/*!
  \robot turns left
  \state is equal to -1
*/
void PioneerRobotInterface::turnLeft() {
	robotAPI->turnRobot(PioneerRobotAPI::DIRECTION::left);
	state = -1;
}
/*!
  \robot turns left
  \state is equal to -1
*/
void PioneerRobotInterface::turnRight() {
	robotAPI->turnRobot(PioneerRobotAPI::DIRECTION::right);
	state = 1;
}
/*!
   \param speed
   \robot move forward
*/
void PioneerRobotInterface::forward(float speed) {
	if (state == 1 || state == -1)
	{
		robotAPI->turnRobot(PioneerRobotAPI::DIRECTION::forward);
		state = 0;
	}
	robotAPI->moveRobot(speed);
	cout << "Robot moving forward at " << speed << " mm/s" << endl;
}
/*!
   \param speed
   \robot move backward
*/
void  PioneerRobotInterface::backward(float speed) {
	if (state == 1 || state == -1)
	{
		robotAPI->turnRobot(PioneerRobotAPI::DIRECTION::forward);
		state = 0;
	}
	robotAPI->moveRobot(speed);
	cout << "Robot moving backward at " << speed << " mm/s" << endl;
}
/*!
   \print robot state
*/
void PioneerRobotInterface::print() {
	if (state == 0)
		cout << "Robot is standing now" << endl;
	else if (state == -1)
		cout << "Robot is turning left" << endl;
	else if (state == 1)
		cout << "Robot is turning right" << endl;
}
/*!
   \return position pose argument
*/
Pose PioneerRobotInterface::getPose() {
	Pose knm;
	knm.setPose(robotAPI->getX(), robotAPI->getY(), robotAPI->getTh());
	return knm;
}
/*!
   \param konum Pose argument
   \set position of the robot
*/
void PioneerRobotInterface::setPose(Pose konum) {

	robotAPI->setPose(konum.getX(), konum.getY(), konum.getTh());
	position->setX(konum.getX());
	position->setY(konum.getY());
	position->setTh(konum.getTh());
	cout << "position=> (" << position->getX() << "," << position->getY() << ") th= " << position->getTh() << endl;

}
/*!
	\stop turning robot
*/
void PioneerRobotInterface::stopTurn() {
	if (state == 1 || state == -1)
	{
		robotAPI->turnRobot(PioneerRobotAPI::DIRECTION::forward);
		state = 0;
	}
	cout << "Robot is standing now" << endl;
}
/*!
  \stop moving robot
*/
void PioneerRobotInterface::stopMove() {
	robotAPI->stopRobot();
	position->setX(robotAPI->getX());
	position->setY(robotAPI->getY());
	position->setTh(robotAPI->getTh());
	cout << "Robot is stop" << endl;
}
/*!
	\get sensor informations from PioneerRobotAPI class.
	\send the sensor informations to the LaserSensor class' update method.
*/
void PioneerRobotInterface::updateSensor() {

	robotAPI->getLaserRange(this->LaserSensorBilgileri);
	LaserSensor laserSensor;
	RangeSensor& rangeNesnesi = laserSensor;
	rangeNesnesi.updateSensor(this->LaserSensorBilgileri);

	SonarSensor sonarSensor;
	RangeSensor& rangeNesnesi2 = sonarSensor;
	robotAPI->getSonarRange(this->SonarSensorBilgileri);
	rangeNesnesi2.updateSensor(this->SonarSensorBilgileri);
}