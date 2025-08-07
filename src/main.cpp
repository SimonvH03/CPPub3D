#include <iostream>

#include "Engine.hpp"
#include "Error.hpp"
#include "Window.hpp"
#include "Game.hpp"

extern cub::err	g_cubErrno;

int	main(int argc, char **argv)
{
	if (argc != 2) return (std::cout << "Usage: " << argv[0] << " <filepath/level.cub>\n", EINVAL);

	{
		Window	window;
		Game	game(window);

		if (!window.init())
			return (print_error(), false);
		if (!game.loadLevel(argv[1]))
			return (print_error(), false);
		if (!game.run())
			return (print_error(), false);
	}
	if (g_cubErrno != cub::err::Success || mlx_errno != MLX_SUCCESS)
		print_error();
	return (g_cubErrno != cub::err::Success || mlx_errno != MLX_SUCCESS);
}
