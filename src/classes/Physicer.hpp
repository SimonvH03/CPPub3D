#ifndef PHYSICER_HPP
# define PHYSICER_HPP
# include <iostream>

# include "MLX42.h"
# include "Config.hpp"
# include "Window.hpp"

# include "Scene.hpp"
# include "Camera.hpp"

class Physicer
{
	public:
		Physicer(Window const &window, Scene const &scene);
		~Physicer();

		void	update();

	private:
		Window const	&_window;
		Scene const		&_scene;
};

#endif
