#pragma once
#include <iostream>
#include <vector>
using namespace std;
#define COORDINATE pair<int,int>


#ifndef _PIECES_H_
#define _PIECES_H_
class Pieces
{
public:
	Pieces(int, int, bool);

protected:
	virtual vector<COORDINATE> movable();
	virtual vector<COORDINATE> eatable();
	virtual bool moveAndEat(COORDINATE);
private:

};
#endif // !_PIECES_H_