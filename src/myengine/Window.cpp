#include "Window.h"

void Window::init(std::string _name, int _width, int _height)
{
	name = _name;
	width = _width;
	height = _height;

	window = SDL_CreateWindow(name,
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		width, height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
}
