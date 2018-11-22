#ifndef MOUSE_H
#define MOUSE_H

#include <SDL2/SDL.h>
#include <memory>
#include <glm/glm.hpp>

namespace myEngine
{

	class Core;

	class Mouse
	{

	private:

		std::weak_ptr<Core> m_core;

		Uint32 m_state;

		bool m_started;
		bool m_centreLocked;

		int m_xPos;
		int m_xDelta;

		int m_yPos;
		int m_yDelta;

	public:

		Mouse();
		Mouse(std::weak_ptr<Core> _core);
		~Mouse();

		void update();

		bool getKey(int _keyCode);

		glm::ivec2 getMousePos() { return glm::ivec2(m_xPos, m_yPos); }
		glm::ivec2 getMouseDelta() { return glm::ivec2(m_xDelta, m_yDelta); }

		void setCentreLocked(bool _locked);
		void setVisible(bool _visible);

		void setCore(std::weak_ptr<Core> _core) { m_core = _core; }

	};

}


#endif // !MOUSE_H