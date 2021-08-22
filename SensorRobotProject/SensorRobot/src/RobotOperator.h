/**
 * @file   RobotOperator.h
 * @Author Melisa ÖZEL (melisaozzel@gmail.com)
 * @date   January, 2021
 * @brief  This file is about operator's information, access state of operator and calling encryption process.
 *
 *
 */

#pragma once
#include "Aria/Aria.h"
#include <iostream>
#include<string.h>
#include "Encryption.h"
using namespace std;

class RobotOperator
{
private:
	string name;
	string surname;
	unsigned int  accessCode;
	unsigned int Code;
	bool accessState;
	Encryption encryption;
public:
	RobotOperator(); /*!< RobotOperator Constructor */
	int encryptCode(int); /*!< encrypt code */
	int descryptCode(); /*!< descrypt code */
	bool checkAccessCode(int); /*!< control accessing */
	void print(); /*!< print information of operator and access state */
	unsigned int getAccessCode(); /*!< get access code */
};

