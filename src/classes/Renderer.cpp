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

	_ray.pos = {(size_t)camera._pos.x, (size_t)camera._pos.y};
	_ray.dir = camera._dir + camera._plane * _aspectRatio * _ray.camera_x;
	_ray.step.x = (_ray.dir.x == 0.0f)
		? std::numeric_limits<float>::max()
		: std::abs(1 / _ray.dir.x);
	_ray.step.y = (_ray.dir.y == 0.0f)
		? std::numeric_limits<float>::max()
		: std::abs(1 / _ray.dir.y);
	_ray.sign.x = (_ray.dir.x == 0)
		? 0 : (_ray.dir.x > 0) ? 1 : -1;
	_ray.sign.y = (_ray.dir.y == 0)
		? 0 : (_ray.dir.y > 0) ? 1 : -1;
	_ray.total.x = (_ray.sign.x > 0)
		? (_ray.pos.x + 1 - camera._pos.x) * _ray.step.x
		: (camera._pos.x - _ray.pos.x) * _ray.step.x;
	_ray.total.y = (_ray.sign.y > 0)
		? (_ray.pos.y + 1 - camera._pos.y) * _ray.step.y
		: (camera._pos.y - _ray.pos.y) * _ray.step.y;
	_ray.start = camera._pos;
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
			_ray.hitAxis = Ray::e_hitAxis::horizontal;
		}
		else
		{
			_ray.total.x += _ray.step.x;
			_ray.pos.x += _ray.sign.x;
			_ray.hitAxis = Ray::e_hitAxis::vertical;
		}
		if (_ray.pos.y > grid.getHeight() || _ray.pos.x > grid.getWidth()) // temporary measure
			break ;
		if (grid.getCell(_ray.pos.y, _ray.pos.x).isSolid())
			break ;
		// if (hit_position(_ray, grid, _ray.pos.y, _ray.pos.x) == true)
		// 	break ;
	}
	if (_ray.hitAxis == Ray::e_hitAxis::horizontal)
		_ray.distance = _ray.total.y - _ray.step.y;
	else
		_ray.distance = _ray.total.x - _ray.step.x;
}

void	Renderer::drawSimpleColumn(uint32_t x)
{
	uint32_t	halfScreen = _image->height / 2;
	uint32_t	halfColumn = halfScreen / _ray.distance;

	halfScreen	= _scene.getCamera()._verticalOffset;
	int32_t		start = halfScreen - halfColumn;
	uint32_t	end = halfScreen + halfColumn;
	uint32_t	screen_y = std::clamp(start, (int32_t)0, (int32_t)_image->height);
	// if (_ray.distance < 1)	std::cout	<< "distance: " << _ray.distance << "\t"
	// 									<< "halfColumn: " << halfColumn << "\t"
	// 									<< "start: " << start << "\t"
	// 									<< "end: " << end << "\t"
	// 									<< "screenHeight: " << _image->height << "\t"
	// 									<< "screen_y: " << screen_y << "\n";
	while (screen_y < std::clamp(end, (uint32_t)0, _image->height))
	{
		((uint32_t *)_image->pixels)[x + screen_y * _image->width]
			= 0xFFFF00FF;
		screen_y++;
	}
}

void	Renderer::update()
{
	wipe();
	for (uint32_t x = 0; x < _image->width; ++x)
	{
		_ray.camera_x = x / (float)(_image->width - 1) - 0.5;
		initRay();
		castRay();
		drawSimpleColumn(x);
		// draw_texture_collumn()
	}
}
