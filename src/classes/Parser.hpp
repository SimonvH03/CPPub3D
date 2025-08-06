#ifndef PARSER_HPP
# define PARSER_HPP
# include <iostream>
# include <string_view>
# include <vector>
# include <fstream>

# include "MLX42.h"
# include "Vec2.hpp"
# include "Config.hpp"

# include "Window.hpp"
# include "Textures.hpp"
# include "Grid.hpp"
# include "Camera.hpp"

struct	ParsingData
{
	Textures	textures;
	Grid		grid;
	Camera		camera;
};

namespace Parser
{
	bool	level(ParsingData &output, std::string const &filePath);
};

#endif
