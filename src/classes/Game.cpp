#include "Game.hpp"

Game::Game(Window &window)
	:	_window(window)
{
	std::cout << "Game Default Constructor\n";
}

Game::~Game()
{
	std::cout << "Game Destructor\n";
	delete _renderer;
	delete _scene;
	clearTextureList();
}

bool	Game::run()
{
	_window.addKeyHook([this](Window::KeyData keyData) {this->keyHook(keyData);});
	_window.addLoopHook([this]() {this->update();});
	// mlx_mouse_hook(window->mlx, mouse_buttons, window);
	_window.loop();
	return (true);
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
		_physicer = new Physicer(_window);
		_scene = new Scene(std::move(levelData), _physicer->getInputsPlay());
		_renderer = new Renderer(_window, *_scene);
	}
	// next steps should be elsewhere
	// if  (!_renderer.init(window)) return (false);
	// if (!_hud.init()) return false;
	return (true);
}

void	Game::keyHook(Window::KeyData keyData)
{
	if (keyData.action != Window::Action::MLX_PRESS)
		return ;
	// if (keyData.key == Window::Key::MLX_KEY_LEFT_CONTROL)
	// {
	// 	toggle_view(window);
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
	_physicer->update();
	_scene->update();
	// _hud.updatePlay();
	_renderer->update();
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
