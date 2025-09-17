#include "Player.hpp"

Player::Player(Camera const &camera, Physicer::InputsPlay const &inputs)
	:	_camera(camera),
		_inputs(inputs)
{
	std::cout << "Player Camera Constructor\n";
}

Player::Player(Camera &&camera, Physicer::InputsPlay const &inputs) noexcept
	:	_camera(std::move(camera)),
		_inputs(inputs)
{
	std::cout << "Player Camera Move Constructor\n";
}

Player &Player::operator=(Player &&original)
{
	std::cout << "Player Move Assignment Operator\n";
	if (this != &original)
	{
		_camera = std::move(original._camera);
	}
	return (*this);
}

Player::~Player()
{
	std::cout << "Player Destructor\n";
}

void	Player::update(Grid const &grid)
{

	execInputs(grid);
}

void	Player::execInputs(Grid const &grid)
{
	_camera.pan(_inputs.pan);
	if (_inputs.move)
		_camera.move(validMove(grid, _camera._pos, _inputs.move.changedBasis(_camera._dir)));
}

Player::Ray::Ray(Vec2 position, Vec2 direction)
	:	pos((size_t)position.x, (size_t)position.y),
		dir(direction),
		start(position)
{
	step.x = (dir.x == 0.0f)
		? std::numeric_limits<float>::max()
		: std::abs(1 / dir.x);
	step.y = (dir.y == 0.0f)
		? std::numeric_limits<float>::max()
		: std::abs(1 / dir.y);
	sign.x = (dir.x == 0)
		? 0 : (dir.x > 0) ? 1 : -1;
	sign.y = (dir.y == 0)
		? 0 : (dir.y > 0) ? 1 : -1;
	total.x = (sign.x > 0)
		? (pos.x + 1 - position.x) * step.x
		: (position.x - pos.x) * step.x;
	total.y = (sign.y > 0)
		? (pos.y + 1 - position.y) * step.y
		: (position.y - pos.y) * step.y;
	std::cout	<< "(" << pos.x << "," << pos.y << ") "
				<< dir << " "
				<< step << " "
				<< "(" << sign.x << "," << sign.y << ") "
				<< total << "\n";
}

Vec2	Player::validMove(Grid const &grid, Vec2 position, Vec2 proposedMove) const
{
	float	validDistance = 0.0f;
	float	proposedDistance = proposedMove.length();

	Ray		ray(position, proposedMove.normalised());

	while (validDistance < proposedDistance)
	{
		if (ray.total.x < ray.total.y)
		{
			ray.pos.x += ray.sign.x;
			ray.total.x += ray.step.x;
			validDistance = ray.total.x;
		}
		else
		{
			ray.pos.y += ray.sign.y;
			ray.total.y += ray.step.y;
			validDistance = ray.total.y;
		}
		if (grid.getCell(ray.pos.y, ray.pos.x).isSolid())
			break ;
	}
	if (proposedDistance)
		std::cout << proposedDistance << " : " << validDistance << "\n";
	return ((validDistance < proposedDistance)
			? proposedMove * validDistance / proposedDistance * 0.99f
			: proposedMove);
}

Camera const	&Player::getCamera() const
{
	return (_camera);
}
