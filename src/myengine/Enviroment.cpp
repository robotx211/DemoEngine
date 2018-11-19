#include "Enviroment.h"

namespace myEngine
{

	Enviroment::Enviroment()
	{
		m_thisTime = 0;
		m_lastTime = 0;
	}
	Enviroment::~Enviroment()
	{

	}

	void Enviroment::start()
	{
		m_thisTime = SDL_GetPerformanceCounter();
		m_lastTime = 0;
		m_deltaTime = 0;
	}

	void Enviroment::update()
	{

		m_lastTime = m_thisTime;
		m_thisTime = SDL_GetPerformanceCounter();

		m_deltaTime = (double)((m_thisTime - m_lastTime) * 1000 / (double)SDL_GetPerformanceFrequency());

	}

}