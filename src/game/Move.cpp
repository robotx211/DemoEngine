#include <myengine/myengine.h>

#include "Move.h"

void Move::start()
	{
	}

	void Move::update()
	{

		float forwardMovement = 0.0f;
		float strafeMovement = 0.0f;

		if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_W))
		{
			forwardMovement += 1.0f;
		}
		else if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_S))
		{
			forwardMovement -= 1.0f;
		}

		if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_A))
		{
			strafeMovement += 1.0f;
		}
		else if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_D))
		{
			strafeMovement -= 1.0f;
		}

		glm::vec3 moveVec = (getTransform()->getForward() * forwardMovement * 0.1f) + (getTransform()->getLeft() * strafeMovement * 0.1f);

		getTransform()->translate(moveVec * glm::vec3(1, 0, 1));

	}