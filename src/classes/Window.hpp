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
		typedef	mlx_texture_t	*Texture;
		typedef	mlx_t 			*Handle;
		typedef	mlx_image_t		*Image;

		typedef	mouse_key_t		MouseKey;
		typedef	keys_t			Key;
		typedef action_t		Action;
		typedef modifier_key_t	Modifier;
		typedef struct {
			MouseKey	key;
			Action		action;
			Modifier	modifier;
		}						MouseData;
		typedef struct {
			Key			key;
			Action		action;
			Modifier	modifier;
		}						KeyData;

		typedef std::function<void ()>			LoopHook;
		typedef std::function<void (KeyData)>	KeyHook;
		// typedef std::function<void (mouse_key_t, action_t)>	MouseHook;
		// typedef std::function<void (double, double)>		ScrollHook;

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
		void	loop();
		void	close();

		void	addKeyHook(KeyHook function);
		void	callKeyHooks(KeyData keyData);
static	void	keyHookCallback(mlx_key_data_t keyData, void *self);

		void	addLoopHook(LoopHook function);
		void	callLoopHooks();
static	void	loopHookCallback(void *self);

		const Settings&		getSettings() const;
		// Handle				getMlx() const;

static	Texture	loadTexture(std::string_view const &filePath);
static	void	deleteTexture(Texture texture);
		Image	newImage() const;

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
