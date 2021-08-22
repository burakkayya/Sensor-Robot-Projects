#include"Pose.h"
#include"PioneerRobotAPI.h"
#include"RobotInterface.h"
#include"PioneerRobotInterface.h"
#include<iostream>
#include<stdio.h>
/**
 * @file PioneerRobotInterface.test
 * @Author Melih Bucak (bckmelih@gmail.com)
 * @date ,January 2021
 * @brief this class is for test purpose.
 *
 */
using namespace std;

int main() {
	PioneerRobotInterface interfaceNesnesi;
	RobotInterface& base = interfaceNesnesi;
	PioneerRobotAPI *robot;
	robot = new PioneerRobotAPI;
	robot->connect();//robot connection
	cout << "-------------- ROBOTINTERFACE TEST--------------\n";
	
	cout << "Robot moves forward!\n";
	base.forward(100);//move forward
	cout << "Robot moves backward!\n";
//	base.backward(-200);//move backward
	base.print();
	cout << "Robot turns right!\n";
	base.turnRight();
//	cout << "Robot turns left!\n";
//	base.turnLeft();
	cout << "send the sensor informations to the LaserSensor class' update method\n";
	base.updateSensor();
	base.getPose();
//	cout << "Robot stops turnning" << endl;
//	base.stopTurn();
	//cout << "Robot stops moving" << endl;
	//base.stopMove();
	cout << endl << endl;
	system("pause");
}