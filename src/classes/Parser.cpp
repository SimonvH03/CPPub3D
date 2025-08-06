#include "Parser.hpp"

namespace
{
	bool loadContent(std::vector<std::string> &content, std::string const &inputFile)
	{
		std::ifstream file(inputFile);
		if (!file.is_open()) return set_error(cub::err::InvalidFile);

		std::string line;
		while (std::getline(file, line))
		{
			if (line.empty()) continue;
			if (line.back() == '\n')
				line.pop_back();
			content.push_back(line);
		}
		return (true);
	}

	std::string_view trimLeft(std::string_view stringView)
	{
		size_t i = 0;
		while (i < stringView.size()
			&& std::isspace(static_cast<unsigned char>(stringView[i])))
			++i;
		return stringView.substr(i);
	}

	uint32_t	parseColour(std::string_view line)
	{
		int		red;
		int		green;
		int		blue;
		size_t	pos = 0;

		red = std::stoi(std::string(line.data() + pos, line.size() - pos));

		pos = line.find(',', pos);
		if (pos == std::string_view::npos) return (set_error(cub::err::InvalidColour), 0);
		line.remove_prefix(pos + 1);
		green = std::stoi(std::string(line.data(), line.size()));

		pos = line.find(',', 0);
		if (pos == std::string_view::npos) return (set_error(cub::err::InvalidColour), 0);
		line.remove_prefix(pos + 1);
		blue = std::stoi(std::string(line.data(), line.size()));

		if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255)
			return (set_error(cub::err::InvalidColour), 0);

		return ((0xFF << 24) | (blue << 16) | (green << 8) | red);
	}

	bool	evaluateLine(Textures &textures, std::string_view line)
	{
		if (line.starts_with("NO ") && !textures.north)
			return (textures.north = Window::loadTexture(trimLeft((line.substr(3))))); // not transposed over y = x yet
		else if (line.starts_with("EA ") && !textures.east)
			return (textures.east = Window::loadTexture(trimLeft((line.substr(3)))));
		else if (line.starts_with("SO ") && !textures.south)
			return (textures.south = Window::loadTexture(trimLeft((line.substr(3)))));
		else if (line.starts_with("WE ") && !textures.west)
			return (textures.west = Window::loadTexture(trimLeft((line.substr(3)))));
		else if (line.starts_with("F ") && !textures.floor)
			return (textures.floor = parseColour(trimLeft(line.substr(2))));
		else if (line.starts_with("C ") && !textures.ceiling)
			return (textures.ceiling = parseColour(trimLeft(line.substr(2))));
		return (false);
	}

	bool	hasValidTypeIdentifier(std::string_view line)
	{
		return (line.starts_with("NO ")
			||	line.starts_with("EA ")
			||	line.starts_with("SO ")
			||	line.starts_with("WE ")
			||	line.starts_with("F ")
			||	line.starts_with("C "));
	}

	bool	parseElements(Textures &textures,
		std::vector<std::string>::const_iterator &iterator,
		std::vector<std::string>::const_iterator end)
	{
		std::string_view	line;

		while (iterator != end && (!textures.floor || !textures. ceiling
			|| !textures.north || !textures.east || !textures.south || !textures.west))
		{
			line = *iterator++;
			if (line.empty())
				continue;
			if (!hasValidTypeIdentifier(line))
				return (set_error(cub::err::InvalidElement));
			if (!evaluateLine(textures, line))
				return (false);
		}
		if (!textures.north || !textures.east || !textures.south || !textures.west)
			return (set_error(cub::err::NoTexture));
		if (!textures.floor || !textures.ceiling)
			return (set_error(cub::err::NoColour));
		return (true);
	}
}

namespace
{
	bool	loadMap(Grid &grid,
		std::vector<std::string>::const_iterator iterator,
		std::vector<std::string>::const_iterator end)
	{
		size_t	xMax;
		size_t	yMax;

		xMax = 0;
		for (std::vector<std::string>::const_iterator line = iterator; line != end; ++line)
			xMax = std::max<size_t>(line->size(), xMax);
		yMax = std::distance(iterator, end);
		grid = Grid(xMax, yMax);
		// std::cout << "Grid initialzed with size " << grid.size() << " (" << grid.getWidth() << "x" << grid.getHeight() << ") " << std::endl;
		for (size_t y = 0; y < yMax; y++)
		{
			std::string_view line = iterator[y];
			for (size_t x = 0; x < xMax; x++)
			{
				char token = (x < line.length()) ? line[x] : ' ';

				if (config::AllowedCharacters.find(token) == config::AllowedCharacters.npos)
				{
					std::cout << token << std::endl;
					return (set_error(cub::err::InvalidMap));
				}
				grid.setCell(y, x, token);
			}
		}
		return ((grid.size() > 0));
	}

	bool	floodFill(Grid const &grid, std::vector<std::vector<bool>> &visited, size_t y, size_t x)
	{
		if (x >= grid.getWidth()|| y >= grid.getHeight()) return false;
		if (visited[y][x] == true) return true;

		char type = grid.getCell(y, x).getType();
		if (type == ' ') return false;
		if (type == '1') return true;

		visited[y][x] = true;

		return floodFill(grid, visited, y + 1, x)
			&& floodFill(grid, visited, y - 1, x)
			&& floodFill(grid, visited, y, x + 1)
			&& floodFill(grid, visited, y, x - 1);
	}

	bool	parseMap(Camera &camera, Grid &grid)
	{
		Vec2	playerPosition;
		char	playerDirection;
		bool	playerFound(false);

		for (size_t y = 0; y < grid.getHeight(); ++y)
		{
			for (size_t x = 0; x < grid.getWidth(); ++x)
			{
				char token = grid.getCell(y, x).getType();
				if (token == 'N' || token == 'E' || token == 'S' || token == 'W')
				{
					if (playerFound) return (set_error(cub::err::MultiplePlayers));
					playerFound = true;
					grid.setCell(y, x, '0');
					playerPosition.x = x;
					playerPosition.y = y;
					playerDirection = token;
				}
			}
		}
		if (!playerFound) return (set_error(cub::err::NoPlayer));

		std::vector<std::vector<bool>> visited(grid.getHeight(), std::vector<bool>(grid.getWidth(), false));
		if (!floodFill(grid, visited, playerPosition.y, playerPosition.x)) return (set_error(cub::err::Perimeter));
	
		camera = Camera(playerPosition, playerDirection);
		return (true);
	}
}

bool Parser::level(ParsingData &levelData, std::string const &inputFile)
{
	std::vector<std::string>	content;

	if (!loadContent(content, inputFile)) return (false);
	std::vector<std::string>::const_iterator iterator = content.begin();
	std::vector<std::string>::const_iterator end = content.end();

	if (!parseElements(levelData.textures, iterator, end)) return (false);

	if (!loadMap(levelData.grid, iterator, end)) return (false);
	if (!parseMap(levelData.camera, levelData.grid)) return (false);
	return (true);
}
