#include "Core.h"
#include "Entity.h"

#include <glm/glm.hpp>

namespace myEngine {

	void Entity::update()
	{
		for (size_t i = 0; i < components.size(); i++)
		{
			if (components.at(i)->started == false)
			{
				components.at(i)->start();
				components.at(i)->started = true;
			}
			components.at(i)->update();
		}
	}

	void Entity::display()
	{
		for (size_t i = 0; i < components.size(); i++)
		{
			components.at(i)->display();
		}
	}

	void Entity::setCore(std::shared_ptr<Core> _core)
	{
		core = _core;
	}

	std::shared_ptr<Core> Entity::getCore()
	{
		return core.lock();
	}

}

