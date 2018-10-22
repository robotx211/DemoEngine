#ifndef MYENGINE_COMPONENT_H
#define MYENGINE_COMPONENT_H

#include <memory>
#include <vector>
#include <iostream>

#include "Core.h"
#include "Entity.h"

namespace myEngine {

  class Component
  {

    friend class Entity;

  private:
    std::weak_ptr<Component> m_self;
    std::weak_ptr<Entity> m_entity;

    bool m_started;

  public:
    std::shared_ptr<Entity> getEntity();
    std::shared_ptr<Core> getCore();

    virtual void awake();
    virtual void start();
    virtual void update();
    virtual void display();

  };

}

#endif