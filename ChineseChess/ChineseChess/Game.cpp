#include "Game.h"

// ��L���y�X
// �W:		72
// �U:		80
// ��:		75
// �k:		77
// <:		44
// >:		46
// Enter:	13
// Esc:		27

// ��l��&�ŧi Game.h �̪� extern string [gameMenu]
#ifdef _GAME_MENU_
string gameMenu[5] = {
	"�סססססססססססססססס�",
	"���@�@�@�@�@���}�l�C���@�@�@�@�@��",
	"�סססססססססססססססס�",
	"���@�@�@�@�@�@�����{���@�@�@�@�@��",
	"�סססססססססססססססס�"
};
#endif // _GAME_MENU_


Game::Game()
{
	cursorPosition.X = 0;	cursorPosition.Y = 0;
	//system("cls");
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//SMALL_RECT windowSize = { 0,0,33, 20 };
	//SetConsoleWindowInfo(handle, TRUE, &windowSize);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

Game::~Game()
{

}

void Game::showMenu() {

	// ��ܿ�XMenu���e
	for (int i = 0; i < (sizeof(gameMenu) / sizeof(gameMenu[0])); i++)
		cout << gameMenu[i] << endl;
	
	// �]�w��l���Ц�m
	int commandPress = 0, y = 1;
	cursorPosition.X = 14;	cursorPosition.Y = 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

	// �]�m�����j�p
	SMALL_RECT windowSize = { 0,0,34, 4 };
	SetConsoleWindowInfo(handle, TRUE, &windowSize);

	// ���å���
	GetConsoleCursorInfo(handle, &cci);
	cci.bVisible = false;
	SetConsoleCursorInfo(handle, &cci);

	// ���б���
	while (commandPress =_getch())
	{
		if (commandPress == 72)	y -= 2;
		if (commandPress == 80)	y += 2;

		if (commandPress == 13) {
			if (y == 3) {
				exit(1);
			}
			else {
				cout << "\a";
			}
		}

		if (y < 1)	y = 3;
		if (y > 3)	y = 1;

		cout << "\b\b�@";
		cursorPosition.Y = y;
		SetConsoleCursorPosition(handle, cursorPosition);
		cout << "\b\b��";
	}
}