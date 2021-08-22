/**
 * @file Robotcontrol.cpp
 * @Author  Eþref Burak KAYA (ebkaya.0637@gmail.com)
 * @Author Gamze Bilmez (gamzebilmezz@gmail.com)
 * @date January, 2021
 * @brief Robot Menu app
 *
 */
#include"RobotControl.h"
#include"PioneerRobotInterface.h"
#include"Pose.h"
#include"Path.h"
#include"RangeSensor.h"
#include"LaserSensor.h"
#include"SonarSensor.h"
using namespace std;
//! Robotcontrol constructor. 
RobotControl::RobotControl()
{
	robotAPI = &inter;
	sonar = &sonarsensor;
	laser = &lasersensor;
	path = new Path;
	state = 0;

	
}
/*!
  \robot turns left
  \state is equal to -1
*/
void RobotControl::turnLeft() {
	robotAPI->turnLeft();
	state = -1;
}
/*!
  \robot turns left
  \state is equal to -1
*/
void RobotControl::turnRight() {
	robotAPI->turnRight();
	state = 1;
}
/*!
   \param speed
   \robot move forward
*/
void RobotControl::forward(float speed) {
	robotAPI->forward(speed);
	cout << "Robot moving forward at " << speed << " mm/s" << endl;
}
/*!
   \param speed
   \robot move backward
*/
void  RobotControl::backward(float speed) {
	robotAPI->backward(speed);
	cout << "Robot moving backward at " << speed << " mm/s" << endl;
}
/*!
   \print robot state
*/
void RobotControl::print() {
	if (state == 0)
		cout << "Robot is standing now" << endl;
	else if (state == -1)
		cout << "Robot is turning left" << endl;
	else if(state==1)
		cout << "Robot is turning right" << endl;
}
/*!
   \return position pose argument
*/
Pose RobotControl::getPose() { 

	return robotAPI->getPose();
}
/*!
   \param konum Pose argument
   \set position of the robot
*/
void RobotControl::setPose(Pose konum) {

	robotAPI->setPose(konum);
}
/*!
	\stop turning robot
*/
void RobotControl::stopTurn() {
	robotAPI->stopTurn();
}
/*!
  \stop moving robot
*/
void RobotControl::stopMove() {
	robotAPI->stopMove();
}
/*!
	@return bool 
	\robot's pose added to path
*/
bool RobotControl::addToPath() {
	Pose konum = robotAPI->getPose();
	path->addPos(konum);
	if (path != NULL)
	{
		return true;
	}
	else false;
}
/*!
	@return bool
	\robot's path cleared
*/
bool RobotControl::clearPath() {

	path->clearPATH();
	if (path == NULL)
		return true;
	else
		return false;
}
/*!
	@return bool
	\Provides access to functions if password is correct
*/
bool RobotControl::openAccess() {

	int password;
	cout << "Enter the password(" << operat.getAccessCode() << "): ";
	cin >> password;
	if (operat.checkAccessCode(password))
		return 1;
	return 0;
}
/*!
	@return bool
	\closes access to functions
*/
bool RobotControl::closeAccess() {

	int password;
	cout << "Enter the password(" << operat.getAccessCode() << "): ";
	cin >> password;
	if (operat.checkAccessCode(password))
		return 1;
	return 0;
}
/*!
	@return bool
	\the path followed by the robot is printed on the file
*/
bool RobotControl::recordPathtoFile() {

	int cou = 0;
	rec.setFileName("Output.txt");
	rec.openFile();

	for (int i = 1; i <= (*path).number; i++) {

		if (rec.writeLine(to_string(path->getPos(i).getX()) + " " + to_string(path->getPos(i).getY()) + " " + to_string(path->getPos(i).getTh())))
			cou++;
		rec.writeLine("\n");
	}

	if (cou != 0)
		return 1;
	return 0;
}
/*!
	\get sensor informations from PioneerRobotAPI class.
*/
void RobotControl::sonarSENSOR() {
	
	robotAPI->updateSensor();
	cout << "Sonar ranges [ ";
	for (int i = 0; i < 16; i++) {
		cout << SonarSensor::RANGES[i] << " ";
	}
	cout << "]" << endl;

}
/*!
	\get sensor informations from PioneerRobotAPI class.
*/
void RobotControl::laserSENSOR() {
	robotAPI->updateSensor();
	cout << "Laser ranges are [ ";

	for (int i = 0; i < 181; i++) {
		cout << LaserSensor::RANGES[i]<< " ";

	}
	cout << "]" << endl;
}

