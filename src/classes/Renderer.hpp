#ifndef RENDERER_HPP
# define RENDERER_HPP
# include <iostream>

# include "MLX42.h"

# include "Window.hpp"

class Renderer
{
	public:
		Renderer(Window &window);
		~Renderer();

	private:
		Window::Image _image;
};

#endif
