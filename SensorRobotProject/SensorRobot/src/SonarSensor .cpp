/**
 * @file   SonarSensor.h
 * @Author Melisa �ZEL (melisaozzel@gmail.com)
 * @date   January, 2021
 * @brief  This file is about Sonar data and it's information.
 *
 *
 */

#include"SonarSensor.h"
#include<stdio.h>
#pragma once
#include "Aria/Aria.h"
#include<stdlib.h>
#include "PioneerRobotAPI.h"
using namespace std;
 float SonarSensor::RANGES[16];
//! Constructor
SonarSensor::SonarSensor()
{
	robotAPI = new PioneerRobotAPI;
	if (robotAPI->connect())
		cout << "connected" << endl;
}

/*!
 \param index an integer argument.
	\return index element of array.
*/
float SonarSensor::getRange(int index)
{
	return Ranges[index];
}

/*!
 \param index an integer argument.
	\return index element's angle of array.
*/
float SonarSensor::getAngle(int index)
{
	double a��[16];
	double de�er = 50;
	a��[0] = 90;
	a��[7] = -90;
	a��[15] = 90;
	a��[8] = -90;

	for (int i = 1; i <= 6; i++)
	{
		a��[i] = de�er;
		de�er -= 20;
	}
	de�er = 50;
	for (int i = 9; i <= 14; i++)
	{
		a��[i] = de�er;
		de�er -= 20;
	}

	return a��[index];
}

/*!
 \param index an integer argument.
	\return maximum value of array elements.
*/
float SonarSensor::getMax(int& index)
{
	float max = Ranges[0];
	int maxindex;

	for (int i = 1; i < 16; i++)
	{
		if (Ranges[i] >= max)
		{
			max = Ranges[i];
			maxindex = i;
		}

	}
	index = maxindex;
	return max;

}

/*!
 \param index an integer argument.
	\return min value of array elements.
*/
float SonarSensor::getMin(int& index)
{
	float min = Ranges[0];
	int minindex;

	for (int i = 1; i < 16; i++)
	{
		if (Ranges[i] <= min)
		{
			min = Ranges[i];
			minindex = i;
		}

	}
	index = minindex;
	return min;

}

/*!
 \param ranges[] an array argument.
	\return nothing
*/
void SonarSensor::updateSensor(float ranges[])
{
	//robotAPI->getSonarRange(this->Ranges);

	int i;
	for (i = 0; i < 16; i++)
	{
		this->RANGES[i] = ranges[i];
	}
}

/*!
 \param i an integer argument.
	\return index element of array.
*/
float& SonarSensor::operator[](int i)
{
	return this->Ranges[i];

}


/*!
 \param startAngle a float argument.
 \ endAngle a float argument.
 \ angle a float argument.
	\return min value of array between startAngle endAngle.
*/
float SonarSensor::getClosestRange(float startAngle, float endAngle, float& angle)
{

	float min = Ranges[(int)startAngle];
	int indexHolder = (int)startAngle;

	for (float i = startAngle + 1.0; i < endAngle; i++) {

		if (Ranges[(int)i] < min) {
			min = Ranges[(int)i];
			indexHolder = (int)i;
		}

	}
	double a��[16];
	double de�er = 50;
	a��[0] = 90;
	a��[7] = -90;
	a��[15] = 90;
	a��[8] = -90;

	for (int i = 1; i <= 6; i++)
	{
		a��[i] = de�er;
		de�er -= 20;
	}
	de�er = 50;
	for (int i = 9; i <= 14; i++)
	{
		a��[i] = de�er;
		de�er -= 20;
	}
	angle = a��[indexHolder];
	return Ranges[indexHolder];


}