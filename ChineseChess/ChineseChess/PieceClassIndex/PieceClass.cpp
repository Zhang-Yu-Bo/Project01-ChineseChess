#include "PieceClass.h"

vector<vector<Pieces*>> pieceStatus;
//===�N/��========================================================
vector<COORDINATE> ClassGeneral::movable(const vector<vector<int>>& boardStatus) {
	vector<COORDINATE> legalMove;
	int i = position.first, j = position.second;
	if (identity == BLACK) {//�¤�
		//UP���ʴѡA���W�Lpalace�B���|�W�O�Ů�
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
	else if (identity == RED) {//����
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
	if (identity == BLACK) {//�¤�
		//UP�Y�ѡA���W�Lpalace�B���|�W�O�ĭx
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
	else if (identity == RED) {//����
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
//===�h/�K========================================================
vector<COORDINATE> ClassGuard::movable(const vector<vector<int>> & boardStatus) {
	vector<COORDINATE> legalMove;
	int i = position.first, j = position.second;
	if (identity == BLACK) {//�¤�
		//UP-RIGHT���ʴѡA���W�Lpalace�B���|�W�O�Ů�
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
		if (i + 1 < palaceBlackI_DOWN && j - 1 > palaceBlackJ_LEFT &&
			(boardStatus[i + 1][j - 1] == 0)) {
			legalMove.push_back(make_pair(i + 1, j - 1));
		}
		//UP-LEFT	
		if (i - 1 > palaceBlackI_UP && j - 1 > palaceBlackJ_LEFT &&
			(boardStatus[i - 1][j - 1] == 0)) {
			legalMove.push_back(make_pair(i - 1, j - 1));
		}
	}
	else if (identity == RED) {//����
		//UP-RIGHT���ʴѡA���W�Lpalace�B���|�W�O�Ů�
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
		if (i + 1 < palaceRedI_DOWN && j - 1 > palaceRedJ_LEFT &&
			(boardStatus[i + 1][j - 1] == 0)) {
			legalMove.push_back(make_pair(i + 1, j - 1));
		}
		//UP-LEFT	
		if (i - 1 > palaceRedI_UP && j - 1 > palaceRedJ_LEFT &&
			(boardStatus[i - 1][j - 1] == 0)) {
			legalMove.push_back(make_pair(i - 1, j - 1));
		}
	}
	return legalMove;
}
vector<COORDINATE> ClassGuard::eatable(const vector<vector<int>> & boardStatus) {
	vector<COORDINATE> legalEat;
	int i = position.first, j = position.second;
	if (identity == BLACK) {//�¤�
		//UP-RIGHT���ʴѡA���W�Lpalace�B���|�W�O�ĭx
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
		if (i + 1 < palaceBlackI_DOWN && j - 1 > palaceBlackJ_LEFT &&
			(boardStatus[i + 1][j - 1] >= 8)) {
			legalEat.push_back(make_pair(i + 1, j - 1));
		}
		//UP-LEFT	
		if (i - 1 > palaceBlackI_UP && j - 1 > palaceBlackJ_LEFT &&
			(boardStatus[i - 1][j - 1] >= 8)) {
			legalEat.push_back(make_pair(i - 1, j - 1));
		}
	}
	else if (identity == RED) {//����
		//UP-RIGHT���ʴѡA���W�Lpalace�B���|�W�O�Ů�
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
		if (i + 1 < palaceRedI_DOWN && j - 1 > palaceRedJ_LEFT &&
			(boardStatus[i + 1][j - 1] > 0 && boardStatus[i + 1][j - 1] <= 7)) {
			legalEat.push_back(make_pair(i + 1, j - 1));
		}
		//UP-LEFT	
		if (i - 1 > palaceRedI_UP && j - 1 > palaceRedJ_LEFT &&
			(boardStatus[i - 1][j - 1] > 0 && boardStatus[i - 1][j - 1] <= 7)) {
			legalEat.push_back(make_pair(i - 1, j - 1));
		}
	}
	return legalEat;
}
//===�H/��========================================================
vector<COORDINATE> ClassMinister::movable(const vector<vector<int>>& boardStatus) {
	vector<COORDINATE> legalMove;
	int i = position.first, j = position.second;
	if (identity == BLACK) {//�¤�
		//UP-RIGHT���ʴѡA���L�e���W�u�B���|�W�O�Ů�
		if (i - 2 > boardTop && j + 2 < boardRight &&
			(boardStatus[i - 2][j + 2] == 0) && (boardStatus[i - 1][j + 1] == 0)) {
			legalMove.push_back(make_pair(i - 2, j + 2));
		}
		//DOWN-RIGHT
		if (i + 2 < riverBlack && j + 2 < boardRight &&
			(boardStatus[i + 2][j + 2] == 0) && (boardStatus[i + 1][j + 1] == 0)) {
			legalMove.push_back(make_pair(i + 2, j + 2));
		}
		//DOWN-LEFT	
		if (i + 2 < riverBlack && j - 2 > boardLeft &&
			(boardStatus[i + 2][j - 2] == 0) && (boardStatus[i + 1][j - 1] == 0)) {
			legalMove.push_back(make_pair(i + 2, j - 2));
		}
		//UP-LEFT	
		if (i - 2 > boardLeft && j - 2 > boardTop &&
			(boardStatus[i - 2][j - 2] == 0) && (boardStatus[i - 1][j - 1] == 0)) {
			legalMove.push_back(make_pair(i - 2, j - 2));
		}
	}
	else if (identity == RED) {//����
		//UP-RIGHT���ʴѡA���W�Lpalace�B���|�W�O�Ů�
		if (i - 2 > riverRed && j + 2 < boardRight &&
			(boardStatus[i - 2][j + 2] == 0) && (boardStatus[i - 1][j + 1] == 0)) {
			legalMove.push_back(make_pair(i - 2, j + 2));
		}
		//DOWN-RIGHT
		if (i + 2 < boardBottom && j + 2 < boardRight &&
			(boardStatus[i + 2][j + 2] == 0) && (boardStatus[i + 1][j + 1] == 0)) {
			legalMove.push_back(make_pair(i + 2, j + 2));
		}
		//DOWN-LEFT	
		if (i + 2 < boardBottom && j - 2 > boardLeft &&
			(boardStatus[i + 2][j - 2] == 0) && (boardStatus[i + 1][j - 1] == 0)) {
			legalMove.push_back(make_pair(i + 2, j - 2));
		}
		//UP-LEFT	
		if (i - 2 > riverRed && j - 2 > boardTop &&
			(boardStatus[i - 2][j - 2] == 0) && (boardStatus[i - 1][j - 1] == 0)) {
			legalMove.push_back(make_pair(i - 2, j - 2));
		}
	}
	return legalMove;
}
vector<COORDINATE> ClassMinister::eatable(const vector<vector<int>> & boardStatus) {
	vector<COORDINATE> legalEat;
	int i = position.first, j = position.second;
	if (identity == BLACK) {//�¤�
		//UP-RIGHT���ʴѡA���L�e���W�u�B���|�W�O�Ů�
		if (i - 2 > boardTop && j + 2 < boardRight &&
			(boardStatus[i - 2][j + 2] >= 8) && (boardStatus[i - 1][j + 1] == 0)) {
			legalEat.push_back(make_pair(i - 2, j + 2));
		}
		//DOWN-RIGHT
		if (i + 2 < riverBlack && j + 2 < boardRight &&
			(boardStatus[i + 2][j + 2] >= 8) && (boardStatus[i + 1][j + 1] == 0)) {
			legalEat.push_back(make_pair(i + 2, j + 2));
		}
		//DOWN-LEFT	
		if (i + 2 < riverBlack && j - 2 > boardLeft &&
			(boardStatus[i + 2][j - 2] >= 8) && (boardStatus[i + 1][j - 1] == 0)) {
			legalEat.push_back(make_pair(i + 2, j - 2));
		}
		//UP-LEFT	
		if (i - 2 > boardLeft && j - 2 > boardTop &&
			(boardStatus[i - 2][j - 2] >= 8) && (boardStatus[i - 1][j - 1] == 0)) {
			legalEat.push_back(make_pair(i - 2, j - 2));
		}
	}
	else if (identity == RED) {//����
		//UP-RIGHT���ʴѡA���W�Lpalace�B���|�W�O�Ů�
		if (i - 2 > riverRed && j + 2 < boardRight &&
			(boardStatus[i - 2][j + 2] > 0) && (boardStatus[i - 2][j + 2] <= 8) && (boardStatus[i - 1][j + 1] == 0)) {
			legalEat.push_back(make_pair(i - 2, j + 2));
		}
		//DOWN-RIGHT
		if (i + 2 < boardBottom && j + 2 < boardRight &&
			(boardStatus[i + 2][j + 2] > 0) && (boardStatus[i + 2][j + 2] <= 8) && (boardStatus[i + 1][j + 1] == 0)) {
			legalEat.push_back(make_pair(i + 2, j + 2));
		}
		//DOWN-LEFT	
		if (i + 2 < boardBottom && j - 2 > boardLeft &&
			(boardStatus[i + 2][j - 2] > 0) && (boardStatus[i + 2][j - 2] <= 8) && (boardStatus[i + 1][j - 1] == 0)) {
			legalEat.push_back(make_pair(i + 2, j - 2));
		}
		//UP-LEFT	
		if (i - 2 > riverRed && j - 2 > boardTop &&
			(boardStatus[i - 2][j - 2] > 0) && (boardStatus[i - 2][j - 2] <= 8) && (boardStatus[i - 1][j - 1] == 0)) {
			legalEat.push_back(make_pair(i - 2, j - 2));
		}
	}
	return legalEat;
}
//===========================================================
vector<COORDINATE> ClassRooks::movable(const vector<vector<int>>& boardStatus) {
	vector<COORDINATE> legalMove;
	int i = position.first, j = position.second;
	if (identity == BLACK) {//�¤�
		//UP���ʴѡA���W�Lpalace�B���|�W�O�Ů�
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
	else if (identity == RED) {//����
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
vector<COORDINATE> ClassRooks::eatable(const vector<vector<int>> & boardStatus) {
	vector<COORDINATE> legalEat;
	int i = position.first, j = position.second;
	if (identity == BLACK) {//�¤�
		//UP�Y�ѡA���W�Lpalace�B���|�W�O�ĭx
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
	else if (identity == RED) {//����
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
vector<COORDINATE> ClassHorses::movable(const vector<vector<int>>& boardStatus) {
	vector<COORDINATE> legalMove;
	int i = position.first, j = position.second;
	if (identity == BLACK) {//�¤�
		//UP���ʴѡA���W�Lpalace�B���|�W�O�Ů�
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
	else if (identity == RED) {//����
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
vector<COORDINATE> ClassHorses::eatable(const vector<vector<int>> & boardStatus) {
	vector<COORDINATE> legalEat;
	int i = position.first, j = position.second;
	if (identity == BLACK) {//�¤�
		//UP�Y�ѡA���W�Lpalace�B���|�W�O�ĭx
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
	else if (identity == RED) {//����
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
vector<COORDINATE> ClassCannons::movable(const vector<vector<int>>& boardStatus) {
	vector<COORDINATE> legalMove;
	int i = position.first, j = position.second;
	if (identity == BLACK) {//�¤�
		//UP���ʴѡA���W�Lpalace�B���|�W�O�Ů�
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
	else if (identity == RED) {//����
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
vector<COORDINATE> ClassCannons::eatable(const vector<vector<int>> & boardStatus) {
	vector<COORDINATE> legalEat;
	int i = position.first, j = position.second;
	if (identity == BLACK) {//�¤�
		//UP�Y�ѡA���W�Lpalace�B���|�W�O�ĭx
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
	else if (identity == RED) {//����
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
vector<COORDINATE> ClassSoldiers::movable(const vector<vector<int>>& boardStatus) {
	vector<COORDINATE> legalMove;
	int i = position.first, j = position.second;
	if (identity == BLACK) {//�¤�
		//UP���ʴѡA���W�Lpalace�B���|�W�O�Ů�
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
	else if (identity == RED) {//����
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
vector<COORDINATE> ClassSoldiers::eatable(const vector<vector<int>> & boardStatus) {
	vector<COORDINATE> legalEat;
	int i = position.first, j = position.second;
	if (identity == BLACK) {//�¤�
		//UP�Y�ѡA���W�Lpalace�B���|�W�O�ĭx
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
	else if (identity == RED) {//����
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