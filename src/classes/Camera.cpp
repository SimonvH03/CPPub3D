#include "Camera.hpp"

Camera::Camera()
{
	std::cout << "Camera Default Constructor\n";
}

Camera::Camera(Vec2	position, char cardinal) : _pos(position), _height_offset(0)
{
	switch (cardinal)
	{
		case 'N':
			_dir = Vec2(0, -1);
			break;
		case 'E':
			_dir = Vec2(1, 0);
			break;
		case 'S':
			_dir = Vec2(0, 1);
			break;
		case 'W':
			_dir = Vec2(-1, 0);
			break;
		default:
			_dir = Vec2(0,0);
	}
	_plane = _dir.left();
}

Camera::Camera(Vec2	position, Vec2 direction) : _pos(position), _dir(direction), _plane(_dir.left()), _height_offset(0)
{
}

Camera::~Camera()
{
	std::cout << "Camera Destructor\n";
}

Vec2	Camera::getPos() const
{
	return (_pos);
}

Vec2	Camera::getDir() const
{
	return (_dir);
}

Vec2	Camera::getPlane() const
{
	return (_plane);
}
