#include <iostream>

#include "Engine.hpp"
#include "Error.hpp"
#include "Window.hpp"
#include "Game.hpp"

extern cub::err	g_cubErrno;

void
	window_keyhook(
		mlx_key_data_t keydata,
		void *mlx)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window((mlx_t *)mlx);
	}
}

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
		// mlx_key_hook(window->mlx, window_keyhook, window);
		// mlx_loop_hook(window->mlx, frametime_dependant_variables, window);
		// mlx_loop_hook(window->mlx, view_manager, window);
		// mlx_mouse_hook(window->mlx, mouse_buttons, window);
		window.key_hook(window_keyhook, NULL);
		if (!window.loop())
			return (false);
	}
	if (g_cubErrno != cub::err::Success || mlx_errno != MLX_SUCCESS)
		print_error();
	return (g_cubErrno != cub::err::Success || mlx_errno != MLX_SUCCESS);
}
