#ifndef MYENGINE_WINDOW_H
#define MYENGINE_WINDOW_H

#include <SDL2/SDL.h>
#include <memory>
#include <iostream>
#include <string>

namespace myEngine {

	class Window
	{

	private:
	  //std::shared_ptr<SDL_Window> window;
	  SDL_Window *m_window;

	  std::string m_name;
	  int m_width;
	  int m_height;

	public:

      SDL_Window* getWindow() { return m_window; }

      Window(std::string _name, int _width, int _height);
      ~Window();

	};

}

#endif