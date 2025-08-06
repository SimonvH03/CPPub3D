#ifndef TEXTURES_HPP
# define TEXTURES_HPP

# include "MLX42.h"

struct Textures
{
	mlx_texture_t	*north;
	mlx_texture_t	*east;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	uint32_t		floor;
	uint32_t		ceiling;
};

#endif
