#include "Core.h"
#include "Entity.h"

void Core::start()
{
  std::cout << "Core Start" << std::endl;
}

void Core::stop()
{
  std::cout << "Core Stop" << std::endl;
}

std::shared_ptr<Entity> Core::addEntity()
{
  std::shared_ptr<Entity> newEntity = std::make_shared<Entity>();

  newEntity.get();

  entities.push_back(newEntity);

  return newEntity;
}

