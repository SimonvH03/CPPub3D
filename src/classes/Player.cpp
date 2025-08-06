#include "Player.hpp"

Player::Player()
{
	std::cout << "Player Default Constructor\n";
}

Player::Player(Camera const &camera) : _camera(camera)
{
	std::cout << "Player Default Constructor\n";
}

Player::~Player()
{
	std::cout << "Player Destructor\n";
}

Camera const	&Player::getCamera()
{
	return (_camera);
}
