#include "Error.hpp"

cub::err	g_cubErrno = cub::err::Success;

const char	*cub_strerror(cub::err val)
{
	static constexpr const char	*cub_errors[] = {
		"No Errors.",
		"MLX42 function has failed.",
		"Dynamic memory allocation has failed.",
		"Data file failed to load.",
		"The provided file was invalid / does not exist.",
		"Cub element has invalid type identifier.",
		"Cub colour has invalid format. (R,G,B [0,255])",
		"Cub colour is missing.",
		"Cub texture has invalid format. (png, xpm42)",
		"Cub texture is missing.",
		"Cub map is missing.",
		"Cub map has invalid character. (0,1,N,E,S,W,' ')",
		"Cub map not closed/surrounded by walls.",
		"Cub map has no player position.",
		"Cub map has multiple player positions.",
		"Cub map has invalid door placement."
	};

	if (val >= cub::err::Success && val < cub::err::ErrorMaxIndex)
		return cub_errors[static_cast<int>(val)];
	else
		return "Unknown Error.";
}

bool	set_error(const cub::err err_val)
{
	if (err_val != cub::err::Success)
		g_cubErrno = err_val;
	return (false);
}

void	print_error(void)
{
	const int	save_errno = errno;

	errno = 0;
	std::cout << "Error\n";
	if (g_cubErrno != cub::err::Success)
		std::cout << "cub_errno: " << static_cast<int>(g_cubErrno) << ": " << cub_strerror(g_cubErrno) << std::endl;
	if (mlx_errno != MLX_SUCCESS)
		std::cout << "cub_errno: " << mlx_errno << ": " << mlx_strerror(mlx_errno) << std::endl;
	if (save_errno != 0)
		std::cout << "std_errno: " << save_errno << ": " << strerror(save_errno) << std::endl;
}
