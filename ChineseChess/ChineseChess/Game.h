#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

static CONSOLE_SCREEN_BUFFER_INFO csbi;
static CONSOLE_CURSOR_INFO cci;
static HANDLE handle;
static COORD cursorPosition;


#ifndef _GAME_MENU_
#define	_GAME_MENU_
extern string gameMenu[5];
#endif // !_GAME_MENU_

class Game
{
public:
	Game();
	~Game();
	void gameStart();
	void initalizateGame();
	void showMenu();
private:

};