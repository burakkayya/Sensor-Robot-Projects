
#pragma once
#include"SonarSensor.h"
#include<stdio.h>
#include "Aria/Aria.h"
#include<stdlib.h>
#include "PioneerRobotAPI.h"
#include"RangeSensor.h"

using namespace std;

int main()
{
	int x;
	int y;
	float ranges[16];

	SonarSensor sonarsensor;

	RangeSensor* base;
	base = &sonarsensor;

	base->updateSensor(ranges);

	/* Sonarsensor->updateSensor(ranges); */
		//test[1]->updateSensor(ranges);
		cout << "Sonar ranges [ ";
	for (int i = 0; i < 16; i++) {
		cout << ranges[i] << " ";
	}
	cout << "]" << endl;
	cout << "5.indexteki sensor degeri: " << base->getRange(5) << endl;
	cout << "1.indexteki sensorun aci degeri: " << base->getAngle(1) << endl;
	cout << "5.indexteki sensorun aci degeri: " << base->getAngle(5) << endl;
	cout << "13.indexteki sensorun aci degeri: " << base->getAngle(13) << endl;
	cout << "6.indexteki sensorun aci degeri: " << base->getAngle(6) << endl;
	cout << "12.indexteki sensorun aci degeri: " << base->getAngle(12) << endl;
	cout << "Maksimum mesafe degeri: " << base->getMax(x) << endl;
	cout << "Maksimum mesafe degerinin indisi: " << x << endl;
	cout << "Minimum mesafe degeri: " << base->getMin(y) << endl;
	cout << "Minimum mesafe degerinin indisi: " << y << endl;
	cout << "Ranges[6]: " << ranges[6] << endl;
	float ang;
	cout << "Closest Range (2,11): " << base->getClosestRange(2, 11, ang) << endl;
	cout << "Closest Range s angle: " << ang << endl;

	system("pause");
}
