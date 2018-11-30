#ifndef ENVIROMENT_H
#define ENVIROMENT_H

#include <SDL2/SDL.h>
#include <deque>

namespace myEngine
{

	/**
	*	Enviroment Class
	*	Uses SDL_GetPerformanceCounter to calculate delta time
	*/
	class Enviroment
	{

	private:

		bool m_started;

		Uint64 m_thisTime;
		Uint64 m_lastTime;

		double m_deltaTime; //milliseconds

		int m_dTStoredCap = 30;

		std::deque<double> m_dTStored; ///< Deque of previous delta times, used to calculate an average FPS
		double m_FPS;

	public:

		Enviroment();
		~Enviroment();

		void start();

		void update();
		void calcdT();
		void calcFPS(); ///< Calculates average FPS based on previous delta times

		//returns delta time in milliseconds
		double getDeltaTime() { return m_deltaTime; }

	};

}

#endif // !ENVIROMENT_H
