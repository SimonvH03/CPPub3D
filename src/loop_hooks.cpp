# include "MLX42.h"
# include "Game.hpp"

// static void
// 	game_keys(
// 		mlx_key_data_t keydata,
// 		t_window *window)
// {
// 	if (keydata.action != MLX_PRESS)
// 		return ;
// 	if (keydata.key == MLX_KEY_M || keydata.key == MLX_KEY_TAB)
// 	{
// 		toggle_maps(&window->hud);
// 	}
// 	if (keydata.key == MLX_KEY_LEFT_CONTROL)
// 	{
// 		toggle_view(window);
// 	}
// 	if (keydata.key == MLX_KEY_E)
// 	{
// 		player_interaction(&window->scene.grid, &window->player.camera);
// 	}
// 	if (keydata.key == MLX_KEY_G)
// 	{
// 		fire_weapon(&window->player.weapon);
// 	}
// 	if (keydata.key == MLX_KEY_R)
// 	{
// 		reload_weapon(&window->player.weapon);
// 	}
// }

// static void
// 	menu_keys(
// 		mlx_key_data_t keydata,
// 		t_window *window)
// {
// 	if (keydata.action != MLX_PRESS)
// 		return ;
// 	if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN)
// 	{
// 		select_button(&window->menu, keydata.key);
// 	}
// 	if (keydata.key == MLX_KEY_ENTER || keydata.key == MLX_KEY_SPACE)
// 	{
// 		confirm_selection(&window->menu, window);
// 	}
// }

void
	window_keyhook(
		mlx_key_data_t keydata,
		void *param)
{
	Game			*game = (Game *)param;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		game->getWindow().close();
	}
	// switch (game->getView())
	// {
	// 	case Game::View::Level:
	// 		game.
	// 		break;
	// 	case Game::View::Menu:
	// 		menu_keys(keydata, window);
	// 		break;
	// 	default:
	// }
}
