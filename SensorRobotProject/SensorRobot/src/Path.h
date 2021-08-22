#pragma once
/**
 *  @file		Path.h
 *	@Author		Melih Bucak (bckmelih@gmail.com)
 *	@Author		Gamze Bilmez (gamzebilmezz@gmail.com)
 *	@date		January, 2021
 *	@brief		A header file for class Path.
 *
 *	This file consists of below operands by using linked list.
 */
#include <iostream>
#include"Node.h"
#include"Pose.h"
using namespace std;
class Path
{
public:
	void clearPATH();//cleared the path
	void addPos(Pose&);//add pose to the node by using linked list
	void print()const;//print nodes' pose by using linked list
	Pose operator[](int);//[] operator overloading
	Pose getPos(int);//return a pose node with an index
	bool removePos(int index);//remove a pose from linked list 
	bool insertPos(int index, Pose pose);//insert a pose with an index to the node by using linked list
	friend ostream& operator<<(ostream&, const Path&);//cout << operator overloading
	friend istream& operator>>(istream&, Path&); //cin >> operator overloading
	Path(); //constructor 
	int number; //number of nodes
private:
	Node* tail;
	Node* head;
};

