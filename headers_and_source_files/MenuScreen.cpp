#include "MenuScreen.h"

MenuScreen::MenuScreen()
{}
MenuScreen::MenuScreen(std::string sHeader, std::vector<std::string> items)
	:header_(sHeader),
	menuItems_(items),
	itemsAmount_(items.size()),
	activeItem_(0)
{}
void MenuScreen::increaseActiveItem()
{
	if (activeItem_ < itemsAmount_ - 1)
		activeItem_++;
	else if(activeItem_ == itemsAmount_ - 1)
	{
		activeItem_ = 0;
	}
}
void MenuScreen::decreaseActiveItem()
{
	if (activeItem_ > 0)
		activeItem_--;
	else if (activeItem_ == 0)
	{
		activeItem_ = itemsAmount_ - 1;
	}
}
int MenuScreen::Show()
{
	while (true)
	{
		system("cls");
		std::cout << "\n\n\n          " << header_ << "\n\n";
		for (int i = 0; i < itemsAmount_; i++)
			std::cout <<"          "<<(activeItem_ == i ? '>' : ' ')<< menuItems_[i] << '\n';

		if (GetAsyncKeyState(VK_DOWN))
			increaseActiveItem();
		if (GetAsyncKeyState(VK_UP))
			decreaseActiveItem();
		if (GetAsyncKeyState(VK_RETURN))
			return activeItem_;

		Sleep(SCREEN_SLEEP);
	}
}