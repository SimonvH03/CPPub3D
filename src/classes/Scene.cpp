#include "Scene.hpp"

Scene::Scene()
{
	std::cout << "Scene Default Constructor\n";
}

Scene::Scene(Parser::Data &&levelData)
	:	_textures(std::move(levelData.textures)),
		_grid(std::move(levelData.grid)),
		_player(std::move(levelData.camera))
{
	std::cout << "Scene Level Constructor\n";
}

Scene	&Scene::operator=(Scene &&original)
{
	std::cout << "Scene Move Assignment Operator\n";
	if (this != &original)
	{
		_textures = std::move(original._textures);
		_grid = std::move(original._grid);
		_player = std::move(original._player);
	}
	return (*this);
}

Scene::~Scene()
{
	std::cout << "Scene Destructor\n";
}

void	Scene::update()
{
	// view manager view::game section
}

// Grid const	&Scene::getGrid() const
// {
// 	return (_grid);
// }
