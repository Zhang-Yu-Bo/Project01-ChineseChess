﻿#include "Game.h"

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
	int setFileNameAndProcess(string fileName, int chessInt[12][11])
	{
		int whosTurn = 0;
		fstream inputStream;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 11; j++) {
				if (i == 0 || j == 0 || i == 11 || j == 1)chessInt[i][j] = -1;
			}
		}
		inputStream.open(("boardText/" + fileName));
		if (!inputStream)  // operator! is used here
		{
			cout << "沒有這個檔案\n";
			system("pause");
			exit(1);
		}
		else {
			for (int i = 1; i < 11; i++) {
				for (int j = 1; j < 10; j++) {
					inputStream >> chessInt[i][j];
				}
			}
			inputStream >> whosTurn;
			/*
			if (inputStream.bad())
				cout << "I/O error while reading\n";
			else if (inputStream.eof())
				cout << "End of file reached successfully\n";
			else if (inputStream.fail())
				cout << "Non-integer data encountered\n";
			*/
			inputStream.close();
			return whosTurn;
		}
	}
	/*
	// 輸出象棋(中文)
	void printChess(int i)
	{
		cout << chessChinese[i];
	}
	void printBoard(int chessInt[12][11])
	{
		for (int i = 0; i < 21; i++) {
			printLeftSpace();
			for (int j = 0; j < 18; j++) {
				if (i % 2 == 1 && j % 2 == 0 && chessInt[(i / 2) + 1][(j / 2) + 1] != 0)
				{
					if (chessInt[(i / 2) + 1][(j / 2) + 1] >= 1 && chessInt[(i / 2) + 1][(j / 2) + 1] <= 7)
						setColor(240);
					else if (chessInt[(i / 2) + 1][(j / 2) + 1] >= 8 && chessInt[(i / 2) + 1][(j / 2) + 1] <= 14)
						setColor(252);
					printChess(chessInt[(i / 2) + 1][(j / 2) + 1]);
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
	*/
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
	this->nowTurn = 0;
	this->tableFileName = "";
	currentCoordinate = make_pair(0, 0);
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	cursorPosition.X = 0;	cursorPosition.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

Game::~Game()
{

}

void Game::showMenu() {

}

void Game::gameStart() {
	int chessInt[12][11];
	int whosTurn = 0;

	// 清空console
	system("cls");
	// 設置視窗大小
	SMALL_RECT windowSize = { 0,0,117, 22 };
	SetConsoleWindowInfo(handle, TRUE, &windowSize);

	// 繪製遊戲畫面
	whosTurn = setFileNameAndProcess("Initial.txt", chessInt);
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
			setColor(252);	cout << "車\b\b";
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

void Game::printChess(int i) {
	cout << this->chessChinese[i];
}

void Game::printBoard(int chessInt[12][11]) {
	for (int i = 0; i < 21; i++) {
		printLeftSpace();
		for (int j = 0; j < 18; j++) {
			if (i % 2 == 1 && j % 2 == 0 && chessInt[(i / 2) + 1][(j / 2) + 1] != 0)
			{
				if (chessInt[(i / 2) + 1][(j / 2) + 1] >= 1 && chessInt[(i / 2) + 1][(j / 2) + 1] <= 7)
					setColor(240);
				else if (chessInt[(i / 2) + 1][(j / 2) + 1] >= 8 && chessInt[(i / 2) + 1][(j / 2) + 1] <= 14)
					setColor(252);
				printChess(chessInt[(i / 2) + 1][(j / 2) + 1]);
			}
			else {
				// 奇數列偶數行判斷int陣列裡面的東東
				setColor(116);
				cout << this->clearBoard[i][j];
			}
		}
		printRightSpace();
		cout << endl;
	}
}