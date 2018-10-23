#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <exception>
#include <iostream>
#include <vector>

#include "Component.h"
#include "Window.h"

#include "VertexArray.h"
#include "ShaderProgram.h"

namespace myEngine
{

  class GL_Triangle : public Component
  {

  private:

		//const GLfloat m_positions[9] = {
		//	0.0f, 0.5f, 0.0f,
		//	-0.5f, -0.5f, 0.0f,
		//	0.5f, -0.5f, 0.0f
		//};

    std::vector<glm::vec3> m_positions;

    std::string m_vertexShaderSrc =
		"attribute vec3 in_Position;            " \
		"                                       " \
		"void main()                            " \
		"{                                      " \
		" gl_Position = vec4(in_Position, 1.0); " \
		"}                                      ";

	std::string m_fragmentShaderSrc =
		"void main()                        " \
		"{                                  " \
		" gl_FragColor = vec4(0, 1, 1, 1);  " \
		"}                                  ";

    std::shared_ptr<VertexBuffer> m_positionsVBO;

    std::shared_ptr<VertexArray> m_VAO;

    std::shared_ptr<ShaderProgram> m_shaderProg;

  public:
    void draw();

    void awake();
    void start();
    void update();
    void display();
    
    void debug();

  };

}