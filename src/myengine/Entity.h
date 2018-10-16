#include <memory>
#include <vector>

#include "Component.h"

namespace myEngine {

	class Core;

	class Entity
	{

		friend class Core;

	private:
	  std::vector<std::shared_ptr<Component>> m_components;
	  std::weak_ptr<Entity> m_self;
	  std::weak_ptr<Core> m_core;

	  void update();
	  void display();

	public:
	  std::shared_ptr<Core> getCore();
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



	};

}

