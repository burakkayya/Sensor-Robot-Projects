/**
 * @file   Record.h
 * @Author Eþref Burak KAYA (ebkaya.0637@gmail.com) -- Melisa ÖZEL (melisaozzel@gmail.com)
 * @date   January, 2021
 * @brief  This file is about file process and getting pose values then printing.
 *
 *
 */
#include "Record.h"
#include "Pose.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<fstream>
#include<iostream>

using namespace std;

//! Constructor
Record::Record() 
{
	
}

/*!
	\return true if file opened otherwise false.
*/
bool Record::openFile() 
{

	file.open(fileName , ios::out);
	if (file)
		return 1;
	else
		return 0;
}

/*!

	\return true if file closed otherwise false.
*/
bool Record::closeFile() 
{

	file.close();
	if (!file)
		return 1;
	else
		return 0;
}

/*!
 \param filename a string argument.
	\return nothing
*/
void Record::setFileName(string filename) 
{
	fileName = filename;
}

/*!
	\return str, is read line.
*/
string Record::readLine() 
{

	file.close();
	file.open(fileName, ios::in);

	string str = "";
	getline(file, str);
	return str;
}

/*!
 \param satir a string argument.
	\return true if line is written otherwise false.
*/
bool Record::writeLine(string satir) 
{

	file.close();
	file.open(fileName, ios::app);

	if (file.is_open()) {
		file << satir << endl;
		return 1;
	}
	else
		return 0;
}

/*!
 \param o an ostream argument.
 rec a const record argument.
	\return o, printed line.
*/
ostream& operator<<(ostream& o , Record& rec) 
{
	rec.file.close();
	rec.file.open(rec.fileName, ios::in);

	string str = "";
	while(getline(rec.file, str))
	o << str<<endl;

	return o;
}

/*!
 \param i an istream argument.
 rec a const record argument
	\return i, taken values.
*/
istream& operator>>(istream& i , Record& rec) 
{
	
		rec.file.close();
		rec.file.open(rec.fileName, ios::app);

		string str;
		
		i.ignore();
		getline(i , str);
		rec.file << str << endl;
		
	return i;
}