#ifndef PLAYER_HPP
# define PLAYER_HPP
# include <iostream>

# include "Camera.hpp"
# include "Grid.hpp"

class Player
{
	public:
		Player();
		Player(Camera const &camera);
		Player(Camera &&camera) noexcept;
		~Player();

		Camera const	&getCamera();

	private:
		Camera	_camera;
};

#endif
