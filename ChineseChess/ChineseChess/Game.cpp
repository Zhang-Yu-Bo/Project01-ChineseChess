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

#ifdef _CURRENT_COORDINATE_
COORDINATE currentCoordinate(0, 0);
#endif // _CURRENT_COORDINATE_

#ifdef _CONSOLE_INFO_HANDLE_
CONSOLE_CURSOR_INFO cci;
HANDLE handle;
COORD cursorPosition;
#endif // _CONSOLE_INFO_HANDLE_


#ifdef _CHESS_CHINESE_
const string chessChinese[15] = {
		"","將","士","象","車","馬","包","卒","帥","仕","相","車","傌","炮","兵"
};
#endif // _CHESS_CHINESE_

#ifdef _CELAR_BOARD_
const string clearBoard[21][18] = {
		{"１","　","２","　","３","　","４","　","５","　","６","　","７","　","８","　","９"},
		{"‧","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","‧"},
		{"∥","　","｜","　","｜","　","｜","＼","｜","／","｜","　","｜","　","｜","　","∥"},
		{"∥","－","＋","－","＋","－","＋","－","＋","－","＋","－","＋","－","＋","－","∥"},
		{"∥","　","｜","　","｜","　","｜","／","｜","＼","｜","　","｜","　","｜","　","∥"},
		{"∥","－","＋","－","＋","－","＋","－","＋","－","＋","－","＋","－","＋","－","∥"},
		{"∥","　","｜","　","｜","　","｜","　","｜","　","｜","　","｜","　","｜","　","∥"},
		{"∥","－","＋","－","＋","－","＋","－","＋","－","＋","－","＋","－","＋","－","∥"},
		{"∥","　","｜","　","｜","　","｜","　","｜","　","｜","　","｜","　","｜","　","∥"},
		{"∥","－","－","－","－","－","－","－","－","－","－","－","－","－","－","－","∥"},
		{"∥","　","　","楚","河","　","　","　"," 　"," ","　","　","漢","界","　","　","∥"},
		{"∥","－","－","－","－","－","－","－","－","－","－","－","－","－","－","－","∥"},
		{"∥","　","｜","　","｜","　","｜","　","｜","　","｜","　","｜","　","｜","　","∥"},
		{"∥","－","＋","－","＋","－","＋","－","＋","－","＋","－","＋","－","＋","－","∥"},
		{"∥","　","｜","　","｜","　","｜","　","｜","　","｜","　","｜","　","｜","　","∥"},
		{"∥","－","＋","－","＋","－","＋","－","＋","－","＋","－","＋","－","＋","－","∥"},
		{"∥","　","｜","　","｜","　","｜","＼","｜","／","｜","　","｜","　","｜","　","∥"},
		{"∥","－","＋","－","＋","－","＋","－","＋","－","＋","－","＋","－","＋","－","∥"},
		{"∥","　","｜","　","｜","　","｜","／","｜","＼","｜","　","｜","　","｜","　","∥"},
		{"‧","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","‧"},
		{"九","　","八","　","七","　","六","　","五","　","四","　","三","　","二","　","一"}
};
#endif // _CLEAR_BOARD_


namespace {
	void setColor(int f = 7, int b = 0) {
		// 使用的常用代碼:240>>白底黑字，116>>灰底深紅字，7>>黑底白字，252>>白底紅字
		unsigned short ForeColor = f + 16 * b;
		SetConsoleTextAttribute(handle, ForeColor);
	}
	void cursorVisiable(bool flag) {
		GetConsoleCursorInfo(handle, &cci);
		cci.bVisible = flag;
		SetConsoleCursorInfo(handle, &cci);
	}
	void setConsoleCursorCoordinate(int x = 42, int y = 2) {
		cursorPosition.X = x;	cursorPosition.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	}
	// 左方空位
	void printLeftSpace() {
		// 1+20
		setColor(7);
		cout << "∥　　　　　　　　　　　　　　　　　　　　";
	}
	//右方空位
	void printRightSpace() {
		// 20+1
		setColor(7);
		cout << "　　　　　　　　　　　　　　　　　　　　∥";
	}
	void printTopBorder() {
		cout << "▼";
		for (int i = 0; i < 57; i++)
			cout << "＝";
		cout << "▼\n";
	}
	void printDownBorder() {
		cout << "▲";
		for (int i = 0; i < 57; i++)
			cout << "＝";
		cout << "▲";
	}
	void printChess(int i) {
		cout << chessChinese[i];
	}
	void printBoard(vector<vector<int>> chessInt) {
		__int64 row, col;
		for (int i = 0; i < 21; i++) {
			printLeftSpace();
			for (int j = 0; j < 18; j++) {
				row = (__int64)(i / 2) + 1;	col = (__int64)(j / 2) + 1;
				if (i % 2 == 1 && j % 2 == 0 && chessInt[row][col] != 0)
				{
					if (chessInt[row][col] >= 1 && chessInt[row][col] <= 7)
						setColor(240, 0);
					else if (chessInt[row][col] >= 8 && chessInt[row][col] <= 14)
						setColor(252, 0);
					printChess(chessInt[row][col]);
				}
				else {
					// 奇數列偶數行判斷int陣列裡面的東東
					setColor(116, 0);
					cout << clearBoard[i][j];
				}
			}
			printRightSpace();
			cout << endl;
		}
	}
}


