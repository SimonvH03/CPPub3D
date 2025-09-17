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

void	Physicer::update()
{
	interpretPressedKeys();
	// mouse_pan();
	// collisioncheck where??? Camera::move()->Scene.requestMove()? Physicer::collisioncheck()->getCamera(),getGrid()?
}

void	Physicer::interpretPressedKeys()
{
	Window::PressedKeys	const	&keys = _window.getPressedKeys();
	float const	frameTimeScalar = std::clamp(_window.getFrameTime(), 0.0f, (0.5f/_movementSpeed));
	_inputsPlay = InputsPlay();

	if (keys.w)	_inputsPlay.move.x += 1;
	if (keys.s)	_inputsPlay.move.x -= 1;
	if (keys.a)	_inputsPlay.move.y -= 1;
	if (keys.d)	_inputsPlay.move.y += 1;
	if (_inputsPlay.move)	_inputsPlay.move.normalise();
	_inputsPlay.move *= _movementSpeed * frameTimeScalar;

	if (keys.up)	_inputsPlay.pan.y += 1;
	if (keys.down)	_inputsPlay.pan.y -= 1;
	if (keys.left)	_inputsPlay.pan.x += 1;
	if (keys.right) _inputsPlay.pan.x -= 1;
	if (_inputsPlay.pan)	_inputsPlay.pan.normalise();
	_inputsPlay.pan *= _rotationSpeed * frameTimeScalar;

	// std::cout	<< "lat: " << _inputsPlay.look.x << "\tlong: " << _inputsPlay.look.y << "\n";
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
