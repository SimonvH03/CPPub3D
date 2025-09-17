#include "Camera.hpp"

Camera::Camera()
{
	std::cout << "Camera Default Constructor\n";
}

Camera::Camera(Vec2	position, char cardinal)
	:	_pos(position)
{
	std::cout << "Camera Position Cardinal Constructor\n";
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

Camera::Camera(Vec2	position, Vec2 direction)
	:	_pos(position),
		_dir(direction),
		_plane(_dir.left())
{
	std::cout << "Camera Position Direction Constructor\n";
}

Camera::Camera(Camera const &original)
	:	_pos(original._pos),
		_dir(original._dir),
		_plane(original._plane),
		_verticalOffset(original._verticalOffset)
{
	std::cout << "Camera Copy Constructor\n";
}

Camera::Camera(Camera &&original) noexcept
	:	_pos(original._pos),
		_dir(original._dir),
		_plane(original._plane),
		_verticalOffset(original._verticalOffset)
{
	std::cout << "Camera Move Constructor\n";
	original._pos = Vec2(0,0);
	original._dir = Vec2(0,0);
	original._plane = Vec2(0,0);
	original._verticalOffset = 0;
}

Camera &Camera::operator=(Camera const &original)
{
	std::cout << "Camera Assignment Operator\n";
	if (this != &original)
	{
		_pos = original._pos;
		_dir = original._dir;
		_plane = original._plane;
		_verticalOffset = original._verticalOffset;
	}
	return (*this);
}

Camera &Camera::operator=(Camera &&original) noexcept
{
	std::cout << "Camera Move Assignment Operator\n";
	if (this != &original)
	{
		_pos = original._pos;
		_dir = original._dir;
		_plane = original._plane;
		_verticalOffset = original._verticalOffset;

		original._pos = Vec2(0,0);
		original._dir = Vec2(0,0);
		original._plane = Vec2(0,0);
		original._verticalOffset = 0;
	}
	return (*this);
}

Camera::~Camera()
{
	std::cout << "Camera Destructor\n";
}

void	Camera::pan(Vec2 radian)
{
	yaw(radian.x);
	pitch(radian.y);
}

void	Camera::yaw(float radian)
{
	if (!radian)	return;

	_dir.rotate(radian);

	_dir.normalise();
	_plane = _dir.left();
	// std::cout << atan2(_dir.y, _dir.x) * 180 / 3.14159 <<"\n";
}

void	Camera::pitch(float radian)// camera shouldn't know window_height
{
	if (!radian)	return;

	_verticalOffset += radian * static_cast<float>(config::WindowHeight);
	_verticalOffset = std::clamp(_verticalOffset, 0.0f, static_cast<float>(config::WindowHeight));
	std::cout << _verticalOffset << "\n";
}

void	Camera::move(Vec2 step)
{
	if (!step)	return;

	_pos += step;
}

// Vec2	Camera::getPos() const
// {
// 	return (_pos);
// }

// Vec2	Camera::getDir() const
// {
// 	return (_dir);
// }

// Vec2	Camera::getPlane() const
// {
// 	return (_plane);
// }
