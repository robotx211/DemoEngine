#ifndef ENVIROMENT_H
#define ENVIROMENT_H

#include <SDL2/SDL.h>

namespace myEngine
{

	class Enviroment
	{

	private:

		Uint64 m_thisTime;
		Uint64 m_lastTime;

		double m_deltaTime;

	public:

		Enviroment();
		~Enviroment();

		void start();
		void update();

		double deltaTime() { return m_deltaTime; }

	};

}

#endif // !ENVIROMENT_H
