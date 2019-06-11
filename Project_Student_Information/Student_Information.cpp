#include <iostream>
#include <string>
#define Size_array 100
using namespace std;

struct Student
{
	int id;
	string name;
	float score;
};

Student *p = new Student[Size_array];
int n;

void Menu();
int Check_ID(int id,int size);
void Input_Student();
void Display();
void SaveToFile();
void LoadFromFile();

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
			break;
		case 2:
			Display();
			break;
		case 3:
			SaveToFile();
			break;
		case 4:
			LoadFromFile();
			break;
		default: 
			system("pause");
	}
}

int Check_ID(int id,int size)
{
	for (int i = 0; i < size; i++)
	{
		if (id == (p+i)->id)
		{
			return 0;
		}
	}
	return 1;
}

void Input_Student()
{
	int id_student;
	int number;
	cout << "--------Input Student--------" << endl;
	cout << "Enter The Number Of  Student: ";
	cin >> number;
	for (int i = n; i < n + number; i++)
	{
		cout << "Enter Student ID: ";
		t1: cin >> id_student;
		cin.ignore();
		if (Check_ID(id_student,i))
		{
			(p+i)->id = id_student;
			cout << "Enter Student Name: ";
			getline(cin, (p+i)->name);
			cout << "Enter Student Score: ";
			float sc;
			t2: cin >> sc;
			if (sc < 0 || sc >10)
			{
				cout << "Score From 0 to 10";
				cout << "Please Enter Again: ";
				goto t2;
			}
			else
			{
				(p+i)->score = sc;
			}
		}
		else
		{
			cout << "Duplication Student ID!!!" << endl;
			cout << "Please Enter Again: ";
			goto t1;
		}
		cout << "---------------------------------" << endl;
	}
	n = n + number;
	Menu();
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