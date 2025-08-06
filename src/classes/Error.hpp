#ifndef ERROR_HPP
# define ERROR_HPP

# include <errno.h>
# include <iostream>
# include <string.h>

# include "MLX42.h"

namespace	cub
{
	enum class	err
	{
		Success = 0,	// No Errors.
		MlxFail,		// MLX42 function has failed.
		MemFail,		// Dynamic memory allocation has failed.
		DataFail,		// Data file failed to load.
		InvalidFile,	// The provided file was invalid or does not exist.
		InvalidElement,	// Cub element has invalid type identifier.
		NoColour,		// Cub colour is missing.
		InvalidColour,	// Cub colour has invalid format (R,G,B [0,255]).
		NoTexture,		// Cub texture path is missing.
		InvalidTexture,	// Cub texture path has invalid format (png, xpm42) or does not exist.
		NoMap,			// Cub map is missing.
		InvalidMap,		// Cub map has invalid character. (0,1,N,E,S,W,' ')
		Perimeter,		// Cub map not closed/surrounded by walls.
		NoPlayer,		// Cub map has no player position.
		MultiplePlayers,// Cub map has multiple player positions.
		InvalidDoor,	// Cub map has invalid door placement.
		ErrorMaxIndex,	// Error count
	};
}

bool	set_error(const cub::err err_val);
void	print_error(void);

#endif
