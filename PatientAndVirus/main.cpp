//#include "MyVirus.h"
#include <iostream>
#include <fstream>
#include "Patient.h"
#include "vld.h"
using namespace std;
void main()
{
	Patient p;
	int t = 0;
	while (p.GetState() == 1)
	{
		cout << "Take Medicine (0 = NO, 1 = YES)" << endl;
		cin >> t;
		if (t == 1)
		{
			int min = 1;
			int max = 2;
			int medicine_resistance = min + (rand() % (int)(max - min + 1));
			cout << "Medicine: " << medicine_resistance << endl;
			p.TakeMedicine(medicine_resistance);
		}
	}
	system("pause");
}