#include "Cell.hpp"

Cell::Cell()
{
	// std::cout << "Cell Default Constructor\n";
}

Cell::Cell(Cell const &original)
{
	// std::cout << "Cell Copy Constructor\n";
	*this = original;
}

Cell::Cell(char token)
{
	// std::cout << "Cell Token Constructor\n";
	*this = token;
}

Cell &Cell::operator=(Cell const &original)
{
	// std::cout << "Cell Assignment Operator\n";
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
	// std::cout << "Cell Token Assignment Operator\n";
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
	// std::cout << "Cell Destructor";
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
