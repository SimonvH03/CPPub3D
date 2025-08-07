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
		enum class View
		{
			Menu,
			Settings,
			Level
		};

		explicit Game(Window &window);
		~Game();

		bool	run();
		bool	loadLevel(const std::string& inputFile);

		Window const	&getWindow() const;
		Scene const		&getScene() const;
		View			getView() const;

	private:
		Window		&_window;
		Scene		*_scene = nullptr;
		// Renderer	*_renderer = nullptr;
		// Hud			*_hud = nullptr;
		View		_view;

		std::vector<Window::Texture>	_allocatedTextures;
		void	addToTextureList(std::initializer_list<Window::Texture> textures);
		void	clearTextureList();
};

#endif
