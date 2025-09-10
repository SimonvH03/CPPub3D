#include "Renderer.hpp"

Renderer::Renderer(Window &window, Scene const &scene)
	:	_image(window.newImage()),
		_scene(scene),
		_aspectRatio(_image->width / _image->height)
{
	std::cout << "Renderer Default Constructor\n";
}

Renderer::~Renderer()
{
	std::cout << "Renderer Destructor\n";
}

void	Renderer::wipe()
{
	std::memset(_image->pixels, 0, _image->width * _image->height * sizeof(uint32_t));
}

void	Renderer::initRay()
{
	Camera const &camera = _scene.getCamera();

	_ray.pos.x = (int)camera._pos.x;
	_ray.pos.y = (int)camera._pos.y;
	_ray.dir.x = camera._dir.x + camera._plane.x * _aspectRatio * _ray.camera_x;
	_ray.dir.y = camera._dir.y + camera._plane.y * _aspectRatio * _ray.camera_x;
	_ray.step.x = std::abs(1 / _ray.dir.x);
	if (_ray.step.x == INFINITY)
		_ray.step.x = (float)UINT32_MAX;
	_ray.step.y = std::abs(1 / _ray.dir.y);
	if (_ray.step.y == INFINITY)
		_ray.step.y = (float)UINT32_MAX;
	_ray.sign.x = (_ray.dir.x == 0) ? 0 : (_ray.dir.x > 0) ? 1 : -1;
	_ray.sign.y = (_ray.dir.y == 0) ? 0 : (_ray.dir.y > 0) ? 1 : -1;
	if (_ray.sign.x > 0)
		_ray.total.x = ((_ray.pos.x + 1 - camera._pos.x) * _ray.step.x);
	else
		_ray.total.x = (camera._pos.x - _ray.pos.x) * _ray.step.x;
	if (_ray.sign.y > 0)
		_ray.total.y = ((_ray.pos.y + 1 - camera._pos.y) * _ray.step.y);
	else
		_ray.total.y = (camera._pos.y - _ray.pos.y) * _ray.step.y;
	_ray.start.x = camera._pos.x;
	_ray.start.y = camera._pos.y;
	_ray.distance = 0;
}

void	Renderer::castRay()
{
	Grid const	&grid = _scene.getGrid();
	while (true)
	{
		if (_ray.total.y < _ray.total.x)
		{
			_ray.total.y += _ray.step.y;
			_ray.pos.y += _ray.sign.y;
			_ray.hitAxis = s_ray::e_hitAxis::horizontal;
		}
		else
		{
			_ray.total.x += _ray.step.x;
			_ray.pos.x += _ray.sign.x;
			_ray.hitAxis = s_ray::e_hitAxis::vertical;
		}
		if (grid.getCell(_ray.pos.y, _ray.pos.x).isSolid())
			break ;
		// if (hit_position(_ray, grid, _ray.pos.y, _ray.pos.x) == true)
		// 	break ;
	}
	if (_ray.hitAxis == s_ray::e_hitAxis::horizontal)
		_ray.distance = _ray.total.y - _ray.step.y;
	else
		_ray.distance = _ray.total.x - _ray.step.x;
}

void	Renderer::update()
{
	wipe();
	for (uint32_t x = 0; x < _image->width; ++x)
	{
		_ray.camera_x = x / (float)(_image->width - 1) - 0.5;
		initRay();
		castRay();
		uint32_t	halfHeight = _image->height / _ray.distance / 2;
		int32_t		start = _image->height / 2 - halfHeight;
		int32_t		end = _image->height / 2 + halfHeight;
		uint32_t	screen_y = (uint32_t)start;
		// std::cout	<< "distance: " << _ray.distance << "\t"
		// 			<< "halfHeight: " << halfHeight << "\t"
		// 			<< "start: " << start << "\t"
		// 			<< "start: " << start << "\t"
		// 			<< "end: " << end << "\t"
		// 			<< "screen_y: " << screen_y << "\n";
		while (screen_y < (uint32_t)end)
		{
			((uint32_t *)_image->pixels)[x + screen_y * _image->width]
				= 0xFFFF00FF;
			screen_y++;
		}
		// draw_texture_collumn()
	}
}
