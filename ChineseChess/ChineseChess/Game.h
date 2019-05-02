#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include "PieceClassIndex/Pieces.h"
#define COORDINATE pair<int,int>

using namespace std;

#ifndef _CURRENT_COORDINATE_
#define _CURRENT_COORDINATE_
extern COORDINATE currentCoordinate;
#endif // !_CURRENT_COORDINATE_

static CONSOLE_SCREEN_BUFFER_INFO csbi;

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
	void printChess(int);
	void printBoard(int chessInt[12][11]);
	CONSOLE_CURSOR_INFO cci;
	HANDLE handle;
	COORD cursorPosition;
	void cursorVisiable(bool);
	void setConsoleCursorCoordinate(int, int);
	void setColor(int, int);
	void printLeftSpace();
	void printRightSpace();

	int nowTurn;
	string tableFileName;
	vector<vector<int>> boardStatus;
	const string chessChinese[15] = {
		"","將","士","象","車","馬","包","卒","帥","仕","相","車","傌","炮","兵"
	};
	const string clearBoard[21][18] = {
		{"１","　","２","　","３","　","４","　","５","　","６","　","７","　","８","　","９"},
		{"•","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","•"},
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
		{"•","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","＝","•"},
		{"九","　","八","　","七","　","六","　","五","　","四","　","三","　","二","　","一"}
	};
};
#endif // !_GAME_H_