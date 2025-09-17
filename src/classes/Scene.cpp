#include "Scene.hpp"

Scene::Scene(Parser::Data &&levelData, Physicer::InputsPlay const &inputs)
	:	_textures(std::move(levelData.textures)),
		_grid(std::move(levelData.grid)),
		_player(std::move(levelData.camera), inputs),
		_inputs(inputs)
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
	_player.update(_grid);
	// update_doors();
	// update_weapon();
}

// Vec2 Scene::clipMovement(Vec2 pos, Vec2 step) const
// {
// 	// Traverse grid
// 	float dist = 0.0f;
// 	while (dist < maxDist)
// 	{
// 		if (sideDistX < sideDistY)
// 		{
// 			sideDistX += deltaDistX;
// 			mapX += stepX;
// 			dist = sideDistX;
// 		}
// 		else
// 		{
// 			sideDistY += deltaDistY;
// 			mapY += stepY;
// 			dist = sideDistY;
// 		}

// 		// Hit a wall? -> clip
// 		if (isWall(mapX, mapY))
// 		{
// 			float scale = (dist < maxDist) ? (dist - 0.001f) / maxDist : 1.0f;
// 			return step * scale;
// 		}
// 	}

// 	// No collision: allow full move
// 	return step;
// }

// void	Scene::keyHook(Window::KeyData keyData)
// {
// 	// Play view?
// 	if (keyData.key == Window::Key::MLX_KEY_TAB
// 		|| keyData.key == Window::Key::MLX_KEY_M)
// 	{
// 		std::cout << "Key pressed:\t" << keyData.key << std::endl;
// 		// _hud.toggleMaps();
// 	}
// 	if (keyData.key == Window::Key::MLX_KEY_E)
// 	{
// 		player_interaction(&window->scene.grid, &window->player.camera);
// 	}
// 	if (keyData.key == Window::Key::MLX_KEY_G)
// 	{
// 		fire_weapon(&window->player.weapon);
// 	}
// 	if (keyData.key == Window::Key::MLX_KEY_R)
// 	{
// 		reload_weapon(&window->player.weapon);
// 	}
// }

Camera const &Scene::getCamera() const
{
	return (_player.getCamera());
}

Grid const	&Scene::getGrid() const
{
	return (_grid);
}
