#ifndef PLAYER_HPP
# define PLAYER_HPP
# include <iostream>

# include "Physicer.hpp"
# include "Grid.hpp"

# include "Camera.hpp"

class Player
{
	public:
		Player(Camera const &camera, Physicer::InputsPlay const &inputs);
		Player(Camera &&camera, Physicer::InputsPlay const &inputs) noexcept;
		Player &operator=(Player &&original);
		~Player();

		void	update(Grid const &_grid);

		Camera const	&getCamera() const;

	private:
		Camera	_camera;

		Physicer::InputsPlay const	&_inputs;

		void	execInputs(Grid const &grid);

		Vec2	validMove(Grid const &grid, Vec2 position, Vec2 proposedMove) const;

		struct	Ray
		{
			struct	coordinate
			{
				size_t	x,y;
			}			pos;
			struct	quadrant
			{
				short	x,y;
			}			sign;
			float		camera_x;
			float		distance;
			float		partial;
			Vec2		dir;
			Vec2		step;
			Vec2		total;
			Vec2		start;
			int16_t		hitCell;
			int16_t		facedCell;
			enum	e_hitAxis
			{
				horizontal,
				vertical
			}			hitAxis;
			Ray(Vec2 pos, Vec2 dir);
		};
};

#endif
