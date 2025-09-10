#include "Scene.hpp"

Scene::Scene(PressedKeys const &pressedKeys)
	:	_pressedKeys(pressedKeys)
{
	std::cout << "Scene Default Constructor\n";
}

Scene::Scene(Parser::Data &&levelData, PressedKeys const &pressedKeys)
	:	_textures(std::move(levelData.textures)),
		_grid(std::move(levelData.grid)),
		_player(std::move(levelData.camera)),
		_pressedKeys(pressedKeys)
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
	// inputs
	// wasd_move();
	arrowkeys();
	// mouse_pan();
	// env updates: doors, entities, animations
	// update_doors();
	// update_weapon();
}

void	Scene::arrowkeys()
{
	short	lateral = 0;
	short	longitudinal = 0;

	if (_pressedKeys.left) lateral += 1;
	if (_pressedKeys.right) lateral -= 1;
	if (_pressedKeys.up) longitudinal += 1;
	if (_pressedKeys.down) longitudinal -= 1;

	if (lateral)
		_player.yawCamera(lateral);
	if (longitudinal)
		_player.pitchCamera(longitudinal);
}

// void
// 	wasd_move(
// 		mlx_t *mlx,
// 		Grid &grid,
// 		Camera &camera)
// {
// 	short	forward_backward;
// 	short	left_right;

// 	forward_backward = 0;
// 	left_right = 0;
// 	if (mlx_is_key_down(mlx, MLX_KEY_W))
// 		forward_backward += 1;
// 	if (mlx_is_key_down(mlx, MLX_KEY_S))
// 		forward_backward -= 1;
// 	if (mlx_is_key_down(mlx, MLX_KEY_A))
// 		left_right -= 1;
// 	if (mlx_is_key_down(mlx, MLX_KEY_D))
// 		left_right += 1;
// 	if (forward_backward || left_right)
// 		move_camera(camera, grid->tilemap, forward_backward, left_right);
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
