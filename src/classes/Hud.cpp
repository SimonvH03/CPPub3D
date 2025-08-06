#include "Hud.hpp"

Hud::Hud(Window &window) : _window(window)
{
	std::cout << "Hud Default Constructor\n";
}


Hud::~Hud()
{
	std::cout << "Hud Destructor\n";
}
