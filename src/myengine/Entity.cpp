#include "Core.h"
#include "Entity.h"

#include <glm/glm.hpp>

void Entity::update()
{
  for each (std::shared_ptr<Component> comp in components)
  {
    comp->update();
  }
}

void Entity::display()
{
  for each (std::shared_ptr<Component> comp in components)
  {
    comp->display();
  }
}

void Entity::setCore(std::shared_ptr<Core> _core)
{
  core = _core;
}

std::shared_ptr<Core> Entity::getCore()
{
  return core.lock();
}

