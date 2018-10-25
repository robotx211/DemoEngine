#include "GL_Triangle.h"

namespace myEngine
{

  void GL_Triangle::awake()
  {

  }

  void GL_Triangle::start()
  {
    std::cout << "GL_Triangle Start" << std::endl;

    m_positions.push_back(glm::vec3(0.0f, 0.5f, 0.0f));
    m_positions.push_back(glm::vec3(-0.5f, -0.5f, 0.0f));
    m_positions.push_back(glm::vec3(0.5f, -0.5f, 0.0f));


    // - - - - - - - - - - - - - - - - - - - - - Create VBO - - - - - - - - - - - - - - - - - - - - - //

    m_positionsVBO = std::make_shared<VertexBuffer>();

    for (size_t i = 0; i < m_positions.size(); i++)
    {
      m_positionsVBO->addVertex(m_positions.at(i));
    }

    m_positionsVBO->upload();

    // - - - - - - - - - - - - - - - - - - - - - Create VAO - - - - - - - - - - - - - - - - - - - - - //

    m_VAO = std::make_shared<VertexArray>();

    m_VAO->addBuffer(ShaderAttribute::in_Position, m_positionsVBO);

    m_VAO->upload();

    // - - - - - - - - - - - - - - - - - - - - - Create Shader Program - - - - - - - - - - - - - - - - - - - - - //

    m_shaderProg = std::make_shared<ShaderProgram>(m_vertexShaderSrc, m_fragmentShaderSrc);

  }

  void GL_Triangle::update()
  {

    m_positionsVBO->upload();

    m_VAO->upload();

    m_shaderProg->link();

  }

  void GL_Triangle::display()
  {
		draw();
  }

  void GL_Triangle::debug()
  {
    std::cout << "    GL_Triangle" << std::endl;
  }

  void GL_Triangle::draw()
  {
		// - - - - - - - - - - - - - - - - - - - - - Draw Triangle - - - - - - - - - - - - - - - - - - - - - //

    //tell OpenGL which shader program to use
    glUseProgram(m_shaderProg->getId());
    //bind the VAO
    glBindVertexArray(m_VAO->getId());

    //draw the vertices in the VAO
    glDrawArrays(GL_TRIANGLES, 0, m_positions.size());

    //reset the state
    glBindVertexArray(0);
    glUseProgram(0);



  }

}