#ifndef CELL_HPP
# define CELL_HPP
# include <iostream>

class Cell
{
	private:
		char	_type;
		bool	_solid;
		int8_t	_id;

	public:
		Cell();
		Cell(char token);
		Cell(Cell const &original);
		Cell &operator=(Cell const &original);
		Cell &operator=(char token);
		~Cell();

		char	getType() const;
		bool	isSolid() const;
		int8_t	getID() const;
};

#endif
