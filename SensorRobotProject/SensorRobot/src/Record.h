/**
 * @file   Record.h
 * @Author Eþref Burak KAYA (ebkaya.0637@gmail.com) -- Melisa ÖZEL (melisaozzel@gmail.com)
 * @date   January, 2021
 * @brief  This file is about file process and getting pose values then printing.
 *
 *
 */

#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<fstream>
#include<iostream>
#include "Pose.h"

using namespace std;

class Record
{
private:
	string fileName;
	fstream file;


public:
	Record(); /*!< Record Constructor */
	bool openFile(); /*!< opens file */
	bool closeFile(); /*!< closes file */
	void setFileName(string); /*!< takes name of file */
	string readLine(); /*!< reads a line */
	bool writeLine(string); /*!< writes a line */
	friend ostream& operator<<(ostream& , Record &); /*!< prints pose values */
	friend istream& operator>>(istream& , Record &); /*!< takes pose values */

};

