#include "MainMenu.h"

#ifdef _MAIN_MENU_OPTION_
const string mainMenuOption[5] = {
		"���ססססססססססססססס�\n",
		"���@�@�@�@�@���}�l�C���@�@�@�@�@��\n",
		"���ססססססססססססססס�\n",
		"���@�@�@�@�@�@�����{���@�@�@�@�@��\n",
		"���ססססססססססססססס�"
};
#endif // _MAIN_MENU_
MainMenu* menu = NULL;

namespace {
	void cursorVisiable(bool flag) {
		GetConsoleCursorInfo(handle, &cci);
		cci.bVisible = flag;
		SetConsoleCursorInfo(handle, &cci);
	}
	void setConsoleCursorCoordinate(int x = 42, int y = 2) {
		cursorPosition.X = x;	cursorPosition.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	}

	void setColor(int f = 7, int b = 0) {
		// �ϥΪ��`�ΥN�X:240>>�թ��¦r�A116>>�ǩ��`���r�A7>>�©��զr�A252>>�թ����r
		unsigned short ForeColor = f + 16 * b;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ForeColor);
	}
}

MainMenu::MainMenu()
{
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	cursorPosition.X = 0;	cursorPosition.Y = 0;
	SetConsoleCursorPosition(handle, cursorPosition);
	menu = this;
}

MainMenu::~MainMenu()
{

}

void MainMenu::showMenu() {
	// �]�m�����j�p
	SMALL_RECT windowSize = { 0,0,33, 4 };
	SetConsoleWindowInfo(handle, TRUE, &windowSize);

	setColor(7,0);
	// ��ܿ�XMenu���e
	for (int i = 0; i < (sizeof(mainMenuOption) / sizeof(mainMenuOption[0])); i++)
		cout << mainMenuOption[i];

	// �N�e�����W�ԡA�Y���N���Ц�my����0���ܡAconsole�e���N�|���U�@�I
	setConsoleCursorCoordinate(0, 0);

	// �]�w��l���Ц�m
	int commandPress = 0, y = 1;
	setConsoleCursorCoordinate(14, 1);

	// ���å���
	cursorVisiable(false);

	// ���б���
	while (commandPress = _getch())
	{
		if (commandPress == 72 || commandPress== 119)	y -= 2;
		if (commandPress == 80 || commandPress == 115)	y += 2;

		if (commandPress == 13 || commandPress == 32) {
			if (y == 1) {
				cout << "\a";
				//this->gameStart();
				Game newGame;
				newGame.gameStart();
			}
			else if (y == 3) {
				exit(1);
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