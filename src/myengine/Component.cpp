#include "Core.h"
#include "Entity.h"
#include "Component.h"


void Component::onInit()
{

}

void Component::onBegin()
{

}

void Component::onTick()
{

}

void Component::onDisplay()
{
  
}

std::shared_ptr<Entity> Component::getEntity()
{

  return entity.lock();

}

std::shared_ptr<Core> Component::getCore()
{

  return entity.lock()->getCore();

}

void Component::tick()
{
  onTick();
}

void Component::display()
{
  onDisplay();
}
