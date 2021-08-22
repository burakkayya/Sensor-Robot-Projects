///**
// * @file   RangeSensor.h
// * @Author Eþref Burak KAYA (ebkaya.0637@gmail.com)
// * @Author Melisa ÖZEL(melisaozzel@gmail.com)
// * @date   January, 2021
// * @brief  This file is about Laser data and it's information.
// *
// * 
// */
#pragma once
#include<stdio.h>
#include "Aria/Aria.h"
#include<stdlib.h>
#include "PioneerRobotAPI.h"
using namespace std;

class RangeSensor
{
public:
	float Ranges[999];
	PioneerRobotAPI* robotAPI;

	virtual float getRange(int) = 0;/*!< get value of array element */
	virtual float getMax(int&) = 0;/*!< get max value of array elements */
	virtual float getMin(int&) = 0;/*!< get min value of array elements */
	virtual void updateSensor(float[]) = 0;/*!< copy all elements of array to another array */
	virtual float& operator[](int) = 0;/*!< get value of array element */
	virtual float getAngle(int) = 0;/*!< get angle of array element */
	virtual float getClosestRange(float, float, float&) = 0;/*!< get min value of array between two angle */
};