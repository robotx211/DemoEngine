#include "Core.h"
#include "Entity.h"
#include "Component.h"


void Component::onAwake()
{

}

void Component::onStart()
{

}

void Component::onUpdate()
{

}

void Component::onDisplay()
{
  
}

void Component::setEntity(std::shared_ptr<Entity> _entity)
{
  entity = _entity;
}

std::shared_ptr<Entity> Component::getEntity()
{

  return entity.lock;

}

std::shared_ptr<Core> Component::getCore()
{

  return entity.lock()->getCore();

}

void Component::awake()
{
  onAwake();
}

void Component::start()
{
  onStart();
}

void Component::update()
{
  onUpdate();
}

void Component::display()
{
  onDisplay();
}
