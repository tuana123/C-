#include <iostream>
#define n 3
#define MAX_NAME_LENGTH     50
using namespace std;
int win = 0, m[3][3];
char player1[MAX_NAME_LENGTH], player2[MAX_NAME_LENGTH];

int CheckDraw()
{

}

int CheckPlayer(int a, int b)
{

}

void PrintArray()
{

}

void Play()
{
	while (1)
	{
		int a, j = 0;
		cout << "Your Turn " << player1 << " " << j << ": ";
		cin >> a;
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
		cin >> a;
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