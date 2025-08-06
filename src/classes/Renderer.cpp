#include "Renderer.hpp"

Renderer::Renderer(Window &window) : _image(window.newImage())
{
	std::cout << "Renderer Default Constructor\n";
}

Renderer::~Renderer()
{
	std::cout << "Renderer Destructor\n";
}
