#ifndef GAME_HPP
# define GAME_HPP
# include <iostream>
# include <fstream>
# include <filesystem>

# include "MLX42.h"
# include "Error.hpp"
# include "Parser.hpp"

# include "Window.hpp"
# include "PressedKeys.hpp"
# include "Scene.hpp"
# include "Hud.hpp"

# include "Renderer.hpp"
# include "Physicer.hpp"

class Game
{
	public:
		Game(Window &window);
		~Game();

		bool	run();
		bool	loadLevel(const std::string& inputFile);

		enum class View
		{
			MainMenu,
			// Settings,
			// LevelSelection,
			Play,
			// Pause,
		};

	private:
		Window		&_window;
		Scene		*_scene = nullptr;
		Renderer	*_renderer = nullptr;
		Physicer	*_physicer = nullptr;
		// Hud			*_hud = nullptr;
		View		_view = View::Play;
		PressedKeys	_pressedKeys;

		std::vector<Window::Texture>	_allocatedTextures;
		void	addToTextureList(std::initializer_list<Window::Texture> textures);
		void	clearTextureList();

		void	keyHook(Window::KeyData keyData);
		void	sync();
		void	update();

		void	updateMainMenu();
		void	updatePlay();
};

#endif
