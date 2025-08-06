#ifndef CAMERA_HPP
# define CAMERA_HPP
# include <iostream>

# include "Config.hpp"

# include "Vec2.hpp"

class Camera
{
	public:
		Vec2	_pos;
		Vec2	_dir;
		Vec2	_plane;
		int32_t	_height_offset;

		float	_aspect_ratio;
		float	_cursor_rot_speed;
		float	_movement_speed;
		float	_movement_matrix[3][3];
		float	_rotation_cosin[2];

	public:
		Camera();
		Camera(Vec2 position, char cardinalDirection);
		Camera(Vec2 position, Vec2 direction);
		~Camera();

		void	update();
		void	fitToWindow(size_t width, size_t height);

		Vec2	getPos() const;
		Vec2	getDir() const;
		Vec2	getPlane() const;
};

#endif
