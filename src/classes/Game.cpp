#include "Game.hpp"

Game::Game(Window &window) : _window(window)
{
	std::cout << "Game Default Constructor\n";
}

Game::~Game()
{
	std::cout << "Game Destructor\n";
}

bool	Game::run()
{
	return (true);
}

bool Game::loadLevel(const std::string& inputFile)
{
	delete		_scene;
	ParsingData	levelData;

	bzero(&levelData, sizeof(ParsingData));
	if (!Parser::level(levelData, inputFile)) return (false);
	std::cout << "level loaded, parsing passed\n";
	_scene = new Scene(_window, levelData);
	// if  (!_renderer.init(window)) return (false);

	// if (!_hud.init()) return false;

	return (true);
}
