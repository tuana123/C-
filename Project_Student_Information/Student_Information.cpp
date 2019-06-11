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

void Input_Student();
int Check_ID(int id);
void Display();
void SaveToFile();
void LoadFromFile();
void Menu();

void Menu()
{
	int c;
	cout << "------------MENU------------" << endl ;
	cout << "    1. Input" << endl;
	cout << "    2. Display" << endl;
	cout << "    3. Save to file" << endl;
	cout << "    4. Load from file" << endl;
	cout << "    Press Something Key To Exit" << endl;
	cin >> c;
	switch (c)
	{
		case 1: 
			Input_Student();
			system("clrs");
			break;
		case 2:
			Display();
			system("clrs");
			break;
		case 3:
			SaveToFile();
			system("clrs");
			break;
		case 4:
			LoadFromFile();
			system("clrs");
			break;
		default: 
			system("pause");
	}
}

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

void Input_Student()
{
	int id;
	cout << "--------Input Student--------" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter Student ID: ";
		t: cin >> id;
		cin.ignore();
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

void Display()
{

}

void SaveToFile()
{

}

void LoadFromFile()
{

}

int main()
{
	Menu();
	return 0;
}