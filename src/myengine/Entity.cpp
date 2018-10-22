#include "Core.h"
#include "Entity.h"

#include <glm/glm.hpp>
#include <typeinfo>

namespace myEngine {

  void Entity::update()
  {
    for (size_t i = 0; i < m_components.size(); i++)
    {
      if (m_components.at(i)->m_started == false)
      {
        m_components.at(i)->start();
        m_components.at(i)->m_started = true;
      }
      m_components.at(i)->update();
    }
  }

  void Entity::display()
  {
    for (size_t i = 0; i < m_components.size(); i++)
    {
      m_components.at(i)->display();
    }
  }

  std::shared_ptr<Core> Entity::getCore()
  {
    return m_core.lock();
  }

}

