#ifndef CAMERA_HPP
# define CAMERA_HPP
# include <iostream>
# include <algorithm>

# include "Config.hpp"

# include "Vec2.hpp"

class Camera
{
	public:
		Camera();
		Camera(Vec2 position, char cardinalDirection);
		Camera(Vec2 position, Vec2 direction);
		Camera(Camera const &original);
		Camera(Camera &&original) noexcept;
		Camera &operator=(Camera const &original);
		Camera &operator=(Camera &&original) noexcept;
		~Camera();

		void	yaw(float step);
		void	pitch(float step);

		void	pan(Vec2 radian);
		void	move(Vec2 step);

	public:
		Vec2	_pos;
		Vec2	_dir;
		Vec2	_plane;
		int32_t	_height_offset = 0;

		static constexpr float	_movement_matrix[3][3] = {{-0.7,0,0.7},{-1,0,1},{-0.7,0,0.7}}; // find out a way to use 1/sqrt(2) instead of 0.7

		// Vec2	getPos() const;
		// Vec2	getDir() const;
		// Vec2	getPlane() const;
};

#endif
