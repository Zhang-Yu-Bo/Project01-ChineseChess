#include "Pieces.h"

vector<COORDINATE> Pieces::movable(const vector<vector<int>>&) {
	return vector<COORDINATE>();
}

vector<COORDINATE> Pieces::eatable(const vector<vector<int>>&) {
	return vector<COORDINATE>();
}

bool Pieces::MoveAndEat(COORDINATE destination, vector<vector<int>>& boardStatus, vector<vector<Pieces*>>& pieceStatus) {
	string chineseNotation;//�N�������ǻ���reference
	int excutor;
	COORDINATE departure;
	bool legalAction = false;
	vector<COORDINATE> movePosition = movable(boardStatus);
	vector<COORDINATE> eatPosition = eatable(boardStatus);
	auto move = find(begin(movePosition), end(movePosition), destination);
	auto eat = find(begin(eatPosition), end(eatPosition), destination);
	//=====================���沾��=====================
	if (move != movePosition.end()) {
		excutor = pieceStatus[position.first][position.second]->code;
		boardStatus[position.first][position.second] = 0;
		pieceStatus[destination.first][destination.second] = pieceStatus[position.first][position.second];
		pieceStatus[position.first][position.second] = NULL;
		boardStatus[destination.first][destination.second] = code;
		departure = position;
		position = destination;
		legalAction = true;
	}
	//=====================����Y��=====================
	else if (eat != eatPosition.end()) {
		excutor = pieceStatus[position.first][position.second]->code;
		pieceStatus[destination.first][destination.second]->alive = false;
		boardStatus[position.first][position.second] = 0;
		pieceStatus[destination.first][destination.second] = pieceStatus[position.first][position.second];
		pieceStatus[position.first][position.second] = NULL;
		boardStatus[destination.first][destination.second] = code;
		departure = position;
		position = destination;
		legalAction = true;
	}
	if (legalAction) {
		string prefix, name, surffix, action, delta;
		//�P�_�{��




	}
	return legalAction;
}
//==============���^���====================
bool Pieces::JudgeAlive()const {
	return alive;
}

bool Pieces::FetchIdentity()const {
	return identity;
}

COORDINATE Pieces::FetchPosition() const {
	return position;
}