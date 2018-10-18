#include <iostream>
#include <memory>

#include "myengine/Core.h"
#include "myengine/Entity.h"
#include "myengine/Component.h"
#include "myengine/Transform.h"
#include "myengine/Window.h"
#include "myengine/GL_Triangle.h"

int main()
{

  std::cout << "Start" << std::endl;

  std::shared_ptr<myEngine::Core> core = myEngine::Core::init();
  core->createNewWindowObject("main window", 1280, 720);

  std::shared_ptr<myEngine::Entity> entity = core->addEntity();

  std::shared_ptr<myEngine::GL_Triangle> triangle = entity->addComponent<myEngine::GL_Triangle>();

  triangle->draw(core->getWindowObject());

  std::cout << "Press Enter To Finish" << std::endl;
  std::cin.get();

  return 0;
}
