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
	}

	void Move::update()
	{

		if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_UP))
		{
			getTransform()->rotateEulerDegrees(-90 * getCore()->getEnviroment()->getDeltaTime() / 1000, 0.0f, 0.0f);
		}
		else if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_DOWN))
		{
			getTransform()->rotateEulerDegrees(90 * getCore()->getEnviroment()->getDeltaTime() / 1000, 0.0f, 0.0f);
		}

		if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_LEFT))
		{
			getTransform()->rotateEulerDegrees(0.0f, -90 * getCore()->getEnviroment()->getDeltaTime() / 1000, 0.0f);
		}
		else if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_RIGHT))
		{
			getTransform()->rotateEulerDegrees(0.0f, 90 * getCore()->getEnviroment()->getDeltaTime() / 1000, 0.0f);
		}

	}


}