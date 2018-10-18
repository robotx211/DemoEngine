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

		const GLfloat m_positions[9] = {
			0.0f, 0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f
		};

		const GLchar *m_vertexShaderSrc =
			"attribute vec3 in_Position;            " \
			"                                       " \
			"void main()                            " \
			"{                                      " \
			" gl_Position = vec4(in_Position, 1.0); " \
			"}                                      ";

		const GLchar *m_fragmentShaderSrc =
			"void main()                        " \
			"{                                  " \
			" gl_FragColor = vec4(1, 1, 1, 1);  " \
			"}                                  ";

  public:
    void draw(std::shared_ptr<Window> _windowObject);

  };

}