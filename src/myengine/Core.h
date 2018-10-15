#include <memory>
#include <vector>
#include <iostream>

namespace myEngine {

	class Entity;

	class Core
	{

	private:
		std::vector<std::shared_ptr<Entity>> entities;
		std::weak_ptr<Core> self;

	public:
		static std::shared_ptr<Core> init();

		void start();

		void update();
		void display();

		void stop();


		std::shared_ptr<Entity> addEntity();


	};

}
