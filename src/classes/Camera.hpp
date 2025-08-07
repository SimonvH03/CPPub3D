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
		int32_t	_height_offset = 0;

		float	_aspect_ratio = 0;
		float	_cursor_rot_speed = 0;
		float	_movement_speed = 0;
		float	_movement_matrix[3][3];
		float	_rotation_cosin[2];

	public:
		Camera();
		Camera(Vec2 position, char cardinalDirection);
		Camera(Vec2 position, Vec2 direction);
		Camera(Camera const &original);
		Camera(Camera &&original) noexcept;
		Camera &operator=(Camera const &original);
		Camera &operator=(Camera &&original) noexcept;
		~Camera();

		void	update();
		void	fitToWindow(size_t width, size_t height);

		Vec2	getPos() const;
		Vec2	getDir() const;
		Vec2	getPlane() const;
};

#endif
