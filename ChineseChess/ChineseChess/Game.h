#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include "PieceClassIndex/Pieces.h"
#include "MainMenu.h"

#define KEYBOARD_UP 72
#define KEYBOARD_DOWN 80
#define KEYBOARD_LEFT 75
#define KEYBOARD_RIGHT 77
#define KEYBOARD_LEFT_SHIFT 44
#define KEYBOARD_RIGHT_SHIFT 46
#define KEYBOARD_ENTER 13
#define KEYBOARD_ESCAPE 27

using namespace std;

typedef pair<int, int> COORDINATE;


#ifndef _CHESS_CHINESE_
#define _CHESS_CHINESE_
extern const string chessChinese[15];
#endif // !_CHESS_CHINESE_

#ifndef _CELAR_BOARD_
#define _CELAR_BOARD_
extern const string clearBoard[21][18];
#endif // !_CELAR_BOARD_

#ifndef _CONSOLE_INFO_HANDLE_
#define _CONSOLE_INFO_HANDLE_
extern CONSOLE_CURSOR_INFO cci;
extern HANDLE handle;
extern COORD cursorPosition;
#endif // !_CONSOLE_INFO_HANDLE_


//static CONSOLE_SCREEN_BUFFER_INFO csbi;

#ifndef _GAME_H_
#define _GAME_H_
class Game
{
public:
	Game();
	~Game();
	void gameStart();
	void showMenu();
private:
	// function
	void setFileNameAndProcess();
	// 
	int nowTurn;
	string tableFileName;
	vector<vector<int>> boardStatus;
	vector<vector<Pieces*>> pointBoardStatus;
};
#endif // !_GAME_H_