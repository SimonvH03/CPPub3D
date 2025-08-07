#include "Game.hpp"
#include "loop_hooks.cpp"

Game::Game(Window &window) : _window(window)
{
	std::cout << "Game Default Constructor\n";
}

Game::~Game()
{
	std::cout << "Game Destructor\n";
	delete _scene;
	clearTextureList();
}

bool	Game::run()
{
	// mlx_loop_hook(window->mlx, frametime_dependant_variables, window);
	// mlx_loop_hook(window->mlx, view_manager, window);
	// mlx_mouse_hook(window->mlx, mouse_buttons, window);
	_window.key_hook(window_keyhook, this);
	// window.loop_hook()
	_window.loop();
	return (true);
}

bool Game::loadLevel(const std::string& inputFile)
{
	delete		_scene;
	{	ParsingData	levelData;

		if (!Parser::level(levelData, inputFile)) return (false);
		addToTextureList({levelData.textures.north,
				levelData.textures.east,
				levelData.textures.south,
				levelData.textures.west});
		std::cout << "Level loaded; Parsing passed\n";
		_scene = new Scene(_window, std::move(levelData));
	}
	// next steps should be elsewhere
	// if  (!_renderer.init(window)) return (false);
	// if (!_hud.init()) return false;
	return (true);
}

void	Game::addToTextureList(std::initializer_list<Window::Texture> textures)
{
	for (Window::Texture texture : textures)
		_allocatedTextures.push_back(texture);
}

void	Game::clearTextureList()
{
	for (Window::Texture texture : _allocatedTextures)
		Window::deleteTexture(texture);
}

Window const	&Game::getWindow() const
{
	return (_window);
}

Scene const	&Game::getScene() const
{
	return (*_scene);
}

Game::View	Game::getView() const
{
	return (_view);
}
