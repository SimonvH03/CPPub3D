#ifndef CONFIG_HPP
# define CONFIG_HPP

# include "MLX42.h"

namespace config
{
	inline static constexpr	const char			*WindowTitle = "title";
	inline static constexpr int32_t				MonitorId = 0;
	inline static constexpr	bool				Fullscreen = false;
	inline static constexpr	int32_t				WindowWidth = 1280;
	inline static constexpr	int32_t				WindowHeight = 720;

	inline static constexpr const std::string	AllowedCharacters = "01NESW ";
}

#endif
