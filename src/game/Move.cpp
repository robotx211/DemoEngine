#include <myengine/myengine.h>

#include "Move.h"

void Move::start()
{
}

void Move::update()
{

	float angle = 90.0f;

	getTransform()->localAxisRotateEulerDegrees(0.0f, angle * getCore()->getEnviroment()->getDeltaTime() / 3000.0f, 0.0f);

}