Game::Game()
{
	this->nowTurn = 0;
	this->tableFileName = "Initial.txt";
	currentCoordinate = make_pair(0, 0);
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	cursorPosition.X = 0;	cursorPosition.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	for (int i = 0; i < 12; i++) {
		this->boardStatus.push_back(vector<int>());
		this->pointBoardStatus.push_back(vector<Pieces*>());
		for (int j = 0; j < 11; j++) {
			this->boardStatus[i].push_back(-1);
			this->pointBoardStatus[i].push_back(NULL);
		}
	}
}

Game::~Game()
{

}

void Game::showMenu() {
	menu->showMenu();
}

void Game::gameStart() {
	// 清空console
	system("cls");
	// 設置視窗大小
	SMALL_RECT windowSize = { 0,0,117, 22 };
	SetConsoleWindowInfo(handle, TRUE, &windowSize);

	// 繪製遊戲畫面
	setFileNameAndProcess();
	printTopBorder();
	printBoard(this->boardStatus);
	printDownBorder();

	// 將畫面往上拉，若不將光標位置y提至0的話，console畫面將會往下一點
	setConsoleCursorCoordinate(0, 0);

	// 顯示光標(Cursor)
	cursorVisiable(true);

	int commandPress, x = 42, y = 2;
	setConsoleCursorCoordinate(42,2);
	bool isTakingPiece = false;

	while (commandPress = _getch())
	{
		switch (commandPress)
		{
		case KEYBOARD_UP:
			y -= 2;
			break;
		case KEYBOARD_DOWN:
			y += 2;
			break;
		case KEYBOARD_LEFT:
			x -= 4;
			break;
		case KEYBOARD_RIGHT:
			x += 4;
			break;
		case KEYBOARD_LEFT_SHIFT:

			break;
		case KEYBOARD_RIGHT_SHIFT:

			break;
		case KEYBOARD_ENTER:
			if (!isTakingPiece) {
				isTakingPiece = true;
			}
			else {
				cout << "\a";
				isTakingPiece = false;
			}
			//setColor(252, 0);	cout << "車";
			break;
		case KEYBOARD_ESCAPE:
			system("cls");
			this->showMenu();
			break;
		default:
			break;
		}

		x = (x > (42 + 32)) ? 42 : x;
		x = (x < 42) ? (42 + 32) : x;
		y = (y > (2 + 18)) ? 2 : y;
		y = (y < 2) ? (2 + 18) : y;
		setConsoleCursorCoordinate(x, y);
	}
}

void Game::setFileNameAndProcess() {
	fstream inputStream;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 11; j++) {
			if (i == 0 || j == 0 || i == 11 || j == 1) {
				this->boardStatus[i][j] = -1;
				this->pointBoardStatus[i][j] = NULL;
			}
		}
	}
	inputStream.open(("boardText/" + this->tableFileName));
	if (!inputStream)  // operator! is used here
	{
		cout << "沒有這個檔案\n";
		system("pause");
		exit(1);
	}
	else {
		for (int i = 1; i < 11; i++) {
			for (int j = 1; j < 10; j++) {
				inputStream >> boardStatus[i][j];
			}
		}
		inputStream >> this->nowTurn;
		inputStream.close();
	}
}