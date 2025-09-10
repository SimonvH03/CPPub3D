#ifndef PHYSICER_HPP
# define PHYSICER_HPP
# include <iostream>
# include <algorithm>

# include "MLX42.h"
# include "Config.hpp"
# include "Window.hpp"

class Physicer
{
	public:
		Physicer(Window const &window);
		~Physicer();

		struct	InputsPlay
		{
			struct Plane
			{
				float	lateral = 0;
				float	longitudinal = 0;
				Plane	&operator*=(float const factor);
			};
			struct Move : Plane
			{
				static constexpr float	max = 0.5;
			}	move;
			struct Look : Plane
			{
				static constexpr float	max = 0.2;
			}	look;
			InputsPlay	&operator*=(float const factor);
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
