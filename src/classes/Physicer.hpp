#ifndef PHYSICER_HPP
# define PHYSICER_HPP
# include <iostream>
# include <algorithm>

# include "MLX42.h"
# include "Vec2.hpp"
# include "Config.hpp"
# include "Window.hpp"

class Physicer
{
	public:
		Physicer(Window const &window);
		~Physicer();

		struct	InputsPlay
		{
			Vec2	pan;
			Vec2	move;
		};

		void	update();

		InputsPlay const &getInputsPlay() const;

	private:
		Window const	&_window;

		InputsPlay		_inputsPlay;

		// float	_mouseSensitivity = config::MouseSensitivity;
		float	_movementSpeed = config::MovementSpeed;
		float	_rotationSpeed = config::RotationSpeed;

		void	interpretPressedKeys();

};

#endif
