#include "Core.h"
#include "Entity.h"
#include "Component.h"

void Entity::tick()
{
  for each (std::shared_ptr<Component> comp in components)
  {
    comp->tick();
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


template <class T> std::shared_ptr<T> Entity::addComponent(T _type)
{
  //if Type T does not inherit from Component, throw exception
  if (std::is_base_of < type(Component), type(T) == false)
  {
    throw std::exception();
  }

  std::shared_ptr<T> newComponent = std::make_shared<T>();

  components.push_back(newComponent);

  return newComponent;
}

