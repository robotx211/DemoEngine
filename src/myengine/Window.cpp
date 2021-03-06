#include "Window.h"

namespace myEngine {


	Window::Window(std::string _name, int _width, int _height)
	{
		m_name = _name;
		m_width = _width;
		m_height = _height;

		m_window = SDL_CreateWindow(m_name.c_str(),
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			m_width, m_height,
			SDL_WINDOW_OPENGL);

		//std::cout << "Window Awake" << std::endl;
	}

    Window::~Window()
    {
      SDL_DestroyWindow(m_window);
    }




}
