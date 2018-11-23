#include "Core.h"
#include "Entity.h"
#include "Component.h"
#include "Transform.h"

namespace myEngine {

	Component::Component()
	{
		m_started = false;
	}

	std::shared_ptr<Entity> Component::getEntity()
	{

		return m_entity.lock();

	}

	std::shared_ptr<Core> Component::getCore()
	{

		return m_entity.lock()->getCore();

	}

	std::shared_ptr<Transform> Component::getTransform()
	{
		return m_entity.lock()->getComponent<Transform>();
	}

	void Component::awake()
	{
	}

	void Component::start()
	{
	}

	void Component::physicsUpdate()
	{
	}
	void Component::update()
	{
	}

	void Component::display()
	{
	}

	void Component::debug()
	{
		std::cout << "    Component Base Class" << std::endl;
	}

}
