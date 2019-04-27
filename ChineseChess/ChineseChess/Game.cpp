#include "Game.h"

// 鍵盤掃描碼
// 上:		72
// 下:		80
// 左:		75
// 右:		77
// <:		44
// >:		46
// Enter:	13
// Esc:		27

// 初始化&宣告 Game.h 裡的 extern string [gameMenu]
#ifdef _GAME_MENU_
string gameMenu[5] = {
	"＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝",
	"∥　　　　　→開始遊戲　　　　　∥",
	"＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝",
	"∥　　　　　　結束程式　　　　　∥",
	"＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝"
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

	// 顯示輸出Menu內容
	for (int i = 0; i < (sizeof(gameMenu) / sizeof(gameMenu[0])); i++)
		cout << gameMenu[i] << endl;
	
	// 設定初始光標位置
	int commandPress = 0, y = 1;
	cursorPosition.X = 14;	cursorPosition.Y = 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

	// 設置視窗大小
	SMALL_RECT windowSize = { 0,0,34, 4 };
	SetConsoleWindowInfo(handle, TRUE, &windowSize);

	// 隱藏光標
	GetConsoleCursorInfo(handle, &cci);
	cci.bVisible = false;
	SetConsoleCursorInfo(handle, &cci);

	// 光標控制
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

		cout << "\b\b　";
		cursorPosition.Y = y;
		SetConsoleCursorPosition(handle, cursorPosition);
		cout << "\b\b→";
	}
}