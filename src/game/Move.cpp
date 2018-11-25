#include <myengine/myengine.h>

#include "Move.h"

void Move::start()
	{
	}

	void Move::update()
	{

		float angle = 90.0f;

		if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_H))
		{ 
			getTransform()->localAxisRotateEulerDegrees(angle * getCore()->getEnviroment()->getDeltaTime() / 1000.0f, 0.0f, 0.0f);
		}

	}