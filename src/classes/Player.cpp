#include "Player.hpp"

Player::Player(Camera const &camera, Physicer::InputsPlay const &inputs)
	:	_camera(camera),
		_inputs(inputs)
{
	std::cout << "Player Camera Constructor\n";
}

Player::Player(Camera &&camera, Physicer::InputsPlay const &inputs) noexcept
	:	_camera(std::move(camera)),
		_inputs(inputs)
{
	std::cout << "Player Camera Move Constructor\n";
}

Player &Player::operator=(Player &&original)
{
	std::cout << "Player Move Assignment Operator\n";
	if (this != &original)
	{
		_camera = std::move(original._camera);
	}
	return (*this);
}

Player::~Player()
{
	std::cout << "Player Destructor\n";
}

void	Player::update()
{
	execInputs();
}

void	Player::execInputs()
{
	_camera.pan(_inputs.pan);
	_camera.move(_inputs.move);
}

Camera const	&Player::getCamera() const
{
	return (_camera);
}
