#include "Move.h"
#include "Transform.h"

namespace myEngine
{

	void Move::start()
	{
		add = true;
		i = 0;
	}

	void Move::update()
	{
		if (add == true)
		{
			if (i < 200)
			{
				//getTransform()->translate(glm::vec3(0.02f, -0.02f, 0.0f));
				getTransform()->rotate(glm::vec3(0.0f, 0.02f, 0.0f));
				i++;
			}
			else
			{
				add = false;
			}
		}
		else if (add == false)
		{
			if (i > -200)
			{
				//getTransform()->translate(glm::vec3(-0.02f, 0.02f, 0.0f));
				getTransform()->rotate(glm::vec3(-0.0f, -0.02f, 0.0f));
				i--;
			}
			else
			{
				add = true;
			}
		}
	}


}