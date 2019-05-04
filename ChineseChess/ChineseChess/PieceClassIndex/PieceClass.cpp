#include "PieceClass.h"

vector<vector<Pieces*>> pieceStatus;
//===========================================================
vector<COORDINATE> ClassGeneral::movable(const vector<vector<int>>& boardStatus) {
	vector<COORDINATE> legalMove;
	int i = position.first, j = position.second;
	if (identity == BLACK) {//黑方
		//UP移動棋，不超過palace且路徑上是空格
		if (i - 1 > palaceBlackI_UP &&
			(boardStatus[i - 1][j] == 0)) {
			legalMove.push_back(make_pair(i - 1, j));
		}
		//DOWN
		if (i + 1 < palaceBlackI_DOWN &&
			(boardStatus[i + 1][j] == 0)) {
			legalMove.push_back(make_pair(i + 1, j));
		}
		//LEFT	
		if (j - 1 > palaceBlackJ_LEFT &&
			(boardStatus[i][j - 1] == 0)) {
			legalMove.push_back(make_pair(i, j - 1));
		}
		//RIGHT	
		if (j + 1 < palaceBlackJ_RIGHT &&
			(boardStatus[i][j + 1] == 0)) {
			legalMove.push_back(make_pair(i, j + 1));
		}
	}
	else if (identity == RED) {//紅方
		//UP
		if (i - 1 > palaceRedI_UP &&
			(boardStatus[i - 1][j] == 0)) {
			legalMove.push_back(make_pair(i - 1, j));
		}
		//DOWN
		if (i + 1 < palaceRedI_DOWN &&
			(boardStatus[i + 1][j] == 0)) {
			legalMove.push_back(make_pair(i + 1, j));
		}
		//LEFT	
		if (j - 1 > palaceRedJ_LEFT &&
			(boardStatus[i][j - 1] == 0)) {
			legalMove.push_back(make_pair(i, j - 1));
		}
		//RIGHT	
		if (j + 1 < palaceRedJ_RIGHT &&
			(boardStatus[i][j + 1] == 0)) {
			legalMove.push_back(make_pair(i, j + 1));
		}
	}
	return legalMove;
}
vector<COORDINATE> ClassGeneral::eatable(const vector<vector<int>> & boardStatus) {
	vector<COORDINATE> legalEat;
	int i = position.first, j = position.second;
	if (identity == BLACK) {//黑方
		//UP吃棋，不超過palace且路徑上是敵軍
		if (i - 1 > palaceBlackI_UP &&
			(boardStatus[i - 1][j] >= 8)) {
			legalEat.push_back(make_pair(i - 1, j));
		}
		//DOWN
		if (i + 1 < palaceBlackI_DOWN &&
			(boardStatus[i + 1][j] >= 8)) {
			legalEat.push_back(make_pair(i + 1, j));
		}
		//LEFT	
		if (j - 1 > palaceBlackJ_LEFT &&
			(boardStatus[i][j - 1] >= 8)) {
			legalEat.push_back(make_pair(i, j - 1));
		}
		//RIGHT	
		if (j + 1 < palaceBlackJ_RIGHT &&
			(boardStatus[i][j + 1] >= 8)) {
			legalEat.push_back(make_pair(i, j + 1));
		}
	}
	else if (identity == RED) {//紅方
		//UP
		if (i - 1 > palaceRedI_UP &&
			(boardStatus[i - 1][j] <= 7 && boardStatus[i - 1][j] > 0)) {
			legalEat.push_back(make_pair(i - 1, j));
		}
		//DOWN
		if (i + 1 < palaceRedI_DOWN &&
			(boardStatus[i + 1][j] <= 7 && boardStatus[i + 1][j] > 0)) {
			legalEat.push_back(make_pair(i + 1, j));
		}
		//LEFT	
		if (j - 1 > palaceRedJ_LEFT &&
			(boardStatus[i][j - 1] <= 7 && boardStatus[i][j - 1] > 0)) {
			legalEat.push_back(make_pair(i, j - 1));
		}
		//RIGHT	
		if (j + 1 < palaceRedJ_RIGHT &&
			(boardStatus[i][j + 1] <= 7 && boardStatus[i][j + 1] > 0)) {
			legalEat.push_back(make_pair(i, j + 1));
		}
	}
	return legalEat;
}
//===========================================================
vector<COORDINATE> ClassGuard::movable(const vector<vector<int>> & boardStatus) {
	vector<COORDINATE> legalMove;
	int i = position.first, j = position.second;
	if (identity == BLACK) {//黑方
		//UP-RIGHT移動棋，不超過palace且路徑上是空格
		if (i - 1 > palaceBlackI_UP && j + 1 < palaceBlackJ_RIGHT &&
			(boardStatus[i - 1][j + 1] == 0)) {
			legalMove.push_back(make_pair(i - 1, j + 1));
		}
		//DOWN-RIGHT
		if (i + 1 < palaceBlackI_DOWN && j + 1 < palaceBlackJ_RIGHT &&
			(boardStatus[i + 1][j + 1] == 0)) {
			legalMove.push_back(make_pair(i + 1, j + 1));
		}
		//DOWN-LEFT	
		if (i + 1 > palaceBlackI_DOWN && j - 1 > palaceBlackJ_LEFT &&
			(boardStatus[i + 1][j - 1] == 0)) {
			legalMove.push_back(make_pair(i + 1, j - 1));
		}
		//UP-LEFT	
		if (i - 1 < palaceBlackI_UP && j - 1 < palaceBlackJ_LEFT &&
			(boardStatus[i - 1][j - 1] == 0)) {
			legalMove.push_back(make_pair(i - 1, j - 1));
		}
	}
	else if (identity == RED) {//紅方
		//UP-RIGHT移動棋，不超過palace且路徑上是空格
		if (i - 1 > palaceRedI_UP && j + 1 < palaceRedJ_RIGHT &&
			(boardStatus[i - 1][j + 1] == 0)) {
			legalMove.push_back(make_pair(i - 1, j + 1));
		}
		//DOWN-RIGHT
		if (i + 1 < palaceRedI_DOWN && j + 1 < palaceRedJ_RIGHT &&
			(boardStatus[i + 1][j + 1] == 0)) {
			legalMove.push_back(make_pair(i + 1, j + 1));
		}
		//DOWN-LEFT	
		if (i + 1 > palaceRedI_DOWN && j - 1 > palaceRedJ_LEFT &&
			(boardStatus[i + 1][j - 1] == 0)) {
			legalMove.push_back(make_pair(i + 1, j - 1));
		}
		//UP-LEFT	
		if (i - 1 < palaceRedI_UP && j - 1 < palaceRedJ_LEFT &&
			(boardStatus[i - 1][j - 1] == 0)) {
			legalMove.push_back(make_pair(i - 1, j - 1));
		}
	}
	return legalMove;
}
vector<COORDINATE> ClassGuard::eatable(const vector<vector<int>> & boardStatus) {
	vector<COORDINATE> legalEat;
	int i = position.first, j = position.second;
	if (identity == BLACK) {//黑方
		//UP-RIGHT移動棋，不超過palace且路徑上是敵軍
		if (i - 1 > palaceBlackI_UP && j + 1 < palaceBlackJ_RIGHT &&
			(boardStatus[i - 1][j + 1] >= 8)) {
			legalEat.push_back(make_pair(i - 1, j + 1));
		}
		//DOWN-RIGHT
		if (i + 1 < palaceBlackI_DOWN && j + 1 < palaceBlackJ_RIGHT &&
			(boardStatus[i + 1][j + 1] >= 8)) {
			legalEat.push_back(make_pair(i + 1, j + 1));
		}
		//DOWN-LEFT	
		if (i + 1 > palaceBlackI_DOWN && j - 1 > palaceBlackJ_LEFT &&
			(boardStatus[i + 1][j - 1] >= 8)) {
			legalEat.push_back(make_pair(i + 1, j - 1));
		}
		//UP-LEFT	
		if (i - 1 < palaceBlackI_UP && j - 1 < palaceBlackJ_LEFT &&
			(boardStatus[i - 1][j - 1] >= 8)) {
			legalEat.push_back(make_pair(i - 1, j - 1));
		}
	}
	else if (identity == RED) {//紅方
		//UP-RIGHT移動棋，不超過palace且路徑上是空格
		if (i - 1 > palaceRedI_UP && j + 1 < palaceRedJ_RIGHT &&
			(boardStatus[i - 1][j + 1] > 0 && boardStatus[i - 1][j + 1] <= 7)) {
			legalEat.push_back(make_pair(i - 1, j + 1));
		}
		//DOWN-RIGHT
		if (i + 1 < palaceRedI_DOWN && j + 1 < palaceRedJ_RIGHT &&
			(boardStatus[i + 1][j + 1] > 0 && boardStatus[i + 1][j + 1] <= 7)) {
			legalEat.push_back(make_pair(i + 1, j + 1));
		}
		//DOWN-LEFT	
		if (i + 1 > palaceRedI_DOWN && j - 1 > palaceRedJ_LEFT &&
			(boardStatus[i + 1][j - 1] > 0 && boardStatus[i + 1][j - 1] <= 7)) {
			legalEat.push_back(make_pair(i + 1, j - 1));
		}
		//UP-LEFT	
		if (i - 1 < palaceRedI_UP && j - 1 < palaceRedJ_LEFT &&
			(boardStatus[i - 1][j - 1] > 0 && boardStatus[i - 1][j - 1] <= 7)) {
			legalEat.push_back(make_pair(i - 1, j - 1));
		}
	}
	return legalEat;
}
//===========================================================
