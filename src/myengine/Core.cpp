#include "Core.h"
#include "Entity.h"

namespace myEngine {

	std::shared_ptr<Core> Core::init()
	{
		std::shared_ptr<Core> newCore = std::make_shared<Core>();
		newCore->m_self = newCore;

		return newCore;
	}

	std::shared_ptr<Window> Core::createNewWindowObject(std::string _name, int _width, int _height)
	{
		std::shared_ptr<Window> newWindowObject = std::make_shared<Window>(_name, _width, _height);

        m_windowObject = newWindowObject;

		return m_windowObject;

	}


	void Core::begin()
	{
		std::cout << "Core Start" << std::endl;
	}

	void Core::update()
	{
		for (size_t i = 0; i < m_entities.size(); i++)
		{
			m_entities.at(i)->update();
		}
	}

	void Core::display()
	{
		for (size_t i = 0; i < m_entities.size(); i++)
		{
			m_entities.at(i)->display();
		}
	}

	void Core::end()
	{
		std::cout << "Core Stop" << std::endl;
	}

	std::shared_ptr<Entity> Core::addEntity()
	{
		std::shared_ptr<Entity> newEntity = std::make_shared<Entity>();

		newEntity->m_self = newEntity;
		newEntity->m_core = m_self;

		m_entities.push_back(newEntity);

		return newEntity;
	}

}

