#include "Window.hpp"

Window::Window()
{
	std::cout << "Window Default Constructor\n";
}

Window::~Window()
{
	std::cout << "Window Destructor\n";
	mlx_terminate(_mlx);
}

bool	Window::init()
{
	int32_t	width;
	int32_t	height;

	mlx_set_setting(MLX_STRETCH_IMAGE, false);
	mlx_set_setting(MLX_FULLSCREEN, false);
	mlx_set_setting(MLX_MAXIMIZED, _settings.fullscreen);
	mlx_set_setting(MLX_DECORATED, !_settings.fullscreen);
	mlx_set_setting(MLX_HEADLESS, false);
	_mlx = mlx_init(_settings.width, _settings.height, config::WindowTitle, false);
	if (_mlx == NULL)
		return (set_error(cub::err::MemFail));
	if (_settings.fullscreen == true)
	{
		mlx_get_monitor_size(_settings.monitorId, &width, &height);
		mlx_set_window_size(_mlx, width, height);
	}
	mlx_set_mouse_pos(_mlx, _mlx->width / 2, _mlx->height / 2);
	_cursor = mlx_create_std_cursor(MLX_CURSOR_ARROW);
	mlx_set_cursor(_mlx, _cursor);
	return (true);
}



bool	Window::loop_hook(void (*function)(void *), void *param) const
{
	if (!mlx_loop_hook(_mlx, function, (param) ? param : _mlx))
		return (set_error(cub::err::MlxFail));
	return (true);
}

void	Window::key_hook(mlx_keyfunc function, void *param) const
{
	mlx_key_hook(_mlx, function, (param) ? param : _mlx);
}

void	Window::mouse_hook(mlx_mousefunc function, void *param) const
{
	mlx_mouse_hook(_mlx, function, (param) ? param : _mlx);
}

void	Window::scroll_hook(mlx_scrollfunc function, void *param) const
{
	mlx_scroll_hook(_mlx, function, (param) ? param : _mlx);
}

void	Window::loop() const
{
	mlx_loop(_mlx);
}

void	Window::close() const
{
	mlx_close_window(_mlx);
}

Window::Texture Window::loadTexture(std::string_view const &filePath)
{
	Texture	texture;
	xpm_t	*xpm;

	if (!std::filesystem::exists(filePath)) return (set_error(cub::err::InvalidTexture), nullptr);
	if (filePath.ends_with(".png"))
	{
		texture = mlx_load_png(filePath.data());
		if (!texture) return (set_error(cub::err::MlxFail), nullptr);
	}
	else if (filePath.ends_with(".xpm42"))
	{
		xpm = mlx_load_xpm42(filePath.data());
		if (xpm == nullptr) return (set_error(cub::err::MlxFail), nullptr);
		texture = &xpm->texture;
	}
	else return (set_error(cub::err::InvalidTexture), nullptr);
	return (texture);
}

void	Window::deleteTexture(Texture texture)
{
	mlx_delete_texture(texture);
}

Window::Image	Window::newImage() const
{
	mlx_image_t	*image;

	image = mlx_new_image(_mlx, _mlx->width, _mlx->height);
	if (image == nullptr)
		return (set_error(cub::err::MlxFail), nullptr);
	if (mlx_image_to_window(_mlx, image, 0, 0) == -1)
		return (set_error(cub::err::MlxFail), nullptr);
	return (image);
}

// Window::Handle	Window::getMlx() const
// {
// 	return (_mlx);
// }

const Window::Settings	&Window::getSettings() const
{
	return (_settings);
}
