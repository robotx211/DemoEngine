#include <iostream>
#include <memory>

#include "myengine/Core.h"
#include "myengine/Entity.h"
#include "myengine/Component.h"

int main()
{

  std::cout << "Start" << std::endl;

  std::shared_ptr<Core> core = std::make_shared<Core>();

  std::cout << "Core Status: " << (core != NULL) << std::endl;

  std::shared_ptr<Entity> newEntity = core->addEntity();

  std::cout << "Entity Status: " << (newEntity != NULL) << std::endl;
  std::cout << "Core Status: " << (core != NULL) << std::endl;

  std::shared_ptr<Component> newComponet = newEntity->addComponent<Component>();

  std::cout << "Component Status: " << (newComponet != NULL) << std::endl;
  std::cout << "Entity Status: " << (newEntity != NULL) << std::endl;
  std::cout << "Core Status: " << (core != NULL) << std::endl;

  std::cout << "Press Enter To Finish" << std::endl;
  std::cin.get();

  return 0;
}