#include "MainMenu.h"

namespace {
	
}

MainMenu::MainMenu()
{
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	cursorPosition.X = 0;	cursorPosition.Y = 0;
	SetConsoleCursorPosition(handle, cursorPosition);
}

void MainMenu::showMenu() {

}

MainMenu::~MainMenu()
{

}

void MainMenu::cursorVisiable(bool flag) {
	GetConsoleCursorInfo(handle, &cci);
	cci.bVisible = flag;
	SetConsoleCursorInfo(handle, &cci);
}
void MainMenu::setConsoleCursorCoordinate(int x = 42, int y = 2) {
	cursorPosition.X = x;	cursorPosition.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}