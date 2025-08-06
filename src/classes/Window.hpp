#ifndef WINDOW_HPP
# define WINDOW_HPP
# include <iostream>
# include <vector>
# include <filesystem>

# include "MLX42.h"
# include "Error.hpp"
# include "Config.hpp"

class Window
{
	public:
		typedef	mlx_texture_t	*Texture;
		typedef	mlx_t 			*Handle;
		typedef	mlx_image_t		*Image;
		struct	Settings
		{
			bool		fullscreen = config::Fullscreen;
			int32_t		monitorId = config::MonitorId;
			int32_t		width = config::WindowWidth;
			int32_t		height = config::WindowHeight;
		};

		Window();
		~Window();

		bool	init();
		bool	loop_hook(void (*function)(void *), void *param);
		bool	key_hook(mlx_keyfunc function, void *param);
		bool	mouse_hook(mlx_mousefunc function, void *param);
		bool	scroll_hook(mlx_scrollfunc function, void *param);
		bool	loop();

		const Settings&		getSettings() const;
		Handle				getMlx() const;

		static Texture		loadTexture(std::string_view const &filePath);
		static void			deleteTexture(Texture texture);
		Image				newImage() const;

	private:
		Handle					_mlx;
		mlx_win_cursor_t		*_cursor;

		enum class View {Menu, Game}	_view;
		Settings						_settings;
};

#endif
