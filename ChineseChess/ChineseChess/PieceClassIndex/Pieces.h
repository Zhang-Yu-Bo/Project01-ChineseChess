#pragma once
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> COORDINATE;

#ifndef _PIECES_H_
#define _PIECES_H_
class Pieces
{
public:
	Pieces(int, int, bool);
	virtual vector<COORDINATE> movable();
	virtual vector<COORDINATE> eatable();
	virtual bool moveAndEat(COORDINATE);
protected:
	
private:

};
#endif // !_PIECES_H_