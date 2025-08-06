#include "GameHUD.hpp"

GameHUD::GameHUD()
{
	std::cout << "GameHUD Default Constructor\n";
}

GameHUD::GameHUD(GameHUD const &original)
{
	std::cout << "GameHUD Copy Constructor\n";
	*this = original;
}

GameHUD &GameHUD::operator=(GameHUD const &original)
{
	std::cout << "GameHUD Assignment Operator\n";
	if (this != &original)
	{
	}
	return (*this);
}

GameHUD::~GameHUD()
{
	std::cout << "GameHUD Destructor\n";
}
