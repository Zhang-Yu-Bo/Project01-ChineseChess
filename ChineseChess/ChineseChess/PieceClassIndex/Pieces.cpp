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
	//=====================執行移棋=====================
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
	//=====================執行吃棋=====================
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
	//決定名稱
	bool pre = false, surf = false;//決定使用哪種綴詞
	switch (excutor) {
		//==BLACK==
	case 1:  name = "將"; break;
	case 2:  name = "士"; break;
	case 3:  name = "象"; break;
	case 4:  name = "車"; break;
	case 5:  name = "馬"; break;
	case 6:  name = "包"; break;
	case 7:  name = "卒"; break;
		//===RED===
	case 8:  name = "帥"; break;
	case 9:	 name = "仕"; break;
	case 10: name = "相"; break;
	case 11: name = "車"; break;
	case 12: name = "傌"; break;
	case 13: name = "炮"; break;
	case 14: name = "兵"; break;
	}
	if (!pre) {//不使用前綴，即同欄內無同種棋
		surf = true;
		//黑方改全形、紅方改國字(欄相反)
		if (color == RED)//紅方
			surffix = NumberTransform(excutor, 10 - departure.second);
		else
			surffix = NumberTransform(excutor, departure.second);
	}
	if (departure.first < destination.first) {//由上往下移
		if (color == BLACK) {//黑方
			action = "進";
		}
		else if (color == RED) {//紅方
			action = "退";
		}
	}
	else if (departure.first > destination.first) {//由下往上移
		if (color == BLACK) {//黑方
			action = "退";
		}
		else if (color == RED) {//紅方
			action = "進";
		}
	}
	else {//水平移動
		action = "平";
	}
	if (departure.second == destination.second) {//垂直移動
		delta = NumberTransform(excutor, abs(departure.first - destination.first));
	}
	else {
		if (color == RED)//紅方
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
	if (excutor >= 1 && excutor <= 7) {//黑方
		switch (n) {
		case 1: str = "１"; break;
		case 2: str = "２"; break;
		case 3: str = "３"; break;
		case 4: str = "４"; break;
		case 5: str = "５"; break;
		case 6: str = "６"; break;
		case 7: str = "７"; break;
		case 8: str = "８"; break;
		case 9: str = "９"; break;
		default: break;
		}
	}
	else if (excutor >= 8 && excutor <= 14) {//紅方
		switch (n) {
		case 1: str = "一"; break;
		case 2: str = "二"; break;
		case 3: str = "三"; break;
		case 4: str = "四"; break;
		case 5: str = "五"; break;
		case 6: str = "六"; break;
		case 7: str = "七"; break;
		case 8: str = "八"; break;
		case 9: str = "九"; break;
		default: break;
		}
	}
	return str;
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