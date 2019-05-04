#pragma once
#include "Pieces.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//=====�ѽL���====================

//=====�E�c���====================
const int palaceBlackI_UP = 0;
const int palaceBlackI_DOWN = 4;
const int palaceBlackJ_LEFT = 3;
const int palaceBlackJ_RIGHT = 7;
const int palaceRedI_UP = 7;
const int palaceRedI_DOWN = 11;
const int palaceRedJ_LEFT = 3;
const int palaceRedJ_RIGHT = 7;
//=====�e�y���====================
const int riverBlack = 5;
const int riverRed = 6;
#ifndef _PIECECLASS_H_
#define _PIECECLASS_H_

//=====�U���Ѥl���O================
class ClassGeneral :public Pieces {//�N�B��
public:
	//�غc�l�A������l��m�B�}��
	ClassGeneral(int i, int j, bool c) :Pieces(i, j, c) { code = 1; }
	//�����禡
	//�Y�^�Ҧ��i�઺���ʥت��a(���]�t�Y��)
	virtual vector<COORDINATE> movable(const vector<vector<int>>&);//�G��int vector
	//�Y�^�Ҧ��i�H�Y���Ѥl��m(���]�t����)
	virtual vector<COORDINATE> eatable(const vector<vector<int>>&);//�G��int vector
	//�ק磌���m�A�]�t�Y�ѻP���ѡA���ǤJ�ت��aindex�A�t���b
};
//==================================================================================

class ClassGuard :public Pieces {//�h�B�K
public:
	ClassGuard(int i, int j, bool c) :Pieces(i, j, c) { code = 2; }
	virtual vector<COORDINATE> movable(const vector<vector<int>>&);
	virtual vector<COORDINATE> eatable(const vector<vector<int>>&);
};
//==================================================================================

#endif// !_PIECESCLASS_H_