#pragma once
#include <Windows.h>
#include <conio.h>
#include <string>
#include <iostream>
#include "Game.h"

using namespace std;

#ifndef _MAIN_MENU_H_
#define _MAIN_MENU_H_
class MainMenu
{
public:
	MainMenu();
	~MainMenu();
	void showMenu();
private:
	HANDLE handle;
	COORD cursorPosition;
	CONSOLE_CURSOR_INFO cci;
	void cursorVisiable(bool);
	void setConsoleCursorCoordinate(int, int);
	void setColor(int, int);
	const string mainMenu[5] = {
		"／」」」」」」」」」」」」」」」／\n",
		"●�@�@�@�@�@＠�}�l�C生�@�@�@�@�@●\n",
		"●」」」」」」」」」」」」」」」●\n",
		"●�@�@�@�@�@�@飢���{Α�@�@�@�@�@●\n",
		"ゞ」」」」」」」」」」」」」」」ゞ"
	};
};

#endif // !_MAIN_MENU_H_
