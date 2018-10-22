#include "GL_Triangle.h"

namespace myEngine
{

  void GL_Triangle::awake()
  {
  }

  void GL_Triangle::start()
  {
  }

  void GL_Triangle::update()
  {
  }

  void GL_Triangle::display()
  {
    draw(getCore()->getWindowObject());
  }

  void GL_Triangle::draw(std::shared_ptr<Window> _windowObject)
  {
    SDL_Window *window = _windowObject->getWindow();

    //create SDL GL Context
    if (!SDL_GL_CreateContext(window))
    {
      std::cout << "GLContext is null" << std::endl;
      throw std::exception();
    }

    //init glew
    if (glewInit() != GLEW_OK)
    {
      std::cout << "glewInit failed" << std::endl;
      throw std::exception();
    }

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


    // - - - - - - - - - - - - - - - - - - - - - Load Vertex Shader - - - - - - - - - - - - - - - - - - - - - //


    // - - - - - - - - - - - - - - - - - - - - - Load Fragment Shader - - - - - - - - - - - - - - - - - - - - - //


    // - - - - - - - - - - - - - - - - - - - - - Create Shader Program - - - - - - - - - - - - - - - - - - - - - //

    m_shaderProg = std::make_shared<ShaderProgram>(m_vertexShaderSrc, m_fragmentShaderSrc);

    // - - - - - - - - - - - - - - - - - - - - - Draw Triangle - - - - - - - - - - - - - - - - - - - - - //

    //set clear colour of _window
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //tell OpenGL which shader program to use
    glUseProgram(m_shaderProg->getId());
    //bind the VAO
    glBindVertexArray(m_VAO->getId());

    //draw the vertices in the VAO
    glDrawArrays(GL_TRIANGLES, 0, m_positions.size());

    //reset the state
    glBindVertexArray(0);
    glUseProgram(0);


    SDL_GL_SwapWindow(window);



  }

}