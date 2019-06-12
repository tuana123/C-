#include "MyPoint.h"
#include <iostream>

MyPoint::MyPoint()
{
	this->mPosX = 0;
	this->mPosY = 0;
}

MyPoint::MyPoint(int x, int y)
{
	this->mPosX = x;
	this->mPosY = y;
}

void MyPoint::Display()
{
	std::cout << "Value of mPosX: " << this->mPosX <<
	std::endl;
	std::cout << "Value of mPosY: " << this->mPosY <<
	std::endl;
}

void MyPoint::SetX(int x)
{
	this->mPosX = x;
}

void MyPoint::SetY(int y)
{
	this->mPosY = y;
}

int MyPoint::GetX()
{
	return this->mPosX;
}

int MyPoint::GetY()
{
	return this->mPosY;
}

double MyPoint::Distance(MyPoint *p)
{
	double a = sqrt((p->mPosX - this->mPosX)*(p->mPosX - this->mPosX) +
		(p->mPosY - this->mPosY)*(p->mPosY - this->mPosY));
	return a;
}

MyPoint::~MyPoint()
{
	
}
