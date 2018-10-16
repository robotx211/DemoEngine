#include "Core.h"
#include "Entity.h"
#include "Window.h"

namespace myEngine {


	void Window::init(std::string _name, int _width, int _height)
	{
		name = _name;
		width = _width;
		height = _height;

		//window = std::make_shared<SDL_Window>(
		//	SDL_CreateWindow(name.c_str(),
		//		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		//		width, height,
		//		SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL)
		//	);

		window = SDL_CreateWindow(name.c_str(),
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			width, height,
			SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

		std::cout << "Window Awake" << std::endl;
	}

	void Window::update()
	{

	}


}
