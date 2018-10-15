#include <memory>
#include <vector>

#include "Component.h"

namespace myEngine {

	class Core;

	class Entity
	{

		friend class Core;

	private:
		std::vector<std::shared_ptr<Component>> components;
		std::weak_ptr<Entity> self;
		std::weak_ptr<Core> core;

		void update();
		void display();

	public:
		void setCore(std::shared_ptr<Core> _core);
		std::shared_ptr<Core> getCore();
		template <typename T> std::shared_ptr<T> addComponent()
		{
			std::shared_ptr<T> newComponent = std::make_shared<T>();

			newComponent->self = newComponent;
			newComponent->entity = this->self;

			newComponent->awake();
			newComponent->started = false;

			components.push_back(newComponent);

			return newComponent;
		}

		//add more for initialisation parameters



	};

}

