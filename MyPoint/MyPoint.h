#pragma once

class MyPoint
{
private:
	int mPosX;
	int mPosY;
public:
	MyPoint();
	~MyPoint();
	MyPoint(int,int);
	void Display();
	void SetX(int);
	void SetY(int);
	int GetX();
	int GetY();
	double Distance(MyPoint *p);
};
