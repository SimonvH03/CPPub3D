#include "Physicer.hpp"

Physicer::Physicer(Window const &window, Scene const &scene)
	:	_window(window),
		_scene(scene)
{
	std::cout << "Physicer Default Constructor\n";
}

Physicer::~Physicer()
{
	std::cout << "Physicer Destructor\n";
}

void	Physicer::update()
{

}
