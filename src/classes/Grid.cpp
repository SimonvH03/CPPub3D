#include "Grid.hpp"

Grid::Grid()
{
	std::cout << "Grid Default Constructor\n";
}

Grid::Grid(size_t width, size_t height)
	:	_width(width),
		_height(height)
{
	std::cout << "Grid Dimensions Constructor\n";
	_data.resize(width * height);
}

Grid::Grid(Grid const &original)
    :	_data(original._data),
		_width(original._width),
		_height(original._height)
{
	std::cout << "Grid Copy Constructor\n";
}

Grid::Grid(Grid&& other) noexcept
    :	_data(std::move(other._data)),
		_width(other._width),
		_height(other._height)
{
    std::cout << "Grid Move Constructor\n";
    other._width = 0;
    other._height = 0;
}

Grid	&Grid::operator=(Grid const &original)
{
	std::cout << "Grid Assignment Operator\n";
	if (this != &original)
	{
		_data = original._data;
		_width = original._width;
		_height = original._height;
	}
	return (*this);
}

Grid& Grid::operator=(Grid&& other) noexcept
{
    std::cout << "Grid Move Assignment Operator\n";
    if (this != &other)
	{
        _data = std::move(other._data);
        _width = other._width;
        _height = other._height;
        other._width = 0;
        other._height = 0;
    }
    return *this;
}

Grid::~Grid()
{
	std::cout << "Grid Destructor\n";
}

void	Grid::setCell(size_t y, size_t x, char value)
{
	cell(y, x) = value;
}

Cell const	&Grid::getCell(size_t y, size_t x) const
{
	return (_data[y * _width + x]);
}

Cell	&Grid::cell(size_t y, size_t x)
{
	return (_data[y * _width + x]);
}

int	Grid::iterate(IterateFunc function, void *param)
{
	size_t	y;
	size_t	x;
	int		return_value;

	for (y = 0; y < _height; y++)
	{
		for (x = 0; x < _width; x++)
		{
			return_value = function(getCell(y, x), y, x, param);
			if (return_value) return (return_value);
		}
	}
	return (0);
}

size_t	Grid::getWidth() const
{
	return (_width);
}

size_t	Grid::getHeight() const
{
	return (_height);
}

size_t	Grid::size() const
{
	return (_data.size());
}
