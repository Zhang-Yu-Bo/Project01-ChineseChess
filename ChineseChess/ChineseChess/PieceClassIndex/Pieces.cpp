#include "Pieces.h"

Pieces::Pieces(int i, int j, bool) {

}

vector<COORDINATE> Pieces::movable() {
	return vector<COORDINATE>();
}

vector<COORDINATE> Pieces::eatable() {
	return vector<COORDINATE>();
}

bool Pieces::moveAndEat(COORDINATE position) {
	return true;
}