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
		Player &operator=(Player &&original);
		~Player();

		void	yawCamera(short sign);
		void	pitchCamera(short sign);

		Camera const	&getCamera() const;

	private:
		Camera	_camera;
};

#endif
