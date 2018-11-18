#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SDL2/SDL.h>
#include <memory>

namespace myEngine
{

	class Keyboard
	{

	private:

		const Uint8 *m_state;

	public:

		Keyboard();
		~Keyboard();

		void update();

		bool getKey(SDL_Scancode _scancode);

	};

}

#endif // !KEYBOARD_H
