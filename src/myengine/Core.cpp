#include "Core.h"
#include "Entity.h"

namespace myEngine {

	std::shared_ptr<Core> Core::init()
	{
		std::shared_ptr<Core> newCore = std::make_shared<Core>();
		newCore->self = newCore;

		return newCore;
	}

	void Core::start()
	{
		std::cout << "Core Start" << std::endl;
	}

	void Core::update()
	{
		for (size_t i = 0; i < entities.size(); i++)
		{
			entities.at(i)->update();
		}
	}

	void Core::display()
	{
		for (size_t i = 0; i < entities.size(); i++)
		{
			entities.at(i)->display();
		}
	}

	void Core::stop()
	{
		std::cout << "Core Stop" << std::endl;
	}

	std::shared_ptr<Entity> Core::addEntity()
	{
		std::shared_ptr<Entity> newEntity = std::make_shared<Entity>();

		newEntity->self = newEntity;
		newEntity->core = this->self;

		entities.push_back(newEntity);

		return newEntity;
	}

}

