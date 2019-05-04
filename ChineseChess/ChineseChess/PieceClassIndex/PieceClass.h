#pragma once
#include "Pieces.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//=====棋盤邊界====================

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
const int riverBlack = 5;
const int riverRed = 6;
#ifndef _PIECECLASS_H_
#define _PIECECLASS_H_

//=====各類棋子類別================
class ClassGeneral :public Pieces {//將、帥
public:
	//建構子，接收初始位置、陣營
	ClassGeneral(int i, int j, bool c) :Pieces(i, j, c) { code = 1; }
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
	ClassGuard(int i, int j, bool c) :Pieces(i, j, c) { code = 2; }
	virtual vector<COORDINATE> movable(const vector<vector<int>>&);
	virtual vector<COORDINATE> eatable(const vector<vector<int>>&);
};
//==================================================================================

#endif// !_PIECESCLASS_H_