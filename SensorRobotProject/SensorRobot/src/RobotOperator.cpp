/**
 * @file   RobotOperator.h
 * @Author Melisa ÖZEL (melisaozzel@gmail.com)
 * @date   January, 2021
 * @brief  This file is about operator's information, access state of operator and calling encryption process.
 *
 *
 */

#include "RobotOperator.h"
#include "Encryption.h"

//! Constructor
RobotOperator::RobotOperator()
{
	accessState = 0;
	cout << "ENTER NAME:";
	cin >> name;
	cout << "ENTER SURNAME:";
	cin >> surname;
	cout << "ENTER CODE:";
	cin >> Code;
	accessCode = encryptCode(Code);

}

/*!
\param x an integer argument.
   \return encrypted code.
*/
int RobotOperator::encryptCode(int x)
{
	return encryption.encrypt(x);
}

/*!
   \return descrypted version of accesscode.
*/
int RobotOperator::descryptCode()
{
	return encryption.decrypt(accessCode);
}

/*!
\param x an integer argument.
   \return true if accesscode equal x otherwise false.
*/
bool RobotOperator::checkAccessCode(int x)
{
	if (accessCode == x)
	{
		accessState = 1;
		return 1;
	}
	else return 0;
}

//! prints operator information and access state.
void RobotOperator::print()
{
	cout << "NAME: " << name << endl;
	cout << "SURNAME: " << surname << endl;
	cout << "ACCESS CODE: " << accessCode << endl;
	if (accessState == 1) cout << "CAN ACCESS" << endl;
	else cout << "CANNOT ACCESS" << endl;
}

unsigned int RobotOperator::getAccessCode() {

	return accessCode;
}