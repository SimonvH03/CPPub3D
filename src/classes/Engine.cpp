#include "Engine.hpp"

Engine::Engine()
{
	std::cout << "Engine Default Constructor\n";
}

Engine::Engine(Engine const &original)
{
	std::cout << "Engine Copy Constructor\n";
	*this = original;
}

Engine &Engine::operator=(Engine const &original)
{
	std::cout << "Engine Assignment Operator\n";
	if (this != &original)
	{
	}
	return (*this);
}

Engine::~Engine()
{
	std::cout << "Engine Destructor\n";
}
