#include <myengine/myengine.h>

#include "Move.h"

void Move::start()
{
}

void Move::update()
{

	float angle = 90.0f;

	getTransform()->localAxisRotateEulerDegrees(angle * getCore()->getEnviroment()->getDeltaTime() / 1000.0f, 0.0f, 0.0f);

}