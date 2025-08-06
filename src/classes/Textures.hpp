#ifndef TEXTURES_HPP
# define TEXTURES_HPP

# include "MLX42.h"

struct Textures
{
	mlx_texture_t	*north = nullptr;
	mlx_texture_t	*east = nullptr;
	mlx_texture_t	*south = nullptr;
	mlx_texture_t	*west = nullptr;
	uint32_t		floor = 0x00000000;
	uint32_t		ceiling = 0x00000000;
};

#endif
