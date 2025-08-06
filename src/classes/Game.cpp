#include "Game.hpp"

Game::Game(Window &window) : _window(window)
{
	std::cout << "Game Default Constructor\n";
}

Game::~Game()
{
	std::cout << "Game Destructor\n";
	delete _scene;
	for (Window::Texture texture : _allocatedTextures)
		Window::deleteTexture(texture);
}

bool	Game::run()
{
	return (true);
}

bool Game::loadLevel(const std::string& inputFile)
{
	delete		_scene;
	ParsingData	levelData;

	if (!Parser::level(levelData, inputFile)) return (false);
	addToTextureList(levelData.textures.north);
	addToTextureList(levelData.textures.east);
	addToTextureList(levelData.textures.south);
	addToTextureList(levelData.textures.west);
	std::cout << "Level loaded; Parsing passed\n";
	_scene = new Scene(_window, levelData);
	// if  (!_renderer.init(window)) return (false);

	// if (!_hud.init()) return false;

	return (true);
}

void	Game::addToTextureList(Window::Texture texture)
{
	_allocatedTextures.insert(_allocatedTextures.begin(), texture);
}
