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
		_height_offset(original._height_offset)
{
	std::cout << "Camera Copy Constructor\n";
}

Camera::Camera(Camera &&original) noexcept
	:	_pos(original._pos),
		_dir(original._dir),
		_plane(original._plane),
		_height_offset(original._height_offset)
{
	std::cout << "Camera Move Constructor\n";
	original._pos = Vec2(0,0);
	original._dir = Vec2(0,0);
	original._plane = Vec2(0,0);
	original._height_offset = 0;
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

		original._pos = Vec2(0,0);
		original._dir = Vec2(0,0);
		original._plane = Vec2(0,0);
		original._height_offset = 0;
	}
	return (*this);
}

Camera::~Camera()
{
	std::cout << "Camera Destructor\n";
}

// void	Camera::pan()
// void	Camera::move()

void	Camera::yaw(float step)// replace float rm[2][2] with Vec2 rm[2], use Vec2 * Vec2 operator
{
	if (step == 0)	return;
	Vec2 const	oldDir = _dir;
	Vec2 const	rm[2] = {Vec2(cosf(step), sinf(step)), Vec2(-sinf(step), cosf(step))};

	_dir.x = oldDir.dot(rm[0]);
	_dir.y = oldDir.dot(rm[1]);
	_dir.normalise();
	_plane = _dir.left();
}

void	Camera::pitch(float step)
{
	if (step == 0)	return;
	_height_offset -= 0.01 * config::WindowHeight * step;
	std::clamp(_height_offset, (int32_t)0, config::WindowHeight); // camera shouldn't know window_height
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
