#include "Core.h"
#include "Entity.h"
#include "Component.h"

#include <glm/glm.hpp>
#include <typeinfo>

namespace myEngine {

  Entity::Entity()
  {
	  m_delete = false;
  }

  Entity::Entity(std::string _name)
  {
    m_name = _name;
  }

  Entity::~Entity()
  {
	  std::cout << "Entity Destructor Called" << std::endl;
  }


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
  void Entity::physicsUpdate()
  {
	  for (size_t i = 0; i < m_components.size(); i++)
	  {

		  m_components.at(i)->physicsUpdate();
	  }
  } 
  void Entity::lateUpdate()
  {
	  for (size_t i = 0; i < m_components.size(); i++)
	  {
		  m_components.at(i)->lateUpdate();
	  }
  }

  void Entity::display()
  {
		for (size_t i = 0; i < m_components.size(); i++)
    {
      m_components.at(i)->display();
    }
  }

  void Entity::debug()
  {
    std::cout << "  " << m_name << std::endl;
    std::cout << "  Components: " << m_components.size() << std::endl;

    for (size_t i = 0; i < m_components.size(); i++)
    {
      m_components.at(i)->debug();
    }
  }





}

