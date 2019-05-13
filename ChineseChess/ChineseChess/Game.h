#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <algorithm>
#include "PieceClassIndex/Pieces.h"
#include "PieceClassIndex/PieceClass.h"
#include "MainMenu.h"
#include <iomanip>
#include <mmsystem.h>
#pragma comment(lib,"Winmm.lib")

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

#ifndef _GAME_MENU_
#define _GAME_MENU_
extern const string gameMenuOption[5];
#endif // !_GAME_MENU_

#ifndef _LEFT_RIGHT_SPACE_
#define _LEFT_RIGHT_SPACE_
extern const string leftSpace[21];
extern const string rightSpace[21];
#endif // !_LEFT_RIGHT_SPACE_

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
	void showTurn();
	void showChoice(int choice);
	void showBattleStatus();
	void boardStatusToPointBoardStatus();
	//黑方勝利擲回BLACK，紅方勝利擲回RED(macro: BLACK 0 / RED 1)，沒分勝負擲回-1，出現錯誤(找不到任一方的王)擲回-2
	int JudgeVictory(const vector<vector<int>>& boardStatus);
	// 
	int nowTurn;
	int whoStart;
	string tableFileName;
	vector<vector<int>> boardStatus;
	vector<vector<Pieces*>> pointBoardStatus;
	vector<string> battleStatus;
	vector<vector<vector<int>>> theLogsOfBS;
};
#endif // !_GAME_H_