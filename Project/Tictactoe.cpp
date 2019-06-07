#include <iostream>
#define n 3
#define MAX_NAME_LENGTH     50
using namespace std;
int win = 0, m[3][3];
char player1[MAX_NAME_LENGTH], player2[MAX_NAME_LENGTH];

int CheckCloumn()
{
	for (int i = 0; i<n; i++)
	{
		int count = 0;
		for (int j = 0; j<n - 1; j++)
		{
			if (m[j][i] == m[j + 1][i] && m[j][i] != 0)
				count++;
		}
		if (count == n - 1)
			return 1;
	}
	return 0;
}

int CheckRow()
{
	for (int i = 0; i<n; i++)
	{
		int count = 0;
		for (int j = 0; j<n - 1; j++)
		{
			if (m[i][j] == m[i][j + 1] && m[i][j] != 0)
				count++;
		}
		if (count == n - 1)
			return 1;
	}
	return 0;
}

int CheckDiagonal1()
{
	for (int i = 0; i<n - 1; i++)
	{
		if (m[i][i] != m[i + 1][i + 1] || m[i][i] == 0)
			return 0;
	}
	return 1;
}

int CheckDiagonal2()
{
	for (int i = 0; i<n - 1; i++)
	{
		if (m[i][n - 1 - i] != m[i + 1][n - 1 - i - 1] || m[i][n - 1 - i] == 0)
			return 0;
	}
	return 1;
}

int CheckDraw()
{
	for (int j = 0; j<n; j++)
	{
		for (int k = 0; k<n; k++)
		{
			if (m[j][k] == 0)
				return 0;
		}
	}
	return 1;
}

int CheckPlayer(int a, int b)
{
	int i = a / 10, j = a % 10;
	m[i][j] = b;
	if (CheckCloumn() == 1 || CheckRow() == 1 || CheckDiagonal1() == 1 || CheckDiagonal2() == 1)
	{
		return 1;
	}
	return 0;
}

void PrintArray()
{
	cout << "   " << 0 << "   " << 1 << "   " << 2 << endl;
	for (int i = 0; i<n; i++)
	{
		cout << i << "| ";
		for (int j = 0; j<n; j++)
		{
			//			cout << m[i][j];
			if (m[i][j] == 1)
				cout << "X";
			else if (m[i][j] == 2)
				cout << "O";
			else cout << " ";
			cout << " | ";
		}
		cout << endl;

	}
}

void Play()
{
	while (1)
	{
		int a, j = 0;
		cout << "Your Turn " << player1 << " " << j << ": ";
		turn1:cin >> a;
		if (a / 10 >= n || a % 10 >= n)
		{
			cout << "Out of Control" << endl;
			cout << "Please Write Again";
			goto turn1;
		}
		else if (m[a / 10][a % 10] != 0)
		{
			cout << "Duplication" << endl;
			cout << "Please Write Again";
			goto turn1;
		}
		win = CheckPlayer(a, 1);
		PrintArray();
		if (win == 1)
		{
			cout << "Player " << player1 << " Win!!!";
			break;
		}
		if (CheckDraw())
		{
			cout << "DRAW";
			break;
		}
		cout << "Your Turn " << player2 << " " << j << ": ";
		turn2: cin >> a;
		if (a / 10 >= n || a % 10 >= n)
		{
			cout << "Out of Control" << endl;
			cout << "Please Write Again";
			goto turn2;
		}
		else if (m[a / 10][a % 10] != 0)
		{
			cout << "Duplication" << endl;
			cout << "Please Write Again";
			goto turn2;
		}
		win = CheckPlayer(a, 2);
		PrintArray();
		if (win == 1)
		{
			cout << "Player " << player2 << " Win!!!";
			break;
		}
		if (CheckDraw())
		{
			cout << "DRAW";
			break;
		}
		j++;
	}
}

int main()
{
	cout << "Welcome To Tic-tac-toe game! Play with your way!" << endl;
	cout << "If you find any problem, please contact minhtuanapro@gmail.com" << endl;
	cout << "SELECT YOUR MODE (1 - PLAY GAME, OTHERS - EXIT GAME):" << endl;
	int i;
	cin >> i;
	if (i == 1)
	{
		cout << "Enter Name Player 1: ";
		cin.getline(player1, MAX_NAME_LENGTH);
		cout << "Enter Name Player 2: ";
		cin.getline(player2, MAX_NAME_LENGTH);
		cout << "      START" << endl;
		cout << "<===============>" << endl;
		for (int j = 0; j<n; j++)
		{
			for (int k = 0; k<n; k++)
			{
				m[j][k] = 0;
			}
		}
		PrintArray();
		Play();
	}
	return 0;
}