
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

const int sizeX = 30, sizeY = 15;
int speed, appleX, appleY, snakeX, snakeY, score, prevX, prevY;
bool endGame;
//int tailArr[sizeX],tailArr2[sizeY];
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Setup() {
	srand(time(0));
	endGame = true;
	//dir = STOP;
	snakeX = sizeX / 2;
	snakeY = sizeY / 2;
	appleX = rand() % sizeX;
	appleY = rand() % sizeY;
	score = 0;	
}


void GameField()
{
	Sleep(400);    //speed of game
	system("cls");
	for (int i = 0; i < sizeX + 1; i++)
		cout << "#";
	cout << endl;
	for (int i = 0; i < sizeY; i++) {
		for (int j = 0; j <= sizeX; j++) {
			if (j == 0 || j == sizeX)
				cout << "0";

			else if (i == snakeY && j == snakeX)
				cout << "S";
			else if (i == appleY && j == appleX)
				cout << "@";

			else if (prevX == j && prevY == i)
				cout << "o";
			else cout << " ";
			
		}
		cout << endl;
	}
	for (int i = 0; i < sizeX + 1; i++)
		cout << "#";
	cout << endl;
	cout << "Score:" << score << endl;
}

void Input() {
	if (_kbhit()) {
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			endGame = false;
			break;
		case 'A':
			dir = LEFT;
			break;
		case 'D':
			dir = RIGHT;
			break;
		case 'W':
			dir = UP;
			break;
		case 'S':
			dir = DOWN;
			break;
		case 'X':
			endGame = false;
			break;
		}
	}
}

void Logica()
{
	prevX = snakeX;
	prevY = snakeY;
	//int prev2X, prev2Y;
	//tailArr[0] = snakeX;
	//tailArr2[0] = snakeY;
	switch (dir)
	{
	case LEFT:
		snakeX--;
		break;

	case RIGHT:
		snakeX++;
		break;

	case UP:
		snakeY--;
		break;

	case DOWN:
		snakeY++;
		break;

	}
	if (snakeX >= sizeX)
		snakeX = 0;
	else if (snakeX < 0)
		snakeX = sizeX - 1;

	if (snakeY >= sizeY)
		snakeY = 0;
	else if (snakeY < 0)
		snakeY = sizeY - 1;

	if (snakeX == appleX && snakeY == appleY)
	{
		score += 10;
		appleX = rand() % sizeX;
		appleY = rand() % sizeY;
	}
}





int main()
{
	setlocale(0, "");
	
	Setup();
	while (endGame)
	{
		GameField();
		Input();
		Logica();
	}

	cout << "¬аш счЄт = " << score << endl;
	system("pause");

	return 0;
}