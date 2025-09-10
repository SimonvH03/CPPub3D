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
# include "PressedKeys.hpp"
# include "Player.hpp"
# include "Grid.hpp"

class Scene
{
	public:
		Scene(PressedKeys const &pressedKeys);
		Scene(Parser::Data &&levelData, PressedKeys const &pressedKeys);
		Scene &operator=(Scene &&original);
		~Scene();

		Camera const	&getCamera() const;
		Grid const		&getGrid() const;
		// Textures const	&getTextures() const;

		void	update();

	private:
		Textures	_textures;
		Grid		_grid;
		Player		_player;

		PressedKeys	const &_pressedKeys;

		void	arrowkeys();
};

#endif
