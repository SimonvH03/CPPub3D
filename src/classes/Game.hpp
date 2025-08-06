#ifndef GAME_HPP
# define GAME_HPP
# include <iostream>
# include <fstream>
# include <filesystem>

# include "MLX42.h"
# include "Error.hpp"
# include "Parser.hpp"

# include "Window.hpp"
# include "Renderer.hpp"
# include "Scene.hpp"
# include "Hud.hpp"

class Game
{
	public:
		explicit Game(Window &window);
		~Game();

		bool	run();
		bool	loadLevel(const std::string& inputFile);

	private:
		void	addToTextureList(Window::Texture texture);

		Window		&_window;
		Scene		*_scene = nullptr;
		// Renderer	*_renderer = nullptr;
		// Hud			*_hud = nullptr;

		std::vector<Window::Texture>	_allocatedTextures;
		// bool		parseMap(std::vector<std::string>::const_iterator &iterator, std::vector<std::string>::const_iterator end);
};

#endif
