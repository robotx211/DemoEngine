#include <memory>
#include <vector>
#include <iostream>

namespace myEngine {

	class Entity;
	class Window;

	class Core
	{

	private:
		std::vector<std::shared_ptr<Entity>> entities;
		std::shared_ptr<Window> window;
		std::weak_ptr<Core> self;

	public:
		static std::shared_ptr<Core> init();
		std::shared_ptr<Window> createWindow(std::string _name, int _width, int _height);

		void start();

		void update();
		void display();

		void stop();


		std::shared_ptr<Entity> addEntity();


	};

}
