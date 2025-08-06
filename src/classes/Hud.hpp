#ifndef HUD_HPP
# define HUD_HPP
# include <iostream>

# include "MLX42.h"

# include "MenuHUD.hpp"
# include "GameHUD.hpp"
# include "Window.hpp"

class Hud
{
	private:
		Window	_window;
		MenuHUD	_menu;
		GameHUD	_game;

	public:
		Hud(Window &window);
		~Hud();
};

#endif
