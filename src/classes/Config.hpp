#ifndef CONFIG_HPP
# define CONFIG_HPP

# include "MLX42.h"

namespace config
{
	inline static constexpr	const char		*WindowTitle = "title";
	inline static constexpr int32_t			MonitorId = 0;
	inline static constexpr	bool			Fullscreen = false;
	inline static constexpr	int32_t			WindowWidth = 2160;
	inline static constexpr	int32_t			WindowHeight = 960;

	inline static constexpr std::string		AllowedCharacters = "01NESW ";

	inline static constexpr	uint32_t		MovementSpeed = 4U;
	inline static constexpr	uint32_t		RotationSpeed = 2U;
	inline static constexpr	uint32_t		MouseSensitivity = 50U;
}

#endif
