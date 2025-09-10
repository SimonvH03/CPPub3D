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
		_height_offset(original._height_offset),
		_cursor_rot_speed(original._cursor_rot_speed),
		_movement_speed(original._movement_speed)
{
	std::cout << "Camera Copy Constructor\n";
}

Camera::Camera(Camera &&original) noexcept
	:	_pos(original._pos),
		_dir(original._dir),
		_plane(original._plane),
		_height_offset(original._height_offset),
		_cursor_rot_speed(original._cursor_rot_speed),
		_movement_speed(original._movement_speed)
{
	std::cout << "Camera Move Constructor\n";
	original._pos = Vec2(0,0);
	original._dir = Vec2(0,0);
	original._plane = Vec2(0,0);
	original._height_offset = 0;
	original._cursor_rot_speed = 0;
	original._movement_speed = 0;
}

Camera &Camera::operator=(Camera const &original)
{
	std::cout << "Camera Assignment Operator\n";
	if (this != &original)
	{
		_pos = original._pos;
		_dir = original._dir;
		_plane = original._plane;
		_height_offset = original._height_offset;
		_cursor_rot_speed = original._cursor_rot_speed;
		_movement_speed = original._movement_speed;
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
		_height_offset = original._height_offset;
		_cursor_rot_speed = original._cursor_rot_speed;
		_movement_speed = original._movement_speed;

		original._pos = Vec2(0,0);
		original._dir = Vec2(0,0);
		original._plane = Vec2(0,0);
		original._height_offset = 0;
		original._cursor_rot_speed = 0;
		original._movement_speed = 0;
	}
	return (*this);
}

Camera::~Camera()
{
	std::cout << "Camera Destructor\n";
}

void	Camera::yaw(short sign)
{
	Vec2	oldDir = _dir;
	const float	rm[2][2] = {{_rotation_cosin[0], _rotation_cosin[1] * sign},
							{-_rotation_cosin[1] * sign, _rotation_cosin[0]}};

	_dir.x = oldDir.x * rm[0][0] + oldDir.y * rm[0][1];
	_dir.y = oldDir.x * rm[1][0] + oldDir.y * rm[1][1];
	_dir.normalise();
	_plane = _dir.left();
}

void	Camera::pitch(short sign)
{
	_height_offset -= 0.01 * config::WindowHeight * sign;
	std::clamp(_height_offset, 0, config::WindowHeight); // this needs to be _window.height
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
