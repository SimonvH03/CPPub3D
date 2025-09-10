#include "Player.hpp"

Player::Player()
{
	std::cout << "Player Default Constructor\n";
}

Player::Player(Camera const &camera)
	:	_camera(camera)
{
	std::cout << "Player Camera Constructor\n";
}

Player::Player(Camera &&camera) noexcept
	:	_camera(std::move(camera))
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

void	Player::yawCamera(short sign)
{
	_camera.yaw(sign);
}

void	Player::pitchCamera(short sign)
{
	_camera.pitch(sign);
}

Camera const	&Player::getCamera() const
{
	return (_camera);
}
