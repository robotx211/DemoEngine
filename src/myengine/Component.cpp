#include "Core.h"
#include "Entity.h"
#include "Component.h"

namespace myEngine {

  std::shared_ptr<Entity> Component::getEntity()
  {

    return m_entity.lock();

  }

  std::shared_ptr<Core> Component::getCore()
  {

    return m_entity.lock()->getCore();

  }

  void Component::awake()
  {
  }

  void Component::start()
  {
  }

  void Component::update()
  {
  }

  void Component::display()
  {
  }

}
