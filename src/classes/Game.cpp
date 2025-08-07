#include "Game.hpp"

Game::Game(Window &window)
	:	_window(window)
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
	_window.addKeyHook([this](Window::KeyData keyData) {this->keyHook(keyData);});
	_window.addLoopHook([this]() {this->update();});
	// mlx_loop_hook(window->mlx, frametime_dependant_variables, window);
	// mlx_loop_hook(window->mlx, view_manager, window);
	// mlx_mouse_hook(window->mlx, mouse_buttons, window);
	_window.loop();
	return (true);
}

void	Game::keyHook(Window::KeyData keyData)
{
	if (keyData.action != Window::Action::MLX_PRESS)
		return ;
	if (keyData.key == Window::Key::MLX_KEY_TAB
		|| keyData.key == Window::Key::MLX_KEY_M)
	{
		std::cout << "Key pressed:\t" << keyData.key << std::endl;
		// _hud.toggleMaps();
	}
	// if (keyData.key == Window::Key::MLX_KEY_LEFT_CONTROL)
	// {
	// 	toggle_view(window);
	// }
	// if (keyData.key == Window::Key::MLX_KEY_E)
	// {
	// 	player_interaction(&window->scene.grid, &window->player.camera);
	// }
	// if (keyData.key == Window::Key::MLX_KEY_G)
	// {
	// 	fire_weapon(&window->player.weapon);
	// }
	// if (keyData.key == Window::Key::MLX_KEY_R)
	// {
	// 	reload_weapon(&window->player.weapon);
	// }
}

void	Game::update()
{
	switch (_view)
	{
		case View::MainMenu:
			updateMainMenu(); break;
		// case View::Settings:
		// 	updateSettings(); break;
		// case View::LevelSelection:
		// 	updateLevel(); break;
		case View::Play:
			updatePlay(); break;
		// case View::Pause:
		// 	updatePause(); break;
	}
}

void	Game::updateMainMenu()
{
	// _hud.updateMainMenu();
}

void	Game::updatePlay()
{
	// _scene->update();
}

bool Game::loadLevel(const std::string& inputFile)
{
	delete _scene;
	{	Parser::Data	levelData;

		if (!Parser::level(levelData, inputFile)) return (false);
		addToTextureList({levelData.textures.north,
				levelData.textures.east,
				levelData.textures.south,
				levelData.textures.west});
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
