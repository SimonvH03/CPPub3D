#include "Scene.hpp"

Scene::Scene(Window &window, ParsingData &&levelData)
	: _window(window),
	_textures(std::move(levelData.textures)),
	_grid(std::move(levelData.grid)),
	_player(std::move(levelData.camera))
{
	std::cout << "Scene Default Constructor\n";
}

Scene::~Scene()
{
	std::cout << "Scene Destructor\n";
}

Grid const	&Scene::getGrid() const
{
	return (_grid);
}
