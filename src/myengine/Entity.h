#ifndef ENTITY_H
#define ENTITY_H

#include <memory>
#include <vector>

#include "Core.h"

namespace myEngine {

	class Component;
	class Transform;

	class Entity
	{

		friend class Core;

	private:
		std::string m_name;

		std::vector<std::shared_ptr<Component>> m_components;
		std::weak_ptr<Entity> m_self;
		std::weak_ptr<Core> m_core;

	public:
		Entity();
		Entity(std::string _name);

		std::string getName() { return m_name; }
		std::shared_ptr<Core> getCore() { return m_core.lock(); }


		void physicsUpdate();
		void update();
		void display();

		void debug();

		template <typename T> std::shared_ptr<T> addComponent()
		{
			std::shared_ptr<T> newComponent = std::make_shared<T>();

			newComponent->m_self = newComponent;
			newComponent->m_entity = this->m_self;

			newComponent->awake();
			newComponent->m_started = false;

			m_components.push_back(newComponent);

			return newComponent;
		}
		//add more for initialisation parameters

		//std::shared_ptr<Transform> getTransform()
		//{
		//	return getComponent<Transform>();
		//}

		template<typename T> std::shared_ptr<T> getComponent()
		{
			std::shared_ptr<T> returnComponent = NULL;

			for (size_t i = 0; i < m_components.size(); i++)
			{
				returnComponent = std::dynamic_pointer_cast<T>(m_components.at(i));

				if (returnComponent != NULL)
				{
					return returnComponent;
				}
			}

			//no component of type T found
			throw std::exception();
		}

		template<typename T> void removeComponent()
		{

			for (size_t i = 0; i < m_components.size(); i++)
			{
				markedComponent = std::dynamic_pointer_cast<T>(m_components.at(i));

				if (markedComponent != NULL)
				{
					m_components.erase(m_components.begin() + i); //does this delete the component?
					delete(markedComponent);
					return;
				}
			}

			//no component of type T found
			throw std::exception();

		}



	};

}

#endif //ENTITY_H

