#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <exception>
#include <iostream>

#include "Component.h"
#include "Window.h"

namespace myEngine
{

  class GL_Triangle : public Component
  {

  private:

  public:
    void draw(std::shared_ptr<Window> _windowObject);

  };

}