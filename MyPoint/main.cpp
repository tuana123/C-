#include "MyPoint.h"
#include <iostream>

using namespace std;

void main()
{
	int x, y;
	cout << "Enter X 1: ";
	cin >> x;
	cout << "Enter Y 1: ";
	cin >> y;
	MyPoint *p1 = new MyPoint();
	p1->SetX(x);
	p1->SetY(y);
	cout << "Point 1:" << endl;
	p1->Display();
	cout << "Enter X 2: ";
	cin >> x;
	cout << "Enter Y 2: ";
	cin >> y;
	MyPoint *p2 = new MyPoint(x,y);
	cout << "Point 2:" << endl;
	p2->Display();
	cout << "Distance Between Point 1 and Point 2: " << p1->Distance(p2) << endl;
	system("pause");
}