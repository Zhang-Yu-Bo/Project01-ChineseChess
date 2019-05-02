#pragma once
#include <Windows.h>
#include <conio.h>

#ifndef _MAIN_MENU_H_
#define _MAIN_MENU_H_
class MainMenu
{
public:
	MainMenu();
	~MainMenu();
	void showMenu();
	void cursorVisiable(bool);
	void setConsoleCursorCoordinate(int, int);
private:
	HANDLE handle;
	COORD cursorPosition;
	CONSOLE_CURSOR_INFO cci;
};

#endif // !_MAIN_MENU_H_
