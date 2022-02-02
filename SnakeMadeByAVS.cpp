
#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;
const int sizeX = 40, sizeY = 20;
int speed, appleX, appleY, snakeX, snakeY, score;
char ArrFieldSize[sizeX][sizeY];


void ArrField()
{
    //system("cls");
    for (int i = 0; i < sizeX; i++)
    {
        for (int j = 0; i < sizeY; j++)
        {
            cout << ArrFieldSize[i][j];
        }
        cout << endl;
    }
}
void GameField();




int main()
{
	appleX = rand() % sizeX;
	appleY = rand() % sizeY;
	snakeX = sizeX / 2;
	snakeY = sizeY / 2;
    setlocale(0, "");
    GameField();
}
void GameField()
{

	int aplleX = rand() % sizeX;
	int aplleY = rand() % sizeY;
	Sleep(100);    //speed of game
	system("cls");
	for (int i = 0; i < sizeX + 1; i++)
		cout << "#";
	cout << endl;

	for (int i = 0; i < sizeY; i++) {
		for (int j = 0; j <= sizeX; j++) {
			if (j == 0 || j == sizeX - 1)
				cout << "#";

			if (i == snakeY && j == snakeX)
				cout << "0";
			else if (i == appleY && j == appleX)
				cout << "F";

			/*else {
				printTail = false;
				for (int k = 0; k < nTail; k++) {
					if (tailX[k] == j && tailY[k] == i) {
						printTail = true;
						cout << "o";
					}
				}
				if (!printTail)
					cout << " ";
			}*/
			else cout << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < sizeX + 1; i++)
		cout << "#";
	cout << endl;
	//cout << "Score:" << score << endl;
}