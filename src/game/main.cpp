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

  std::shared_ptr<Core> core = Core::init();

  std::shared_ptr<Entity> entity = core->addEntity();

  std::shared_ptr<Window> window = entity->addComponent<Window>();

  std::cout << "Press Enter To Finish" << std::endl;
  std::cin.get();

  return 0;
}