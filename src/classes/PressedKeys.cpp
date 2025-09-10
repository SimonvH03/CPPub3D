#include "PressedKeys.hpp"

PressedKeys::PressedKeys()
{
	std::cout << "PressedKeys Default Constructor\n";
}

void	PressedKeys::update(Window const &window)
{
	w		= window.isKeyDown(Window::Key::MLX_KEY_W);
	a		= window.isKeyDown(Window::Key::MLX_KEY_A);
	s		= window.isKeyDown(Window::Key::MLX_KEY_S);
	d		= window.isKeyDown(Window::Key::MLX_KEY_D);
	up		= window.isKeyDown(Window::Key::MLX_KEY_UP);
	down	= window.isKeyDown(Window::Key::MLX_KEY_DOWN);
	left	= window.isKeyDown(Window::Key::MLX_KEY_LEFT);
	right	= window.isKeyDown(Window::Key::MLX_KEY_RIGHT);
}

PressedKeys::~PressedKeys()
{
	std::cout << "PressedKeys Destructor\n";
}
