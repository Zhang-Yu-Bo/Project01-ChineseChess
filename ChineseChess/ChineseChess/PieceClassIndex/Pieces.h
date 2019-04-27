#pragma once
#include <iostream>
#include <vector>
using namespace std;
#define COORDINATE pair<int,int>

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