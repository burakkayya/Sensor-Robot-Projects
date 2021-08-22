#include"Pose.h"
#include<math.h>
#define PI 3.14159265

Pose::Pose()
{
	this->x = 0;
	this->y = 0;
	this->th = 0;
}
float Pose::getX() {
	return this->x;
}
void Pose::setX(float _x) {
	this->x = _x;
}
float Pose::getY() {
	return this->y;
}
void Pose::setY(float _y) {
	this->y = _y;
}
float Pose::getTh() {
	return this->th;
}
void Pose::setTh(float _th) {
	this->th = _th;
}
void Pose::getPose(float& _x, float& _y, float& _th) {
	x = _x;
	y = _y;
	th = _th;
}
void Pose::setPose(float _x, float _y, float _th) {
	this->x = _x;
	this->y = _y;
	this->th = _th;
}
float Pose::findDistanceTo(Pose pos) {
	float d = 0,distance=0;
	d = pow(x - pos.x, 2) + pow(y - pos.y, 2);
	distance = pow(d,0.5);

	return distance;
}
float Pose::findAngleTo(Pose pos) {
	float param=0,result=0;
	param = (y - pos.y) / (x - pos.x);
	result = atan(param) * 180 / PI;
	return 180.0-result;
}
bool Pose::operator==(const Pose& other) { // açýya bakmalý mý
	if (x==other.x && y==other.y && th==other.th)
	{
		return true;
	}
	return false;
}
Pose Pose::operator+(const Pose& other) {
	Pose p;
	float t;
	p.x = x + other.x;
	p.y = y + other.y;
	//float uv = (x * other.x) + (y * other.y);     // u.v
	//float uu = pow((pow(x, 2) + pow(y, 2)),0.5) * pow((pow(other.x, 2) + pow(other.y, 2)),0.5);
	////p.th = (acos(uv/uu) * 180 / PI);
	p.th= atan(p.y/p.x) * 180 / PI;
	return p;
}
Pose Pose::operator-(const Pose& other) {
	Pose p;
	p.x = x - other.x;
	p.y = y - other.y;
	p.th = atan(p.y / p.x) * 180 / PI;

	return p;

}
Pose& Pose::operator+=(const Pose& other) {
	x = x + other.x;
	y = y + other.y;
   th = atan(y /x) * 180 / PI;

	return *this;
}
Pose& Pose::operator-=(const Pose& other) {
	x = x - other.x;
	y = y - other.y;
	th = atan(y / x) * 180 / PI;

	return *this;
}
bool Pose::operator<(const Pose& other) {
	float b = pow(x, 2) + pow(y, 2);
	float b1 = pow(other.x, 2) + pow(other.y, 2);
	if (b < b1)
	{
		return true;
	}
	else
		return false;
}