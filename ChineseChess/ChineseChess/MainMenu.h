#pragma once
#include <Windows.h>
#include <conio.h>
#include <string>
#include <iostream>
#include "Game.h"

using namespace std;

#ifndef _MAIN_MENU_OPTION_
#define _MAIN_MENU_OPTION_
extern const string mainMenuOption[5];
#endif // !_MAIN_MENU_OPTION_


#ifndef _MAIN_MENU_H_
#define _MAIN_MENU_H_
class MainMenu
{
public:
	MainMenu();
	~MainMenu();
	void showMenu();
private:
	
};

extern MainMenu* menu;
#endif // !_MAIN_MENU_H_
