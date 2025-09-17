#ifndef CELL_HPP
# define CELL_HPP
# include <iostream>

class Cell
{
	private:
		char	_type = '\0';
		bool	_solid = false;
		int8_t	_id = 0x00;

	public:
		Cell();
		Cell(char token);
		Cell(Cell const &original);
		Cell &operator=(Cell const &original);
		Cell &operator=(char token);
		~Cell();

	explicit	operator bool() const;

		char	getType() const;
		bool	isSolid() const;
		int8_t	getID() const;
};

#endif
