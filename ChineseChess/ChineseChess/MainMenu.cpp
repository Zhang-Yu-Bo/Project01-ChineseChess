#include "MainMenu.h"

#ifdef _MAIN_MENU_OPTION_
const string mainMenuOption[7] = {
		"▼＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝▼\n",
		"∥　　　　　→開始遊戲　　　　　∥\n",
		"∥＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝∥\n",
		"∥　　　　　　讀取棋盤　　　　　∥\n",
		"∥＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝∥\n",
		"∥　　　　　　結束程式　　　　　∥\n",
		"▲＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝▲"
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
	menu = this;
}

MainMenu::~MainMenu()
{

}

void MainMenu::showMenu() {
	// 設置視窗大小
	SMALL_RECT windowSize = { 0,0,33, 6 };
	SetConsoleWindowInfo(handle, TRUE, &windowSize);
	setConsoleCursorCoordinate(0, 0);

	setColor(7,0);
	// 顯示輸出Menu內容
	for (int i = 0; i < (sizeof(mainMenuOption) / sizeof(mainMenuOption[0])); i++)
		cout << mainMenuOption[i];

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
		if (commandPress == 72 || commandPress== 119)	y -= 2;
		if (commandPress == 80 || commandPress == 115)	y += 2;

		if (commandPress == 13 || commandPress == 32) {
			if (y == 1) {
				cout << "\a";
				Game newGame("Initial.txt");
				newGame.gameStart();
			}
			else if (y == 3) {
				string fileName = this->showFiles();
				if (fileName == "quit") {
					this->showMenu();
				}
				else {
					cout << "\a";
					Game newGame(fileName+".txt");
					newGame.gameStart();
				}
				
			}
			else if (y == 5) {
				exit(1);
			}
		}

		if (y < 1)	y = 5;
		if (y > 5)	y = 1;

		cout << "\b\b　";
		cursorPosition.Y = y;
		SetConsoleCursorPosition(handle, cursorPosition);
		cout << "\b\b→";
	}
}

string MainMenu::showFiles() {
	setConsoleCursorCoordinate(0, 0);
	cout << "▼＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝▼\n";
	cout << "∥　　　　　　　　　　　　　　　∥\n";
	cout << "∥　　　　　　　　　　　　　　　∥\n";
	cout << "∥　輸入檔名：　　　　　　　　　∥\n";
	cout << "∥　　　　　　　　　　　　　　　∥\n";
	cout << "∥　　　　　　　（quit取消輸入）∥\n";
	cout << "▲＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝▲";
	setConsoleCursorCoordinate(0, 0);
	cursorVisiable(true);
	setConsoleCursorCoordinate(14, 3);
	string fileName = "";
	getline(cin, fileName);
	return fileName;
}