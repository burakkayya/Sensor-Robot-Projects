///**
// * @file   LaserSensor.h
// * @Author Eþref Burak KAYA (ebkaya.0637@gmail.com)
// * @date   January, 2021
// * @brief  This file is about Laser data and it's information.
// *
// * 
// */
#include "LaserSensor.h"
#include<stdio.h>
#pragma once
#include "Aria/Aria.h"
#include<stdlib.h>
#include "PioneerRobotAPI.h"
#include"RangeSensor.h"
#include"PioneerRobotInterface.h"

using namespace std;
float LaserSensor::RANGES[181] = { NULL };
//! Constructor
LaserSensor::LaserSensor()
{
	robotAPI = new PioneerRobotAPI;

	if (!robotAPI->connect()) {
		cout << "Could not connect..." << endl;
	}
	else
		cout << "Could connect..." << endl;


}

/*!
 \param ranges[] an array argument.
	\return nothing
*/
void LaserSensor::updateSensor(float ranges[])
{
	//robotAPI->getLaserRange(this->Ranges);
	int i;
	for (i = 0; i < 181; i++) {
		this->RANGES[i] = ranges[i];
	}
}
/*!
 \param index an integer argument.
	\return maximum value of array elements.
*/
float LaserSensor::getMax(int& index)
{

	float max = Ranges[0];
	int indexHolder = 0;

	for (int i = 0; i < 181; i++) {
		if (max < Ranges[i]) {
			max = Ranges[i];
			indexHolder = i;
		}
	}
	index = indexHolder;
	return max;
}

/*!
 \param index an integer argument.
	\return min value of array elements.
*/
float LaserSensor::getMin(int& index)
{
	float min = Ranges[0];
	int indexHolder = 0;

	for (int i = 0; i < 181; i++) {
		if (min > Ranges[i]) {
			min = Ranges[i];
			indexHolder = i;
		}
	}
	index = indexHolder;
	return min;
}

/*!
 \param index an integer argument.
	\return index element of array.
*/
float LaserSensor::getRange(int index)
{
	return Ranges[index];
}

/*!
 \param index an integer argument.
	\return index element's angle of array.
*/
float LaserSensor::getAngle(int index)
{
	return index;
}

/*!
 \param i an integer argument.
	\return index element of array.
*/
float& LaserSensor::operator[](int i)
{

	return Ranges[i];

}

/*!
 \param startAngle a float argument.
 \ endAngle a float argument.
 \ angle a float argument.
	\return min value of array between startAngle endAngle.
*/
float LaserSensor::getClosestRange(float startAngle, float endAngle, float& angle)
{

	float min = Ranges[(int)startAngle];
	int indexHolder = (int)startAngle;

	for (float i = startAngle + 1.0; i < endAngle; i++) {

		if (Ranges[(int)i] < min) {
			min = Ranges[(int)i];
			indexHolder = (int)i;
		}

	}
	angle = indexHolder;
	return Ranges[indexHolder];

}
