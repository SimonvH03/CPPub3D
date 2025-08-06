#ifndef SCENE_HPP
# define SCENE_HPP
# include <iostream>
# include <string_view>
# include <vector>
# include <fstream>

# include "MLX42.h"

# include "Textures.hpp"
# include "Parser.hpp"
# include "Window.hpp"
# include "Player.hpp"
# include "Grid.hpp"

class Scene
{
	public:
		Scene(Window &window, ParsingData const &levelData);
		~Scene();

		Grid const		&getGrid() const;
		// Textures const	&getTextures() const;

	private:
		Window 		&_window;
		Textures	_textures;
		Grid		_grid;
		Player		_player;
};

#endif
