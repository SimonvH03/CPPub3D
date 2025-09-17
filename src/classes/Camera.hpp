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

		void	pan(Vec2 radian);
		void	move(Vec2 step);

		Vec2	_pos;
		Vec2	_dir;
		Vec2	_plane;
		float	_verticalOffset = config::WindowHeight / 2;

	private:
		void	yaw(float radian);
		void	pitch(float radian);

		// Vec2	getPos() const;
		// Vec2	getDir() const;
		// Vec2	getPlane() const;
};

#endif
