
#include "LaserSensor.h"
#include "PioneerRobotAPI.h"
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {


	float range[181];

	LaserSensor lasersensor;
	RangeSensor& base = lasersensor;

	/*base = &lasersensor;*/
	
	base.updateSensor(range);

	cout << "------------------LASERSENSOR---------------------------" << endl;
	cout << "Laser ranges are [ ";

	for (int i = 0; i < 181; i++) {
		cout << range[i] << " ";
		
	}
	cout << "]" << endl;


	int indexmin=-1, indexmax=-1;

	base.getMax(indexmax);
	cout << "getMax (index): " << indexmax << endl;
	cout << "getMax : " << base.getMax(indexmax) << endl;
	base.getMin(indexmin);
	cout << "getMin (index): " << indexmin << endl;
	cout << "getMin : " << base.getMin(indexmin) << endl;

	cout << "Sensor 178 range: " << base.getRange(181) << endl;

	cout << "Sensor 1 angle: " << base.getAngle(1) << endl;

	cout << "Sensor 2: " << range[2] << endl;

	float ang;
	cout << "Closest Range (2,5): " << base.getClosestRange(2, 5, ang) << endl;
	cout << "Closest Range s angle: " << ang << endl;

	range[5];

	cout << "-------------------LASERSENSOR--------------------------" << endl;
}