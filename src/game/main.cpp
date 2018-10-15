#include <iostream>
#include <memory>

#include "myengine/Core.h"
#include "myengine/Entity.h"
#include "myengine/Component.h"
#include "myengine/Transform.h"
#include "myengine/Window.h"

int main()
{

  std::cout << "Start" << std::endl;

  std::shared_ptr<myEngine::Core> core = myEngine::Core::init();

  std::shared_ptr<myEngine::Entity> entity = core->addEntity();

	std::shared_ptr<myEngine::Component> component = entity->addComponent<myEngine::Component>();
	std::shared_ptr<myEngine::Transform> transform = entity->addComponent<myEngine::Transform>();
  std::shared_ptr<myEngine::Window> window = entity->addComponent<myEngine::Window>();

	core->update();
	core->display();

  std::cout << "Press Enter To Finish" << std::endl;
  std::cin.get();

  return 0;
}