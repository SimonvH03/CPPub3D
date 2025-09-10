#ifndef PRESSEDKEYS_HPP
# define PRESSEDKEYS_HPP
# include <iostream>

# include "Window.hpp"

class PressedKeys
{
	public:
		PressedKeys();
		~PressedKeys();

		void	update(Window const &window);

		bool	w		= false;
		bool	a		= false;
		bool	s		= false;
		bool	d		= false;
		bool	up		= false;
		bool	down	= false;
		bool	left	= false;
		bool	right	= false;
};

#endif
