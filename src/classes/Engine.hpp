#ifndef ENGINE_HPP
# define ENGINE_HPP
# include <iostream>

// # include "MLX42.h"

class Engine
{
	private:

	public:
		Engine();
		Engine(Engine const &original);
		Engine &operator=(Engine const &original);
		~Engine();

		void	raycast();
		void	render_texture_column();
};

#endif
