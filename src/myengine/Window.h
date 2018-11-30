#ifndef MYENGINE_WINDOW_H
#define MYENGINE_WINDOW_H

#include <SDL2/SDL.h>
#include <memory>
#include <iostream>
#include <string>

namespace myEngine {

	/**
	*	Creates and stores an SDL Window
	*/
	class Window
	{

	private:
	  SDL_Window *m_window;

	  std::string m_name;
	  int m_width;
	  int m_height;

	public:

      SDL_Window* getWindow() { return m_window; }

      Window(std::string _name, int _width, int _height);
      ~Window();

			int getWidth() { return m_width; }
			int getHeight() { return m_height; }

			float getAspectRatio() { return (float)m_width / (float)m_height; } ///< returns the aspect ratio of the window

	};

}

#endif