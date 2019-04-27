#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#define COORDINATE pair<int,int>

using namespace std;

#ifndef _GAME_MENU_
#define	_GAME_MENU_
extern const string gameMenu[5];
#endif // !_GAME_MENU_

#ifndef _CLEAR_BOARD_
#define	_CLEAR_BOARD_
extern const string clearBoard[21][18];
#endif // !_CLEAR_BOARD_

#ifndef _CHESS_CHINESE_
#define _CHESS_CHINESE_
extern const string chessChinese[15];
#endif // !_CHESS_CHINESE_

#ifndef _CURRENT_COORDINATE_
#define _CURRENT_COORDINATE_
extern COORDINATE currentCoordinate;
#endif // !_CURRENT_COORDINATE_


static CONSOLE_SCREEN_BUFFER_INFO csbi;
static CONSOLE_CURSOR_INFO cci;
static HANDLE handle;
static COORD cursorPosition;

class Game
{
public:
	Game();
	~Game();
	void gameStart();
	void initializeGame();
	void showMenu();
private:

};