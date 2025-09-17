#ifndef SCENE_HPP
# define SCENE_HPP
# include <iostream>
# include <string_view>
# include <vector>
# include <fstream>

# include "MLX42.h"
# include "Physicer.hpp"

# include "Textures.hpp"
# include "Parser.hpp"
# include "Window.hpp"
# include "Player.hpp"
# include "Grid.hpp"

class Scene
{
	public:
		Scene(Parser::Data &&levelData, Physicer::InputsPlay const &inputs);
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

		Physicer::InputsPlay const	&_inputs;

};

#endif
