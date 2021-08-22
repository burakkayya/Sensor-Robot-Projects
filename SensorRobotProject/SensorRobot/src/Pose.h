#pragma once
class Pose
{
private:
	float x;
	float y;
	float th;
public:
	Pose();
	float getX();
	void setX(float);
	float getY();
	void setY(float);
	float getTh();
	void setTh(float);
	bool operator==(const Pose& other);
	Pose operator+(const Pose& other);
	Pose operator-(const Pose& other);
	Pose& operator+=(const Pose& other);
	Pose& operator-=(const Pose& other);
	bool operator<(const Pose& other);
	void getPose(float& _x, float& _y, float& _th);
	void setPose(float _x, float _y, float _th);
	float findDistanceTo(Pose pos);
	float findAngleTo(Pose pos);

};