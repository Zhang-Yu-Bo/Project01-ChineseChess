#pragma once
#include <Windows.h>
#include <conio.h>
#include <string>
#include <iostream>
#include <direct.h>
#include "Game.h"

using namespace std;

#ifndef _MAIN_MENU_OPTION_
#define _MAIN_MENU_OPTION_
extern const string mainMenuOption[7];
#endif // !_MAIN_MENU_OPTION_


#ifndef _MAIN_MENU_H_
#define _MAIN_MENU_H_
class MainMenu
{
public:
	MainMenu();
	~MainMenu();
	void showMenu();
	string showFiles();
private:
	
};

extern MainMenu* menu;
#endif // !_MAIN_MENU_H_
