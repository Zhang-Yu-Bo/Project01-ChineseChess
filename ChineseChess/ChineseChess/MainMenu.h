#pragma once
#include <Windows.h>
#include <conio.h>
#include <string>
#include <iostream>
#include "Game.h"

using namespace std;

#ifndef _MAIN_MENU_
#define _MAIN_MENU_
extern const string mainMenu[5];
#endif // !_MAIN_MENU_


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
