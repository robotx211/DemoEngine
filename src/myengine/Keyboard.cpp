#include "Keyboard.h"

namespace myEngine
{
	Keyboard::Keyboard()
	{

	}

	Keyboard::~Keyboard()
	{

	}

	void Keyboard::update()
	{
		SDL_PumpEvents();
		m_state = SDL_GetKeyboardState(NULL);
	}

	bool Keyboard::getKey(SDL_Scancode _scancode)
	{
		return m_state[_scancode];
	}

}