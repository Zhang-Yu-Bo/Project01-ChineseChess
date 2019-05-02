#include "MainMenu.h"

namespace {
	void setColor(int f = 7, int b = 0) {
		// 使用的常用代碼:240>>白底黑字，116>>灰底深紅字，7>>黑底白字，252>>白底紅字
		unsigned short ForeColor = f + 16 * b;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ForeColor);
	}
}

MainMenu::MainMenu()
{
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	cursorPosition.X = 0;	cursorPosition.Y = 0;
	SetConsoleCursorPosition(handle, cursorPosition);
}

void MainMenu::showMenu() {
	// 設置視窗大小
	SMALL_RECT windowSize = { 0,0,33, 4 };
	SetConsoleWindowInfo(handle, TRUE, &windowSize);

	setColor(7);
	// 顯示輸出Menu內容
	for (int i = 0; i < (sizeof(mainMenu) / sizeof(mainMenu[0])); i++)
		cout << mainMenu[i];

	// 將畫面往上拉，若不將光標位置y提至0的話，console畫面將會往下一點
	setConsoleCursorCoordinate(0, 0);

	// 設定初始光標位置
	int commandPress = 0, y = 1;
	setConsoleCursorCoordinate(14, 1);

	// 隱藏光標
	cursorVisiable(false);

	// 光標控制
	while (commandPress = _getch())
	{
		if (commandPress == 72)	y -= 2;
		if (commandPress == 80)	y += 2;

		if (commandPress == 13) {
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

		cout << "\b\b　";
		cursorPosition.Y = y;
		SetConsoleCursorPosition(handle, cursorPosition);
		cout << "\b\b→";
	}
}

MainMenu::~MainMenu()
{

}

void MainMenu::cursorVisiable(bool flag) {
	GetConsoleCursorInfo(handle, &cci);
	cci.bVisible = flag;
	SetConsoleCursorInfo(handle, &cci);
}
void MainMenu::setConsoleCursorCoordinate(int x = 42, int y = 2) {
	cursorPosition.X = x;	cursorPosition.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}