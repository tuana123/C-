#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
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
void SaveToFile(string filename);
void LoadFromFile(string fileName);
void Replace(string &str, char to, char by);

void Menu()
{
	int c;
	cout << "------------------MENU------------------" << endl ;
	cout << "    1. Input" << endl;
	cout << "    2. Display" << endl;
	cout << "    3. Save to file" << endl;
	cout << "    4. Load from file" << endl;
	cout << "    Press Something Key To Exit" << endl;
	cout << "----------Press Your Chosse-------------" << endl;
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
			SaveToFile("studen.txt");
			break;
		case 4:
			LoadFromFile("student.txt");
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
	system("cls");
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
	system("cls");
	cout << " ID" << setw(20) << "Name" << setw(20) << "Score" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << " " << (p + i)->id << setw(20) << (p + i)->name << setw(20) << (p + i)->score << endl;
	}
	Menu();
}

void SaveToFile(string filename)
{
	ofstream outFile;
	outFile.open(filename);
	if (outFile.is_open())
	{
		//save number
		outFile << n << endl;
		for (int i = 0; i < n; i++)
		{
			int id = p[i].id;
			string name = p[i].name;
			float score = p[i].score;
			Replace(name, ' ', '_');
			outFile << id << " " << name << " " << score << endl;
		}

		cout << "Save to " << filename << endl;

		outFile.close();
	}
	else
	{
		cout << "ERROR" << endl;
	}
	Menu();
}

void LoadFromFile(string fileName)
{
	ifstream inFile;
	inFile.open("student");

	if (inFile.is_open())
	{
		inFile >> n;

		for (int i = 0; i < n; i++)
		{
			inFile >> p[i].id;
			inFile >> p[i].name;
			inFile >> p[i].score;
			Replace(p[i].name, '_', ' ');
		}
		inFile.close();
	}
	else
	{
		cout << "LOAD ERROR" << endl;
	}
	Menu();
}

void Replace(string &str, char to, char by)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == to)
		{
			str.at(i) = by;
		}
	}
}


int main()
{
	Menu();
	
	return 0;
}