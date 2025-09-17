#ifndef GRID_HPP
# define GRID_HPP

# include <iostream>
# include <vector>

# include "Error.hpp"

# include "Cell.hpp"

class Grid
{
	public:
		Grid();
		Grid(size_t width, size_t height);
		Grid(Grid const &original);
		Grid(Grid &&original) noexcept;
		Grid &operator=(Grid const &original);
		Grid &operator=(Grid &&other) noexcept;
		~Grid();

		using		IterateFunc = int	(Cell, size_t, size_t, void *);
		int			iterate(IterateFunc function, void *param);

		Cell const	&getCell(size_t y, size_t x) const;
		void		setCell(size_t y, size_t x, char token);

		size_t		getWidth() const;
		size_t		getHeight() const;
		size_t		size() const;

	private:
		std::vector<Cell>	_data;
		size_t				_width = 0;
		size_t				_height = 0;

		Cell		&cell(size_t y, size_t x);
};

#endif
