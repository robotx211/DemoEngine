#include <myengine/myengine.h>

#include "Move.h"

void Move::start()
	{
		add = true;
	}

	void Move::update()
	{

		if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_UP))
		{
			getTransform()->worldAxisRotateEulerDegrees(-90 * getCore()->getEnviroment()->getDeltaTime() / 1000, 0.0f, 0.0f);
		}
		else if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_DOWN))
		{
			getTransform()->worldAxisRotateEulerDegrees(90 * getCore()->getEnviroment()->getDeltaTime() / 1000, 0.0f, 0.0f);
		}

		if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_LEFT))
		{
			getTransform()->worldAxisRotateEulerDegrees(0.0f, -90 * getCore()->getEnviroment()->getDeltaTime() / 1000, 0.0f);
		}
		else if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_RIGHT))
		{
			getTransform()->worldAxisRotateEulerDegrees(0.0f, 90 * getCore()->getEnviroment()->getDeltaTime() / 1000, 0.0f);
		}

		if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_SPACE))
		{
			getTransform()->setLocalOrientation(glm::quat(glm::vec3(0.0f, 0.0f, 0.0f)));
		}

	}