#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include <Windows.h>
#include <vector>
#include <string>
#include <iostream>
#include "Defines.h"

class MenuScreen
{
public:
	MenuScreen();
	MenuScreen(std::string sHeader, std::vector<std::string> items);
	int Show();
private:
	int activeItem_;
	int itemsAmount_;
	void increaseActiveItem();
	void decreaseActiveItem();
	std::string header_;
	std::vector<std::string> menuItems_;
};
#endif
