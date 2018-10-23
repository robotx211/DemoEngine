#include <iostream>
#include <memory>

#include <myengine/myengine.h>

int main()
{

  std::cout << "Start" << std::endl;

  std::shared_ptr<myEngine::Core> core = myEngine::Core::init();
  core->createNewWindowObject("main window", 1280, 720);

  std::shared_ptr<myEngine::Entity> entity = core->addEntity("Triangle");

  std::shared_ptr<myEngine::GL_Triangle> triangle = entity->addComponent<myEngine::GL_Triangle>();

  core->begin();

  return 0;
}
