/**
 *  @file		Path.h
 *	@Author		Melih Bucak (bckmelih@gmail.com)
 *	@Author		Gamze Bilmez (gamzebilmezz@gmail.com)
 *	@date		January, 2021
 *	@brief		A header file for class Path.
 *
 *	This file consists of below operands by using linked list.
 */
#include<iostream>
#include"Path.h"
#include"Pose.h"
using namespace std;

Path::Path() {
	this->head = NULL;
	this->tail = NULL;
	this->number = 0;
}
/*!
		\param &Obj_pose is a Pose class's object.
		\add Pose class' object at the end of the linked list node.
		\increment the number of nodes.
*/
void Path::addPos(Pose& Obj_pose) {
	Node* tmp = new Node;
	tmp->pose = Obj_pose;
	tmp->next = NULL;
	if (head == NULL) {
		head = tmp;
		tail = tmp;
	}
	else {
		tail->next = tmp;
		tail = tail->next;
	}
	this->number++;
}
/*!
		\print pose values.
*/
void Path::print()const {
	Node* p = head;
	int i = 1;
	int count = this->number;
	cout << "----------------PATH(S)----------------: " << endl;
	while (count != 0) {
		cout << "Path[" << i << "]" << "	x:" << p->pose.getX() << "	y:" << p->pose.getY() << "	th:" << p->pose.getTh() << endl;
		p = p->next;
		i++;
		count--;
	}
}
/*!
		\param index is an int argument.
		\return the pose value from the given index by using operator overloading.
*/
Pose Path::operator[](int index) {
	if (index < 1 || index > this->number) {
		cout << "Path:operator[]::OUT OF RANGE" << endl;
	}
	else
	{
		Node* p = head;
		for (int i = 1; i <= index - 1; i++)
		{
			p = p->next;
		}
		Pose p1 = p->pose;
		return p1;
	}
}
/*!
		\param index is an int argument.
		\return the pose value at the given index.
*/
Pose Path::getPos(int index) {
	if (index < 1 || index > this->number)
	{
		cout << "Path:getPos::index::OUT OF RANGE" << endl;
	}
	else {
		Node* p = head;
		int i = 0;
		while (p->next != NULL) {

			if (i == index)
				break;
			p = p->next;
			i++;
		}
		return p->pose;
	}
}
/*!
		\param index is an int argument.
		\remove the pose value from the given index.
*/
bool Path::removePos(int index) {
	if (index < 1 || index > this->number) {
		cout << "Path:removePos::OUT OF RANGE" << endl;
		return false;
	}
	Node* temp = head;
	Node* tmp = head;
	int i = 1;
	while (temp != NULL) {//find the node to be deleted

		if (i == index - 1) {//store node position at (index-1)
			tmp = temp;
		}
		if (i == index)
			break;
		temp = temp->next;
		i++;
	}
	if (temp == this->head) {//remove first node
		this->head = this->head->next;
		if (this->head == NULL) this->tail = NULL;
	}
	else if (temp == this->tail) {//remove last node
		this->tail->next = NULL;
		//return true;
	}
	else {
		tmp->next = temp->next;
	}
	this->number--;
	delete temp;
	return true;
}
/*!
		\param index is an int argument.
		\param Obj_pose is a Pose argument.
		\insert the pose value to the linked list at the given index otherwise return false.
*/
bool Path::insertPos(int index, Pose Obj_pose) {
	if (index < 0 || index >= this->number) {
		cout << "Path:insertPos::OUT OF RANGE" << endl;
		return false;
	}
	Node* temp = new Node;
	temp->pose = Obj_pose;
	temp->next = NULL;
	if (index == 0)
	{
		temp->next = head;
		head = temp;
		this->number++;
		return true;
	}
	Node* temp2 = head;
	for (int i = 0; i < index - 1; i++)
	{
		temp2 = temp2->next;
	}
	temp->next = temp2->next;
	temp2->next = temp;
	this->number++;
	return true;
}
/*!
		\param out is an ostream argument.
		\param obj is a Path argument.
		\overloading ostream operator <<
*/
ostream& operator<<(ostream& out, const Path& obj) {
	out << "Path:" << "    x:" << obj.head->pose.getX() << "    y:" << obj.head->pose.getY() << "    th:" << obj.head->pose.getTh() << endl;
	return out;
}
/*!
		\param in is an istream argument.
		\param obj is a Path argument.
		\overloading istream operator >>
*/
istream& operator>>(istream& in, Path& obj) {
	cout << "Enter position values which are x, y, th :";
	float x, y, th;
	in >> x >> y >> th;
	obj.head->pose.setX(x);
	obj.head->pose.setY(y);
	obj.head->pose.setTh(th);
	return in;
}
/*!
	\cleared the path
*/
void Path::clearPATH()
{
	Node* node = this->head;
	while (this->head)
	{
		node = this->head;
		Node* n = new Node;
		delete node;
		node = n;
		n = n->next;
	}

}