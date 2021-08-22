/**
 *  @file		Node.h
 *	@Author		Melih Bucak (bckmelih@gmail.com)
 *	@date		January, 2021
 *	@brief		A header file for class Node.
 *
 *	This file consists of Node's next pointer and Pose object.
 */
#pragma once
#include"Pose.h"
struct Node
{
	Node* next;
	Pose pose;
};
