#ifndef PHYSICER_HPP
# define PHYSICER_HPP
# include <iostream>

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
			struct Move
			{
				float	lateral;
				float	longitudinal;
			}	move;
			struct Look
			{
				float	lateral;
				float	longitudinal;
			}	look;
			InputsPlay &operator*(float const factor);
		};

		void	update();

		InputsPlay const &getInputsPlay() const;

	private:
		Window const	&_window;

		InputsPlay		_inputsPlay;

		void	interpretPressedKeys();

};

#endif
