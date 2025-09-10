#ifndef RENDERER_HPP
# define RENDERER_HPP
# include <iostream>
# include <cstring>

# include "MLX42.h"
# include "Vec2.hpp"

# include "Window.hpp"
# include "Scene.hpp"

class Renderer
{
	public:
		Renderer(Window &window, Scene const &scene);
		~Renderer();

		void	update();

	private:
		Window::Image	_image;
		// Window::Image	_background;
		Scene const		&_scene;
		float			_aspectRatio;

		void	wipe();
		void	initRay();
		void	castRay();
		// void	render_texture_column();

	
		struct	s_ray
		{
			struct	coordinate
			{
				uint32_t	x,y;
			}			pos;
			struct	quadrant
			{
				short		x,y;
			}			sign;
			float		camera_x;
			float		distance;
			float		partial;
			Vec2		dir;
			Vec2		step;
			Vec2		total;
			Vec2		start;
			int16_t		hitCell;
			int16_t		facedCell;
			enum	e_hitAxis
			{
				horizontal,
				vertical
			}			hitAxis;
		}	_ray;
};

#endif
