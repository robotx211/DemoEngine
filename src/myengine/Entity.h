#ifndef ENTITY_H
#define ENTITY_H

#include <memory>
#include <vector>

#include "Core.h"

namespace myEngine {

	class Component;
	class Transform;

	/**
	*	Entity Class
	*	Contains vector of Components
	*/
	class Entity
	{

		friend class Core;

	private:
		std::string m_name;

		std::vector<std::shared_ptr<Component>> m_components; ///< All components attached to the Entity
		std::weak_ptr<Entity> m_self;
		std::weak_ptr<Core> m_core;

		bool m_delete; ///< Deletion flag

	public:
		Entity();
		Entity(std::string _name);
		~Entity();

		void setName(std::string _name) { m_name = _name; }
		std::string getName() { return m_name; }
		std::shared_ptr<Core> getCore() { return m_core.lock(); }

		void update(); ///< Calls start on all Components which have not started yet, calls Update on all Components
		void physicsUpdate(); ///< Calls physicsUpdate on all Components
		void lateUpdate(); ///< Calls lateUpdate on all Components
		void display(); ///< Calls display on all Components
		void GUI(); ///< Calls GUI on all Components

		void debug();

		template <typename T> std::shared_ptr<T> addComponent() ///< Creates a new component of type T, attaches it to the Entity
		{
			//needs error checking: if a non component is passed in, throw an exception
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

		template<typename T> std::shared_ptr<T> getComponent() ///< Attempts to return an attached Component of type T
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

		template<typename T> void removeComponent() ///< Attempts to remove an attached Component of type T
		{

			for (size_t i = 0; i < m_components.size(); i++)
			{
				markedComponent = std::dynamic_pointer_cast<T>(m_components.at(i));

				if (markedComponent != NULL)
				{
					m_components.erase(m_components.begin() + i);
					delete(markedComponent);
					return;
				}
			}

			//no component of type T found
			throw std::exception();

		}

		void markForDeletion() { m_delete = true; }



	};

}

#endif //ENTITY_H

