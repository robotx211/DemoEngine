#include "Move.h"
#include "Transform.h"
#include "Constants.h"
#include "Core.h"
#include "Keyboard.h"

namespace myEngine
{

	void Move::start()
	{
		add = true;
		i = 0;
	}

	void Move::update()
	{

		bool space = getCore()->getKeyboard()->getKey(SDL_SCANCODE_SPACE);

		if (space)
		{
			getTransform()->rotateEulerDegrees(glm::vec3(0.0f, 1.0f, 0.0f));
		}

	}


}