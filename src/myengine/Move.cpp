#include "Move.h"
#include "Transform.h"
#include "Constants.h"
#include "Core.h"
#include "Keyboard.h"
#include "Mouse.h"

namespace myEngine
{

	void Move::start()
	{
		add = true;
		i = 0;
	}

	void Move::update()
	{
		getCore()->getMouse()->setCentreLocked(false);

		bool leftMb = getCore()->getMouse()->getKey(SDL_BUTTON_LEFT);
		bool rightMb = getCore()->getMouse()->getKey(SDL_BUTTON_RIGHT);

		if (leftMb)
		{
			getTransform()->rotateEulerDegrees(0.0f, -1.0f, 0.0f);
		}
		else if (rightMb)
		{
			getTransform()->rotateEulerDegrees(0.0f, 1.0f, 0.0f);
		}

	}


}