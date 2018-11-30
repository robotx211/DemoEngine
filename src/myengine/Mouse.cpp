#include <iostream>

#include "Mouse.h"
#include "Core.h"


//debugging
#include <bitset>

namespace myEngine
{

	Mouse::Mouse()
	{
		m_xPos = 0;
		m_xDelta = 0;

		m_yPos = 0;
		m_yDelta = 0;

		m_started = false;
		m_centreLocked = false;
	}
	Mouse::Mouse(std::weak_ptr<Core> _core)
	{
		m_xPos = 0;
		m_xDelta = 0;

		m_yPos = 0;
		m_yDelta = 0;

		setCore(_core);

		m_started = false;
		m_centreLocked = false;
	}

	Mouse::~Mouse()
	{

	}

	void Mouse::update()
	{
		int xBefore = m_xPos;
		int yBefore = m_yPos;

		SDL_PumpEvents();
		m_state = SDL_GetMouseState(&m_xPos, &m_yPos);

		if (m_started == false)
		{
			m_xDelta = 0;
			m_yDelta = 0;

			m_started = true;
		}
		else {
			m_xDelta = m_xPos - xBefore;
			m_yDelta = m_yPos - yBefore;
		}

		//resets the mouse position if needed
		if (m_centreLocked == true)
		{
			m_xPos = m_core.lock()->getWindowObject()->getWidth() / 2;
			m_yPos = m_core.lock()->getWindowObject()->getHeight() / 2;

			SDL_WarpMouseInWindow(NULL, m_xPos, m_yPos);
		}

	}

	bool Mouse::getKey(int _keyCode)
	{
		return m_state & SDL_BUTTON(_keyCode);
	}

	void Mouse::setCentreLocked(bool _locked)
	{
		m_centreLocked = _locked;

		if (m_centreLocked)
		{
			m_xPos = m_core.lock()->getWindowObject()->getWidth() / 2;
			m_yPos = m_core.lock()->getWindowObject()->getHeight() / 2;

			SDL_WarpMouseInWindow(NULL, m_xPos, m_yPos);
		}
	}
	void Mouse::setVisible(bool _visible)
	{
		if (_visible)
		{
			SDL_ShowCursor(SDL_ENABLE);
		}
		else
		{
			SDL_ShowCursor(SDL_DISABLE);
		}
	}

	

}
