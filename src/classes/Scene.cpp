#include "Scene.hpp"

Scene::Scene(Window &window, ParsingData const &levelData) : _window(window), _textures(levelData.textures), _grid(levelData.grid), _player(levelData.camera)
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
