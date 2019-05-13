#include "Pieces.h"

vector<COORDINATE> Pieces::movable(const vector<vector<int>>&) {
	return vector<COORDINATE>();
}

vector<COORDINATE> Pieces::eatable(const vector<vector<int>>&) {
	return vector<COORDINATE>();
}

bool Pieces::MoveAndEat(COORDINATE destination, vector<vector<int>>& boardStatus, vector<vector<Pieces*>>& pieceStatus ,string& chineseNotation) {
	int excutor;
	COORDINATE departure;
	bool legalAction = false;
	vector<COORDINATE> movePosition = movable(boardStatus);
	vector<COORDINATE> eatPosition = eatable(boardStatus);
	auto move = find(begin(movePosition), end(movePosition), destination);
	auto eat = find(begin(eatPosition), end(eatPosition), destination);
	//=====================���沾��=====================
	if (move != movePosition.end()) {
		departure = position;
		excutor = pieceStatus[position.first][position.second]->code;
		chineseNotation = ChineseNotation(departure, destination, boardStatus, excutor);
		boardStatus[position.first][position.second] = 0;
		pieceStatus[destination.first][destination.second] = pieceStatus[position.first][position.second];
		pieceStatus[position.first][position.second] = NULL;
		boardStatus[destination.first][destination.second] = code;

		position = destination;
		legalAction = true;
	}
	//=====================����Y��=====================
	else if (eat != eatPosition.end()) {
		departure = position;
		excutor = pieceStatus[position.first][position.second]->code;
		chineseNotation = ChineseNotation(departure, destination, boardStatus, excutor);
		pieceStatus[destination.first][destination.second]->alive = false;
		boardStatus[position.first][position.second] = 0;
		pieceStatus[destination.first][destination.second] = pieceStatus[position.first][position.second];
		pieceStatus[position.first][position.second] = NULL;
		boardStatus[destination.first][destination.second] = code;

		position = destination;
		legalAction = true;
	}
	return legalAction;
}

string Pieces::ChineseNotation(const COORDINATE& departure, const COORDINATE& destination, const vector<vector<int>>& boardStatus, const int& excutor) {
	string prefix, name, surffix, action, delta;
	int countAbove = 0, countBeneath = 0;
	bool color;
	if (excutor >= 1 && excutor <= 7) color = BLACK;
	else color = RED;
	//�M�w�W��
	bool pre = false, surf = false;//�M�w�ϥέ��غ��
	switch (excutor) {
		//==BLACK==
	case 1:  name = "�N"; break;
	case 2:  name = "�h"; break;
	case 3:  name = "�H"; break;
	case 4:  name = "��"; break;
	case 5:  name = "��"; break;
	case 6:  name = "�]"; break;
	case 7:  name = "��"; break;
		//===RED===
	case 8:  name = "��"; break;
	case 9:	 name = "�K"; break;
	case 10: name = "��"; break;
	case 11: name = "��"; break;
	case 12: name = "�X"; break;
	case 13: name = "��"; break;
	case 14: name = "�L"; break;
	}
	if (!pre) {//���ϥΫe��A�Y�P�椺�L�P�ش�
		surf = true;
		//�¤����ΡB������r(��ۤ�)
		if (color == RED)//����
			surffix = NumberTransform(excutor, 10 - departure.second);
		else
			surffix = NumberTransform(excutor, departure.second);
	}
	if (departure.first < destination.first) {//�ѤW���U��
		if (color == BLACK) {//�¤�
			action = "�i";
		}
		else if (color == RED) {//����
			action = "�h";
		}
	}
	else if (departure.first > destination.first) {//�ѤU���W��
		if (color == BLACK) {//�¤�
			action = "�h";
		}
		else if (color == RED) {//����
			action = "�i";
		}
	}
	else {//��������
		action = "��";
	}
	if (departure.second == destination.second) {//��������
		delta = NumberTransform(excutor, abs(departure.first - destination.first));
	}
	else {
		if (color == RED)//����
			delta = NumberTransform(excutor, 10 - destination.second);
		else
			delta = NumberTransform(excutor, destination.second);
	}
	if (pre) {
		return prefix + name + action + delta;
	}
	else {
		return name + surffix + action + delta;
	}
}

string Pieces::NumberTransform(const int excutor, const int n) {
	string str;
	if (excutor >= 1 && excutor <= 7) {//�¤�
		switch (n) {
		case 1: str = "��"; break;
		case 2: str = "��"; break;
		case 3: str = "��"; break;
		case 4: str = "��"; break;
		case 5: str = "��"; break;
		case 6: str = "��"; break;
		case 7: str = "��"; break;
		case 8: str = "��"; break;
		case 9: str = "��"; break;
		default: break;
		}
	}
	else if (excutor >= 8 && excutor <= 14) {//����
		switch (n) {
		case 1: str = "�@"; break;
		case 2: str = "�G"; break;
		case 3: str = "�T"; break;
		case 4: str = "�|"; break;
		case 5: str = "��"; break;
		case 6: str = "��"; break;
		case 7: str = "�C"; break;
		case 8: str = "�K"; break;
		case 9: str = "�E"; break;
		default: break;
		}
	}
	return str;
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