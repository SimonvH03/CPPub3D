#ifndef PLAYER_HPP
# define PLAYER_HPP
# include <iostream>

# include "Physicer.hpp"

# include "Camera.hpp"

class Player
{
	public:
		Player(Camera const &camera, Physicer::InputsPlay const &inputs);
		Player(Camera &&camera, Physicer::InputsPlay const &inputs) noexcept;
		Player &operator=(Player &&original);
		~Player();

		void	update();

		Camera const	&getCamera() const;

	private:
		Camera	_camera;

		Physicer::InputsPlay const	&_inputs;

		void	execInputs();

};

#endif
