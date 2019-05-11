#pragma once
#include <iostream>
#include <vector>
#define BLACK 0
#define RED 1
using namespace std;

typedef pair<int, int> COORDINATE;

#ifndef _PIECES_H_
#define _PIECES_H_
class Pieces{
protected:
	COORDINATE position;
	bool identity;//0黑、1紅
	int code;
	bool alive;
public:
	//建構子
	Pieces(int i, int j, bool c) :position(make_pair(i, j)), identity(c), alive(true) {}
	Pieces(const Pieces& p) {
		position.first = p.position.first;
		position.second = p.position.second;
		identity = p.identity;
		alive = p.alive;
		code = p.code;
	}
	~Pieces() {}
	//虛擬函式(用於讓子類別繼承)
	//擲回所有可能的移動目的地(不包含吃棋)
	virtual vector<COORDINATE> movable(const vector<vector<int>>&);
	//擲回所有可以吃的棋子位置(不包含移棋)
	virtual vector<COORDINATE> eatable(const vector<vector<int>>&);
	//修改物件位置，包含吃棋與移棋，須傳入目的地index，含防呆
	bool MoveAndEat(COORDINATE, vector<vector<int>>&, vector<vector<Pieces*>>&);
	bool JudgeAlive()const;
	bool FetchIdentity()const;
	COORDINATE FetchPosition()const;
};
#endif // !_PIECES_H_