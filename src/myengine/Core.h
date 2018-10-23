#ifndef CORE_H
#define CORE_H

#include <memory>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <GL/glew.h>

#include "Window.h"

namespace myEngine {

  class Entity;

  class Core
  {

  private:
    std::vector<std::shared_ptr<Entity>> m_entities;
    std::shared_ptr<Window> m_windowObject;
    std::weak_ptr<Core> m_self;

    bool running;

  public:
    static std::shared_ptr<Core> init();
    std::shared_ptr<Window> createNewWindowObject(std::string _name, int _width, int _height);
    std::shared_ptr<Window> getWindowObject() { return m_windowObject; }

    void begin();

    void update();
    void display();

    void debug();

    void end();

    std::shared_ptr<Entity> addEntity(std::string _name);


  };

}

#endif //CORE_H
