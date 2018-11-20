#include <iostream>

#include "Enviroment.h"

namespace myEngine
{

	Enviroment::Enviroment()
	{
		m_started = false;

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

		m_started = true;
	}

	void Enviroment::update()
	{

		if (m_started == false)
		{
			start();
		}

		calcdT();
		calcFPS();

	}
	void Enviroment::calcdT()
	{
		m_lastTime = m_thisTime;
		m_thisTime = SDL_GetPerformanceCounter();

		m_deltaTime = (double)((m_thisTime - m_lastTime) * 1000 / (double)SDL_GetPerformanceFrequency());

		//std::cout << "dT = " << m_deltaTime << std::endl;
	}
	void Enviroment::calcFPS()
	{
		if (m_dTStored.size() < m_dTStoredCap)
		{
			m_dTStored.push_back(m_deltaTime);
		}
		else
		{
			m_dTStored.pop_front();
			m_dTStored.push_back(m_deltaTime);
		}

		m_FPS = 0.0; //start
		for (size_t i = 0; i < m_dTStored.size(); i++)
		{
			m_FPS += m_dTStored.at(i); //sum of dTs
		}
		m_FPS = m_FPS / (double)m_dTStored.size(); //avg dT
		m_FPS = 1000 / m_FPS;

		//std::cout << "fps = " << m_FPS << std::endl;
	}

}