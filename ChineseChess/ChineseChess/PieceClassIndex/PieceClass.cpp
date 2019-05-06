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
vector<COORDINATE> ClassRook::movable(const vector<vector<int>>& boardStatus) {
	vector<COORDINATE> legalMove;
	int i = position.first, j = position.second, k = 1;
	if (identity == BLACK) {//�¤�
		//UP���ʴѡA���W�L��ɥB���|�W�O�Ů�
		k = 1;
		while (i - k > boardTop &&
			(boardStatus[i - k][j] == 0)) {
			legalMove.push_back(make_pair(i - k, j));
			k++;
		}
		//DOWN
		k = 1;
		while (i + k < boardBottom &&
			(boardStatus[i + k][j] == 0)) {
			legalMove.push_back(make_pair(i + k, j));
			k++;
		}
		//LEFT
		k = 1;
		while (j - k > boardLeft &&
			(boardStatus[i][j - k] == 0)) {
			legalMove.push_back(make_pair(i, j - k));
			k++;
		}
		//RIGHT	
		k = 1;
		while (j + k < boardRight &&
			(boardStatus[i][j + k] == 0)) {
			legalMove.push_back(make_pair(i, j + k));
			k++;
		}
	}
	else if (identity == RED) {//����
		//UP
		k = 1;
		while (i - k > boardTop &&
			(boardStatus[i - k][j] == 0)) {
			legalMove.push_back(make_pair(i - k, j));
			k++;
		}
		//DOWN
		k = 1;
		while (i + k < boardBottom &&
			(boardStatus[i + k][j] == 0)) {
			legalMove.push_back(make_pair(i + k, j));
			k++;
		}
		//LEFT	
		k = 1;
		while (j - k > boardLeft &&
			(boardStatus[i][j - k] == 0)) {
			legalMove.push_back(make_pair(i, j - k));
			k++;
		}
		//RIGHT	
		k = 1;
		while (j + k < boardRight &&
			(boardStatus[i][j + k] == 0)) {
			legalMove.push_back(make_pair(i, j + k));
			k++;
		}
	}
	return legalMove;
}
vector<COORDINATE> ClassRook::eatable(const vector<vector<int>> & boardStatus) {
	vector<COORDINATE> legalEat;
	int i = position.first, j = position.second, k = 1;
	if (identity == BLACK) {//�¤�
		//UP���ʴ�
		k = 1;
		while (i - k > boardTop &&
			(boardStatus[i - k][j] == 0)) {
			k++;
		}
		if (boardStatus[i - k][j] >= 8) legalEat.push_back(make_pair(i - k, j));
		//DOWN
		k = 1;
		while (i + k < boardBottom &&
			(boardStatus[i + k][j] == 0)) {
			k++;
		}
		if (boardStatus[i + k][j] >= 8) legalEat.push_back(make_pair(i + k, j));
		//LEFT
		k = 1;
		while (j - k > boardLeft &&
			(boardStatus[i][j - k] == 0)) {
			k++;
		}
		if (boardStatus[i][j - k] >= 8) legalEat.push_back(make_pair(i, j - k));
		//RIGHT	
		k = 1;
		while (j + k < boardRight &&
			(boardStatus[i][j + k] == 0)) {
			k++;
		}
		if (boardStatus[i][j + k] >= 8) legalEat.push_back(make_pair(i, j + k));
	}
	else if (identity == RED) {//����
		//UP
		k = 1;
		while (i - k > boardTop &&
			(boardStatus[i - k][j] == 0)) {
			k++;
		}
		if (boardStatus[i - k][j] <= 7 && boardStatus[i - k][j] >= 1) legalEat.push_back(make_pair(i - k, j));
		//DOWN
		k = 1;
		while (i + k < boardBottom &&
			(boardStatus[i + k][j] == 0)) {
			k++;
		}
		if (boardStatus[i + k][j] <= 7 && boardStatus[i + k][j] >= 1) legalEat.push_back(make_pair(i + k, j));
		//LEFT	
		k = 1;
		while (j - k > boardLeft &&
			(boardStatus[i][j - k] == 0)) {
			k++;
		}
		if (boardStatus[i][j - k] <= 7 && boardStatus[i][j - k] >= 1) legalEat.push_back(make_pair(i, j - k));
		//RIGHT	
		k = 1;
		while (j + k < boardRight &&
			(boardStatus[i][j + k] == 0)) {
			k++;
		}
		if (boardStatus[i][j + k] <= 7 && boardStatus[i][j + k] >= 1) legalEat.push_back(make_pair(i, j + k));
	}
	return legalEat;
}
//===========================================================
vector<COORDINATE> ClassHorse::movable(const vector<vector<int>>& boardStatus) {
	vector<COORDINATE> legalMove;
	int i = position.first, j = position.second;
	if ((i - 1) >= 1 && (i - 1) <= 10 && j >= 1 && j <= 9) {									//�W��
		if (boardStatus[i - 1][j] == 0) {
			if ((i - 2) >= 1 && (i - 2) <= 10 && (j - 1) >= 1 && (j - 1) <= 9) {				//�W�G��
				if (boardStatus[i - 2][j - 1] == 0)
					legalMove.push_back(make_pair(i - 2, j - 1));
			}
			if ((i - 2) >= 1 && (i - 2) <= 10 && (j + 1) >= 1 && (j + 1) <= 9) {				//�W�G�k
				if (boardStatus[i - 2][j + 1] == 0)
					legalMove.push_back(make_pair(i - 2, j + 1));
			}
		}
	}
	if ((i + 1) >= 1 && (i + 1) <= 10 && j >= 1 && j <= 9) {									//�U��
		if (boardStatus[i + 1][j] == 0) {
			if ((i + 2) >= 1 && (i + 2) <= 10 && (j - 1) >= 1 && (j - 1) <= 9) {				//�U�G��
				if (boardStatus[i + 2][j - 1] == 0)
					legalMove.push_back(make_pair(i + 2, j - 1));
			}
			if ((i + 2) >= 1 && (i + 2) <= 10 && (j + 1) >= 1 && (j + 1) <= 9) {				//�U�G�k
				if (boardStatus[i + 2][j + 1] == 0)
					legalMove.push_back(make_pair(i + 2, j + 1));
			}
		}
	}
	if (i >= 1 && i <= 10 && (j - 1) >= 1 && (j - 1) <= 9) {									//����
		if (boardStatus[i][j - 1] == 0) {
			if ((i - 1) >= 1 && (i - 1) <= 10 && (j - 2) >= 1 && (j - 2) <= 9) {				//�W���G
				if (boardStatus[i - 1][j - 2] == 0)
					legalMove.push_back(make_pair(i - 1, j - 2));
			}
			if ((i + 1) >= 1 && (i + 1) <= 10 && (j - 2) >= 1 && (j - 2) <= 9) {				//�U���G
				if (boardStatus[i + 1][j - 2] == 0)
					legalMove.push_back(make_pair(i + 1, j - 2));
			}
		}
	}
	if (i >= 1 && i <= 10 && (j + 1) >= 1 && (j + 1) <= 9) {									//�k��
		if (boardStatus[i][j + 1] == 0) {
			if ((i - 1) >= 1 && (i - 1) <= 10 && (j + 2) >= 1 && (j + 2) <= 9) {				//�W�k�G
				if (boardStatus[i - 1][j + 2] == 0)
					legalMove.push_back(make_pair(i - 1, j + 2));
			}
			if ((i + 1) >= 1 && (i + 1) <= 10 && (j + 2) >= 1 && (j + 2) <= 9) {				//�U�k�G
				if (boardStatus[i + 1][j + 2] == 0)
					legalMove.push_back(make_pair(i + 1, j + 2));
			}
		}
	}
	return legalMove;
}
vector<COORDINATE> ClassHorse::eatable(const vector<vector<int>>& boardStatus) {
	vector<COORDINATE> legalEat;
	int i = position.first, j = position.second;
	int lowBound = 0, upBound = 0;
	if (identity == BLACK) {//�¤�
		lowBound = 8;	upBound = 14;
	}
	else if (identity == RED) {//����
		lowBound = 1;	upBound = 7;
	}
	if ((i - 1) >= 1 && (i - 1) <= 10 && j >= 1 && j <= 9) {									//�W��
		if (boardStatus[i - 1][j] == 0) {
			if ((i - 2) >= 1 && (i - 2) <= 10 && (j - 1) >= 1 && (j - 1) <= 9) {				//�W�G��
				if (boardStatus[i - 2][j - 1] >= lowBound && boardStatus[i - 2][j - 1] <= upBound)
					legalEat.push_back(make_pair(i - 2, j - 1));
			}
			if ((i - 2) >= 1 && (i - 2) <= 10 && (j + 1) >= 1 && (j + 1) <= 9) {				//�W�G�k
				if (boardStatus[i - 2][j + 1] >= lowBound && boardStatus[i - 2][j + 1] <= upBound)
					legalEat.push_back(make_pair(i - 2, j + 1));
			}
		}
	}
	if ((i + 1) >= 1 && (i + 1) <= 10 && j >= 1 && j <= 9) {									//�U��
		if (boardStatus[i + 1][j] == 0) {
			if ((i + 2) >= 1 && (i + 2) <= 10 && (j - 1) >= 1 && (j - 1) <= 9) {				//�U�G��
				if (boardStatus[i + 2][j - 1] >= lowBound && boardStatus[i + 2][j - 1] <= upBound)
					legalEat.push_back(make_pair(i + 2, j - 1));
			}
			if ((i + 2) >= 1 && (i + 2) <= 10 && (j + 1) >= 1 && (j + 1) <= 9) {				//�U�G�k
				if (boardStatus[i + 2][j + 1] >= lowBound && boardStatus[i + 2][j + 1] <= upBound)
					legalEat.push_back(make_pair(i + 2, j + 1));
			}
		}
	}
	if (i >= 1 && i <= 10 && (j - 1) >= 1 && (j - 1) <= 9) {									//����
		if (boardStatus[i][j - 1] == 0) {
			if ((i - 1) >= 1 && (i - 1) <= 10 && (j - 2) >= 1 && (j - 2) <= 9) {				//�W���G
				if (boardStatus[i - 1][j - 2] >= lowBound && boardStatus[i - 1][j - 2] <= upBound)
					legalEat.push_back(make_pair(i - 1, j - 2));
			}
			if ((i + 1) >= 1 && (i + 1) <= 10 && (j - 2) >= 1 && (j - 2) <= 9) {				//�U���G
				if (boardStatus[i + 1][j - 2] >= lowBound && boardStatus[i + 1][j - 2] <= upBound)
					legalEat.push_back(make_pair(i + 1, j - 2));
			}
		}
	}
	if (i >= 1 && i <= 10 && (j + 1) >= 1 && (j + 1) <= 9) {									//�k��
		if (boardStatus[i][j + 1] == 0) {
			if ((i - 1) >= 1 && (i - 1) <= 10 && (j + 2) >= 1 && (j + 2) <= 9) {				//�W�k�G
				if (boardStatus[i - 1][j + 2] >= lowBound && boardStatus[i - 1][j + 2] <= upBound)
					legalEat.push_back(make_pair(i - 1, j + 2));
			}
			if ((i + 1) >= 1 && (i + 1) <= 10 && (j + 2) >= 1 && (j + 2) <= 9) {				//�U�k�G
				if (boardStatus[i + 1][j + 2] >= lowBound && boardStatus[i + 1][j + 2] <= upBound)
					legalEat.push_back(make_pair(i + 1, j + 2));
			}
		}
	}
	return legalEat;
}
//===========================================================
vector<COORDINATE> ClassCannon::movable(const vector<vector<int>>& boardStatus) {
	vector<COORDINATE> legalMove;
	int i = position.first, j = position.second, k = 1;
	if (identity == BLACK) {//�¤�
		//UP���ʴѡA���W�L��ɥB���|�W�O�Ů�
		k = 1;
		while (i - k > boardTop &&
			(boardStatus[i - k][j] == 0)) {
			legalMove.push_back(make_pair(i - k, j));
			k++;
		}
		//DOWN
		k = 1;
		while (i + k < boardBottom &&
			(boardStatus[i + k][j] == 0)) {
			legalMove.push_back(make_pair(i + k, j));
			k++;
		}
		//LEFT
		k = 1;
		while (j - k > boardLeft &&
			(boardStatus[i][j - k] == 0)) {
			legalMove.push_back(make_pair(i, j - k));
			k++;
		}
		//RIGHT	
		k = 1;
		while (j + k < boardRight &&
			(boardStatus[i][j + k] == 0)) {
			legalMove.push_back(make_pair(i, j + k));
			k++;
		}
	}
	else if (identity == RED) {//����
		//UP
		k = 1;
		while (i - k > boardTop &&
			(boardStatus[i - k][j] == 0)) {
			legalMove.push_back(make_pair(i - k, j));
			k++;
		}
		//DOWN
		k = 1;
		while (i + k < boardBottom &&
			(boardStatus[i + k][j] == 0)) {
			legalMove.push_back(make_pair(i + k, j));
			k++;
		}
		//LEFT	
		k = 1;
		while (j - k > boardLeft &&
			(boardStatus[i][j - k] == 0)) {
			legalMove.push_back(make_pair(i, j - k));
			k++;
		}
		//RIGHT	
		k = 1;
		while (j + k < boardRight &&
			(boardStatus[i][j + k] == 0)) {
			legalMove.push_back(make_pair(i, j + k));
			k++;
		}
	}
	return legalMove;
}
vector<COORDINATE> ClassCannon::eatable(const vector<vector<int>> & boardStatus) {
	vector<COORDINATE> legalEat;
	int i = position.first, j = position.second, k = 1;
	if (identity == BLACK) {//�¤�
		//UP���ʴ�
		k = 1;
		while (i - k > boardTop &&
			(boardStatus[i - k][j] == 0)) {
			k++;
		}
		if (boardStatus[i - k][j] != -1) {
			k++;
			while (i - k > boardTop &&
				(boardStatus[i - k][j] == 0)) {
				k++;
			}
			if (boardStatus[i - k][j] >= 8) legalEat.push_back(make_pair(i - k, j));
		}
		//DOWN
		k = 1;
		while (i + k < boardBottom &&
			(boardStatus[i + k][j] == 0)) {
			k++;
		}
		if (boardStatus[i + k][j] != -1) {
			k++;
			while (i + k < boardBottom &&
				(boardStatus[i + k][j] == 0)) {
				k++;
			}
			if (boardStatus[i + k][j] >= 8) legalEat.push_back(make_pair(i + k, j));
		}
		//LEFT
		k = 1;
		while (j - k > boardLeft &&
			(boardStatus[i][j - k] == 0)) {
			k++;
		}
		if (boardStatus[i][j - k] != -1) {
			k++;
			while (j - k > boardLeft &&
				(boardStatus[i][j - k] == 0)) {
				k++;
			}
			if (boardStatus[i][j - k] >= 8) legalEat.push_back(make_pair(i, j - k));
		}
		//RIGHT	
		k = 1;
		while (j + k < boardRight &&
			(boardStatus[i][j + k] == 0)) {
			k++;
		}
		if (boardStatus[i][j + k] != -1) {
			k++;
			while (j + k < boardRight &&
				(boardStatus[i][j + k] == 0)) {
				k++;
			}
			if (boardStatus[i][j + k] >= 8) legalEat.push_back(make_pair(i, j + k));
		}
	}
	else if (identity == RED) {//����
		//UP
		k = 1;
		while (i - k > boardTop &&
			(boardStatus[i - k][j] == 0)) {
			k++;
		}
		if (boardStatus[i - k][j] != -1) {
			k++;
			while (i - k > boardTop &&
				(boardStatus[i - k][j] == 0)) {
				k++;
			}
			if (boardStatus[i - k][j] <= 7 && boardStatus[i - k][j] >= 1) legalEat.push_back(make_pair(i - k, j));
		}
		//DOWN
		k = 1;
		while (i + k < boardBottom &&
			(boardStatus[i + k][j] == 0)) {
			k++;
		}
		if (boardStatus[i + k][j] != -1) {
			k++;
			while (i + k < boardBottom &&
				(boardStatus[i + k][j] == 0)) {
				k++;
			}
			if (boardStatus[i + k][j] <= 7 && boardStatus[i + k][j] >= 1) legalEat.push_back(make_pair(i + k, j));
		}
		//LEFT	
		k = 1;
		while (j - k > boardLeft &&
			(boardStatus[i][j - k] == 0)) {
			k++;
		}
		if (boardStatus[i][j - k] != -1) {
			k++;
			while (j - k > boardLeft &&
				(boardStatus[i][j - k] == 0)) {
				k++;
			}
			if (boardStatus[i][j - k] <= 7 && boardStatus[i][j - k] >= 1) legalEat.push_back(make_pair(i, j - k));
		}
		//RIGHT	
		k = 1;
		while (j + k < boardRight &&
			(boardStatus[i][j + k] == 0)) {
			k++;
		}
		if (boardStatus[i][j + k] != -1) {
			k++;
			while (j + k < boardRight &&
				(boardStatus[i][j + k] == 0)) {
				k++;
			}
			if (boardStatus[i][j + k] <= 7 && boardStatus[i][j + k] >= 1) legalEat.push_back(make_pair(i, j + k));
		}
	}
	return legalEat;
}
//===========================================================
vector<COORDINATE> ClassSoldier::movable(const vector<vector<int>>& boardStatus) {
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
vector<COORDINATE> ClassSoldier::eatable(const vector<vector<int>> & boardStatus) {
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