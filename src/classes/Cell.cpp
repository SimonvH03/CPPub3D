#include "Cell.hpp"

Cell::Cell() : _type(0), _solid(0), _id(0)
{
}

Cell::Cell(Cell const &original)
{
	*this = original;
}

Cell::Cell(char token)
{
	*this = token;
}

Cell &Cell::operator=(Cell const &original)
{
	if (this != &original)
	{
		_type = original._type;
		_solid = original._solid;
		_id = original._id;
	}
	return (*this);
}

Cell &Cell::operator=(char token)
{
	if (std::isdigit(token))
	{
		_type =	token;
		_solid = (token != '0');
		_id = token - '0';
	}
	else
	{
		_type = token;
		_solid = true;
		_id = 0;
	}
	return (*this);
}

Cell::~Cell()
{
}

char	Cell::getType() const
{
	return (_type);
}

bool	Cell::isSolid() const
{
	return (_solid);
}

int8_t	Cell::getID() const
{
	return (_id);
}
