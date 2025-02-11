#include "MainMenu.h"

#ifdef _MAIN_MENU_OPTION_
const string mainMenuOption[7] = {
		"／」」」」」」」」」」」」」」」／\n",
		"●�@�@�@�@�@＠�}�l�C生�@�@�@�@�@●\n",
		"●」」」」」」」」」」」」」」」●\n",
		"●�@�@�@�@�@�@的��観�L�@�@�@�@�@●\n",
		"●」」」」」」」」」」」」」」」●\n",
		"●�@�@�@�@�@�@飢���{Α�@�@�@�@�@●\n",
		"ゞ」」」」」」」」」」」」」」」ゞ"
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
		// �魯葎艮`ノ�N�X:240>>フ�涯側r�A116>>η�害`���r�A7>>饗�灰妣r�A252>>フ�階��r
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
	// �]�m鋸機�j�p
	SMALL_RECT windowSize = { 0,0,33, 6 };
	SetConsoleWindowInfo(handle, TRUE, &windowSize);
	setConsoleCursorCoordinate(0, 0);

	setColor(7,0);
	// 塔ボ翠�XMenuず�e
	for (int i = 0; i < (sizeof(mainMenuOption) / sizeof(mainMenuOption[0])); i++)
		cout << mainMenuOption[i];

	// �N�e�羽垢W�圈A�Yぃ�N��斜�豸my苅��0�左棔Aconsole�e�臼N�|�垢U�@�I
	setConsoleCursorCoordinate(0, 0);

	// �]�w�讒l��斜�豸m
	int commandPress = 0, y = 1;
	setConsoleCursorCoordinate(14, 1);

	// 藻唾��斜
	cursorVisiable(false);

	// ��斜臼��
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

		cout << "\b\b�@";
		cursorPosition.Y = y;
		SetConsoleCursorPosition(handle, cursorPosition);
		cout << "\b\b＠";
	}
}

string MainMenu::showFiles() {
	setConsoleCursorCoordinate(0, 0);
	cout << "／」」」」」」」」」」」」」」」／\n";
	cout << "●�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@●\n";
	cout << "●�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@●\n";
	cout << "●�@翠�J隻�W�G�@�@�@�@�@�@�@�@�@●\n";
	cout << "●�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@●\n";
	cout << "●�@�@�@�@�@�@�@�]翠�Jquit�隍^�^●\n";
	cout << "ゞ」」」」」」」」」」」」」」」ゞ";
	setConsoleCursorCoordinate(0, 0);
	cursorVisiable(true);
	setConsoleCursorCoordinate(14, 3);
	string fileName = "";
	getline(cin, fileName);
	return fileName;
}