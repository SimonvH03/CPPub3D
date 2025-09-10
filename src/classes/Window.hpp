#ifndef WINDOW_HPP
# define WINDOW_HPP
# include <iostream>
# include <vector>
# include <filesystem>
# include <functional>

# include "MLX42.h"
# include "Error.hpp"
# include "Config.hpp"

class Window
{
	public:
		Window();
		~Window();

		bool	init();
		void	loop();
		void	close();

		using Texture	= mlx_texture_t*;
		using Handle	= mlx_t*;
		using Image		= mlx_image_t*;

		using MouseKey	= mouse_key_t;
		using Key		= keys_t;
		using Action	= action_t;
		using Modifier	= modifier_key_t;

		struct MouseData
		{
			MouseKey	key;
			Action		action;
			Modifier	modifier;
		};
		struct KeyData
		{
			Key			key;
			Action		action;
			Modifier	modifier;
		};

		using LoopHook	= std::function<void ()>;
		using KeyHook	= std::function<void (KeyData)>;
		// using MouseHook	= std::function<void (mouse_key_t, action_t)>;
		// using ScrollHook= std::function<void (double, double)>;

		struct	Settings
		{
			bool		fullscreen = config::Fullscreen;
			int32_t		monitorId = config::MonitorId;
			int32_t		width = config::WindowWidth;
			int32_t		height = config::WindowHeight;
		};

		void	addKeyHook(KeyHook function);
		void	callKeyHooks(KeyData keyData);
static	void	keyHookCallback(mlx_key_data_t keyData, void *self);

		void	addLoopHook(LoopHook function);
		void	callLoopHooks();
static	void	loopHookCallback(void *self);

static	Texture	loadTexture(std::string_view const &filePath);
static	void	deleteTexture(Texture texture);

		Image	newImage() const;
		bool	isKeyDown(Key key) const;

		// Settings const	&getSettings() const;
		// Handle			getMlx() const;

	private:
		Handle					_mlx = nullptr;
		mlx_win_cursor_t		*_cursor = nullptr;
		Settings				_settings;

		std::vector<LoopHook>	_loopHooks;
		std::vector<KeyHook>	_keyHooks;
		// std::vector<mouseHook>	_mouseHooks;
		// std::vector<scrollHook>	_scrollHooks;
};

#endif
