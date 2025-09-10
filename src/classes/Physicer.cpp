#include "Physicer.hpp"

Physicer::Physicer(Window const &window)
	:	_window(window)
{
	std::cout << "Physicer Default Constructor\n";
}

Physicer::~Physicer()
{
	std::cout << "Physicer Destructor\n";
}

Physicer::InputsPlay &Physicer::InputsPlay::operator*(float factor)
{
	move.lateral *= factor;
	move.longitudinal *= factor;

	look.lateral *= factor;
	look.longitudinal *= factor;
	return (*this);
}

void	Physicer::update()
{
	interpretPressedKeys();
	// mouse_pan();
	_inputsPlay * _window.getFrameTime();
}

void	Physicer::interpretPressedKeys()
{
	Window::PressedKeys	const	&keys = _window.getPressedKeys();

	if (keys.w) _inputsPlay.move.lateral += 1;
	if (keys.a) _inputsPlay.move.lateral -= 1;
	if (keys.s) _inputsPlay.move.longitudinal += 1;
	if (keys.d) _inputsPlay.move.longitudinal -= 1;

	if (keys.left)	_inputsPlay.look.lateral += 1;
	if (keys.right) _inputsPlay.look.lateral -= 1;
	if (keys.up)	_inputsPlay.look.longitudinal += 1;
	if (keys.down)	_inputsPlay.look.longitudinal -= 1;

	std::cout	<< "lat: " << _inputsPlay.look.lateral << "\tlong: " << _inputsPlay.look.longitudinal << "\n";
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

Physicer::InputsPlay const &Physicer::getInputsPlay() const
{
	return (_inputsPlay);
}
