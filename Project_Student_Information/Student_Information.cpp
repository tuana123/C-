#include <iostream>
#include <string>
using namespace std;

struct Student
{
	int id;
	string name;
	float score;
};

int n;
Student *array_student = new Student[n];

void Input(){}
int Check_ID(int id){}

int Check_ID(int id)
{
	for (int i = 0; i < n; i++)
	{
		if (id == array_student[i].id)
		{
			return 0;
		}
	}
	return 1;
}

void Input()
{
	int id;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter Student ID: ";
		t: cin >> id;
		cin.ignore;
		if (Check_ID(id))
		{
			array_student[i].id = id;
			cout << "Enter Student Name: ";
			getline(cin, array_student[i].name);
			cout << "Enter Student Score: ";
			cin >> array_student[i].score;
		}
		else
		{
			cout << "Duplication Student ID!!!" << endl;
			cout << "Please Enter Again: ";
			goto t;
		}
	}
}

int main()
{

}