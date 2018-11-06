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