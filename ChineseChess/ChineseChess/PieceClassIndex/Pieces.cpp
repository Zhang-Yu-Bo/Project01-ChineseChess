#include "Pieces.h"

vector<COORDINATE> Pieces::movable(const vector<vector<int>>&) {
	return vector<COORDINATE>();
}

vector<COORDINATE> Pieces::eatable(const vector<vector<int>>&) {
	return vector<COORDINATE>();
}

bool Pieces::MoveAndEat(COORDINATE destination, vector<vector<int>>& boardStatus, vector<vector<Pieces*>>& pieceStatus) {
	vector<COORDINATE> movePosition = movable(boardStatus);
	vector<COORDINATE> eatPosition = eatable(boardStatus);
	auto move = find(begin(movePosition), end(movePosition), destination);
	auto eat = find(begin(eatPosition), end(eatPosition), destination);
	//==============執行移棋====================
	if (move != movePosition.end()) {
		boardStatus[position.first][position.second] = 0;
		pieceStatus[destination.first][destination.second] = pieceStatus[position.first][position.second];
		pieceStatus[position.first][position.second] = NULL;
		boardStatus[destination.first][destination.second] = code;
		position = destination;
		return true;
	}
	//==============執行吃棋====================
	else if (eat != eatPosition.end()) {
		pieceStatus[destination.first][destination.second]->alive = false;
		boardStatus[position.first][position.second] = 0;
		pieceStatus[destination.first][destination.second] = pieceStatus[position.first][position.second];
		pieceStatus[position.first][position.second] = NULL;
		boardStatus[destination.first][destination.second] = code;
		position = destination;
		return true;
	}
	else {
		return false;
	}
}
//==============取回資料====================
bool Pieces::JudgeAlive()const {
	return alive;
}

bool Pieces::FetchIdentity()const {
	return identity;
}

COORDINATE Pieces::FetchPosition() const {
	return position;
}