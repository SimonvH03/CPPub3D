#include "MenuHUD.hpp"

MenuHUD::MenuHUD()
{
	std::cout << "MenuHUD Default Constructor\n";
}

MenuHUD::MenuHUD(MenuHUD const &original)
{
	std::cout << "MenuHUD Copy Constructor\n";
	*this = original;
}

MenuHUD &MenuHUD::operator=(MenuHUD const &original)
{
	std::cout << "MenuHUD Assignment Operator\n";
	if (this != &original)
	{
	}
	return (*this);
}

MenuHUD::~MenuHUD()
{
	std::cout << "MenuHUD Destructor\n";
}
