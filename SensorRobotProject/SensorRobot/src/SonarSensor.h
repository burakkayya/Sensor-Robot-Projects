
/**
 * @file   SonarSensor.h
 * @Author Melisa ÖZEL (melisaozzel@gmail.com)
 * @date   January, 2021
 * @brief  This file is about Sonar data and it's information.
 *
 *
 */

#pragma once
#include<stdio.h>
#include "Aria/Aria.h"
#include<stdlib.h>
#include "PioneerRobotAPI.h"
#include"RangeSensor.h"
using namespace std;

class SonarSensor : public RangeSensor
{
public:
	static float RANGES[16];
	SonarSensor(); /*!< SonarSensor Constructor */
	float getRange(int); /*!< get value of array element */
	float getMax(int&); /*!< get max value of array elements */
	float getMin(int&); /*!< get min value of array elements */
	void updateSensor(float[]); /*!< copy all elements of array to another array */
	float getAngle(int); /*!< get angle of array element */
	float getClosestRange(float, float, float&); /*!< get min value of array between two angle */
	float& operator[](int); /*!< get value of array element */

};

