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
	if (_mlx == nullptr) return (set_error(cub::err::MlxFail));
	if (_settings.fullscreen == true)
	{
		mlx_get_monitor_size(_settings.monitorId, &width, &height);
		mlx_set_window_size(_mlx, width, height);
	}
	mlx_set_mouse_pos(_mlx, _mlx->width / 2, _mlx->height / 2);
	_cursor = mlx_create_std_cursor(MLX_CURSOR_ARROW);
	if (_cursor == nullptr) return (set_error(cub::err::MlxFail));
	mlx_set_cursor(_mlx, _cursor);
	return (true);
}

void	Window::loop()
{
	mlx_key_hook(_mlx, keyHookCallback, this);
	mlx_loop_hook(_mlx, loopHookCallback, this);
	mlx_loop(_mlx);
}

void	Window::close()
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

bool	Window::isKeyDown(Key key) const
{
	return (mlx_is_key_down(_mlx, key));
}

void	Window::addKeyHook(KeyHook function)
{
	_keyHooks.push_back(function);
}

void	Window::callKeyHooks(KeyData keyData)
{
	if (keyData.key == MLX_KEY_ESCAPE && keyData.action == MLX_PRESS)
		return close();
	for (KeyHook function : _keyHooks)
		function(keyData);
}

void	Window::keyHookCallback(mlx_key_data_t keyData, void *self)
{
	((Window *)self)->callKeyHooks(KeyData{keyData.key, keyData.action, keyData.modifier});
}

void	Window::addLoopHook(LoopHook function)
{
	_loopHooks.push_back(std::move(function));
}

void	Window::callLoopHooks()
{
	for (LoopHook &function : _loopHooks)
		function();
}

void	Window::loopHookCallback(void *self)
{
	((Window *)self)->callLoopHooks();
}

// const Window::Settings	&Window::getSettings() const
// {
// 	return (_settings);
// }
