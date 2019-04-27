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
const string gameMenu[5] = {
	"＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝",
	"∥　　　　　→開始遊戲　　　　　∥",
	"＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝",
	"∥　　　　　　結束程式　　　　　∥",
	"＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝"
};
#endif // _GAME_MENU_

// 初始化&宣告 Game.h 裡的 extern string [clearBoard]
#ifdef _CLEAR_BOARD_
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

// 初始化&宣告 Game.h 裡的 extern const string [chessChinese]
#ifdef _CHESS_CHINESE_
const string chessChinese[15] = { 
	"","將","士","象","車","馬","包","卒","帥","仕","相","車","傌","炮","兵" 
};
#endif // _CHESS_CHINESE_

#ifdef _CURRENT_COORDINATE_
COORDINATE currentCoordinate(0, 0);
#endif // _CURRENT_COORDINATE_


namespace {
	void setColor(int f = 7, int b = 0) {
		// 使用的常用代碼:240>>白底黑字，116>>灰底深紅字，7>>黑底白字，252>>白底紅字
		unsigned short ForeColor = f + 16 * b;
		SetConsoleTextAttribute(handle, ForeColor);
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
	int setFileNameAndProcess(string fileName, int chessInt[10][9])
	{
		int whosTurn = 0;
		fstream inputStream;
		inputStream.open(("boardText/"+fileName));
		if (!inputStream)  // operator! is used here
		{
			cout << "沒有這個檔案\n";
			system("pause");
			exit(1);
		}
		else {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 9; j++) {
					inputStream >> chessInt[i][j];
				}
			}
			inputStream >> whosTurn;
			if (inputStream.bad())
				cout << "I/O error while reading\n";
			else if (inputStream.eof())
				cout << "End of file reached successfully\n";
			else if (inputStream.fail())
				cout << "Non-integer data encountered\n";
			inputStream.close();
			return whosTurn;
		}
	}
	// 輸出象棋(中文)
	void printChess(int i)
	{
		cout << chessChinese[i];
	}
	void printBoard(int chessInt[10][9])
	{
		for (int i = 0; i < 21; i++) {
			printLeftSpace();
			for (int j = 0; j < 18; j++) {
				if (i % 2 == 1 && j % 2 == 0 && chessInt[(i / 2)][(j / 2)] != 0)
				{
					if (chessInt[(i / 2)][(j / 2)] >= 1 && chessInt[(i / 2)][(j / 2)] <= 7) 
						setColor(240);
					else if (chessInt[(i / 2)][(j / 2)] >= 8 && chessInt[(i / 2)][(j / 2)] <= 14) 
						setColor(252);
					printChess(chessInt[(i / 2)][(j / 2)]);
				}
				else {
					// 奇數列偶數行判斷int陣列裡面的東東
					setColor(116);
					cout << clearBoard[i][j];
				}
			}
			printRightSpace();
			cout << endl;
		}
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
	void cursorVisiable(bool flag) {
		GetConsoleCursorInfo(handle, &cci);
		cci.bVisible = flag;
		SetConsoleCursorInfo(handle, &cci);
	}
	void setConsoleCursorCoordinate(int x = 42, int y = 2) {
		cursorPosition.X = x;	cursorPosition.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	}
}


Game::Game()
{
	cursorPosition.X = 0;	cursorPosition.Y = 0;
	currentCoordinate = make_pair(0, 0);
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

	// 設置視窗大小
	SMALL_RECT windowSize = { 0,0,34, 4 };
	SetConsoleWindowInfo(handle, TRUE, &windowSize);

	// 顯示輸出Menu內容
	for (int i = 0; i < (sizeof(gameMenu) / sizeof(gameMenu[0])); i++)
		cout << gameMenu[i] << endl;
	
	// 將畫面往上拉，若不將光標位置y提至0的話，console畫面將會往下一點
	setConsoleCursorCoordinate(0, 0);

	// 設定初始光標位置
	int commandPress = 0, y = 1;
	setConsoleCursorCoordinate(14, 1);

	// 隱藏光標
	cursorVisiable(false);

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
				this->gameStart();
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

void Game::gameStart() {
	int chessInt[10][9];
	int whosTurn = 0;

	// 清空console
	system("cls");
	// 設置視窗大小
	SMALL_RECT windowSize = { 0,0,117, 22 };
	SetConsoleWindowInfo(handle, TRUE, &windowSize);

	// 繪製遊戲畫面
	whosTurn = setFileNameAndProcess("Test.txt", chessInt);
	printTopBorder();
	printBoard(chessInt);
	printDownBorder();

	// 將畫面往上拉，若不將光標位置y提至0的話，console畫面將會往下一點
	setConsoleCursorCoordinate(0, 0);

	// 顯示光標(Cursor)
	cursorVisiable(true);

	int commandPress, x = 42, y = 2;
	setConsoleCursorCoordinate();

	while (commandPress = _getch())
	{
		switch (commandPress)
		{
		case 72:				//上
			y -= 2;
			break;
		case 80:				//下
			y += 2;
			break;
		case 75:				//左
			x -= 4;
			break;
		case 77:				//右
			x += 4;
			break;
		case 44:				//<

			break;
		case 46:				//>

			break;
		case 13:				//Enter

			break;
		case 27:				//Esc
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