#pragma once
#include "Pieces.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//=====棋盤邊界====================
const int boardTop = 0;
const int boardBottom = 11;
const int boardLeft = 0;
const int boardRight = 10;
//=====九宮邊界====================
const int palaceBlackI_UP = 0;
const int palaceBlackI_DOWN = 4;
const int palaceBlackJ_LEFT = 3;
const int palaceBlackJ_RIGHT = 7;
const int palaceRedI_UP = 7;
const int palaceRedI_DOWN = 11;
const int palaceRedJ_LEFT = 3;
const int palaceRedJ_RIGHT = 7;
//=====河流邊界====================
const int riverBlack = 6;
const int riverRed = 5;
#ifndef _PIECECLASS_H_
#define _PIECECLASS_H_

//=====各類棋子類別================
class ClassGeneral :public Pieces {//將、帥
public:
	//建構子，接收初始位置、陣營
	ClassGeneral(int i, int j, bool c) :Pieces(i, j, c) { 
		code = (c) ? 1 + 7 : 1;
	}
	//成員函式
	//擲回所有可能的移動目的地(不包含吃棋)
	virtual vector<COORDINATE> movable(const vector<vector<int>>&);//二維int vector
	//擲回所有可以吃的棋子位置(不包含移棋)
	virtual vector<COORDINATE> eatable(const vector<vector<int>>&);//二維int vector
	//修改物件位置，包含吃棋與移棋，須傳入目的地index，含防呆
};
//==================================================================================

class ClassGuard :public Pieces {//士、仕
public:
	ClassGuard(int i, int j, bool c) :Pieces(i, j, c) {
		code = (c) ? 2 + 7 : 2;
	}
	virtual vector<COORDINATE> movable(const vector<vector<int>>&);
	virtual vector<COORDINATE> eatable(const vector<vector<int>>&);
};
//==================================================================================

class ClassMinister:public Pieces {//象、相
public:
	ClassMinister(int i, int j, bool c) :Pieces(i, j, c) {
		code = (c) ? 3 + 7 : 3;
	}
	virtual vector<COORDINATE> movable(const vector<vector<int>>&);
	virtual vector<COORDINATE> eatable(const vector<vector<int>>&);
};
//==================================================================================

class ClassRook :public Pieces {//車、俥
public:
	ClassRook(int i, int j, bool c) :Pieces(i, j, c) {
		code = (c) ? 4 + 7 : 4;
	}
	virtual vector<COORDINATE> movable(const vector<vector<int>>&);
	virtual vector<COORDINATE> eatable(const vector<vector<int>>&);
};
//==================================================================================

class ClassHorse :public Pieces {//馬、傌
public:
	ClassHorse(int i, int j, bool c) :Pieces(i, j, c) {
		code = (c) ? 5 + 7 : 5;
	}
	virtual vector<COORDINATE> movable(const vector<vector<int>>&);
	virtual vector<COORDINATE> eatable(const vector<vector<int>>&);
};
//==================================================================================

class ClassCannon :public Pieces {//包、炮
public:
	ClassCannon(int i, int j, bool c) :Pieces(i, j, c) {
		code = (c) ? 6 + 7 : 6;
	}
	virtual vector<COORDINATE> movable(const vector<vector<int>>&);
	virtual vector<COORDINATE> eatable(const vector<vector<int>>&);
};
//==================================================================================

class ClassSoldier :public Pieces {//卒、兵
public:
	ClassSoldier(int i, int j, bool c) :Pieces(i, j, c) {
		code = (c) ? 7 + 7 : 7;
	}
	virtual vector<COORDINATE> movable(const vector<vector<int>>&);
	virtual vector<COORDINATE> eatable(const vector<vector<int>>&);
};
//==================================================================================

#endif// !_PIECESCLASS_H_