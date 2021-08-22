
/**
 * @file Robotcontrol.h
 * @Author Gamze Bilmez (gamzebilmezz@gmail.com)
 * @date January, 2021
 * @brief Robot Menu app
 *
 */

#include"RobotControl.h"
#include"Pose.h"
#include<iostream>
#include<Windows.h>
#include"PioneerRobotInterface.h"
#include"RobotInterface.h"

using namespace std;
void main()
{
	RobotControl* kumanda;
	kumanda = new RobotControl;
	Pose konum;
	cout << "----------------ROBOT CONTROL--------------" << endl;
    
	kumanda->openAccess();

	kumanda->turnRight();
	Sleep(1000);
	kumanda->print();

	kumanda->forward(2000);
	Sleep(1000);

	kumanda->stopMove();
	konum = kumanda->getPose();
	kumanda->setPose(konum);
	kumanda->addToPath();

	kumanda->turnLeft();
	Sleep(1000);
	kumanda->print();

	kumanda->stopTurn();
	kumanda->print();

	kumanda->laserSENSOR();
	kumanda->sonarSENSOR();


	kumanda->backward(-100);
	Sleep(1000);
	kumanda->stopMove();
	konum = kumanda->getPose();
	kumanda->recordPathtoFile();
	kumanda->setPose(konum);
	kumanda->addToPath();
	kumanda->laserSENSOR();
	kumanda->sonarSENSOR();


	kumanda->clearPath();

	system("pause");
}