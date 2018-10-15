#include "Core.h"
#include "Entity.h"

namespace myEngine {

	void Component::onAwake()
	{
		std::cout << "Component Base Class Awake" << std::endl;
	}

	void Component::onStart()
	{
		std::cout << "Component Base Class Start" << std::endl;
	}

	void Component::onUpdate()
	{
		std::cout << "Component Base Class Update" << std::endl;
	}

	void Component::onDisplay()
	{
		std::cout << "Component Base Class Display" << std::endl;
	}

	void Component::setEntity(std::shared_ptr<Entity> _entity)
	{
		entity = _entity;
	}

	std::shared_ptr<Entity> Component::getEntity()
	{

		return entity.lock();

	}

	std::shared_ptr<Core> Component::getCore()
	{

		return entity.lock()->getCore();

	}

	void Component::awake()
	{
		onAwake();
	}

	void Component::start()
	{
		onStart();
	}

	void Component::update()
	{
		onUpdate();
	}

	void Component::display()
	{
		onDisplay();
	}

}
