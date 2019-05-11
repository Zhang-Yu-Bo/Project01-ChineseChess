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
	bool identity;//0�¡B1��
	int code;
	bool alive;
public:
	//�غc�l
	Pieces(int i, int j, bool c) :position(make_pair(i, j)), identity(c), alive(true) {}
	Pieces(const Pieces& p) {
		position.first = p.position.first;
		position.second = p.position.second;
		identity = p.identity;
		alive = p.alive;
		code = p.code;
	}
	~Pieces() {}
	//�����禡(�Ω����l���O�~��)
	//�Y�^�Ҧ��i�઺���ʥت��a(���]�t�Y��)
	virtual vector<COORDINATE> movable(const vector<vector<int>>&);
	//�Y�^�Ҧ��i�H�Y���Ѥl��m(���]�t����)
	virtual vector<COORDINATE> eatable(const vector<vector<int>>&);
	//�ק磌���m�A�]�t�Y�ѻP���ѡA���ǤJ�ت��aindex�A�t���b
	bool MoveAndEat(COORDINATE, vector<vector<int>>&, vector<vector<Pieces*>>&);
	bool JudgeAlive()const;
	bool FetchIdentity()const;
	COORDINATE FetchPosition()const;
};
#endif // !_PIECES_H_