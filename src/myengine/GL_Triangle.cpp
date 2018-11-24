#include "GL_Triangle.h"

namespace myEngine
{

  void GL_Triangle::awake()
  {

  }

  void GL_Triangle::start()
  {
    std::cout << "GL_Triangle Start" << std::endl;

	glm::vec3 resize = glm::vec3(getCore()->getWindowObject()->getWidth() / 100.0f, getCore()->getWindowObject()->getHeight() / 100.0f, 1.0f);

    m_positions.push_back(glm::vec3(0.0f, 0.0f, 0.0f) / resize);
    m_positions.push_back(glm::vec3(1.0f, 1.0f, 0.0f) / resize);
    m_positions.push_back(glm::vec3(0.0f, 1.0f, 0.0f) / resize);

	m_positions.push_back(glm::vec3(0.0f, 0.0f, 0.0f) / resize);
	m_positions.push_back(glm::vec3(1.0f, 0.0f, 0.0f) / resize);
	m_positions.push_back(glm::vec3(1.0f, 1.0f, 0.0f) / resize);

	m_texcoords.push_back(glm::vec2(1.0f, 0.0f));
	m_texcoords.push_back(glm::vec2(0.0f, 1.0f));
	m_texcoords.push_back(glm::vec2(0.0f, 0.0f));

	m_texcoords.push_back(glm::vec2(1.0f, 0.0f));
	m_texcoords.push_back(glm::vec2(1.0f, 1.0f));
	m_texcoords.push_back(glm::vec2(0.0f, 1.0f));


    // - - - - - - - - - - - - - - - - - - - - - Create VBO - - - - - - - - - - - - - - - - - - - - - //

    m_positionsVBO = std::make_shared<VertexBuffer>();

    for (size_t i = 0; i < m_positions.size(); i++)
    {
      m_positionsVBO->addVertex(m_positions.at(i));
    }

	m_positionsVBO->upload();


	m_texcoordsVBO = std::make_shared<VertexBuffer>();

	for (size_t i = 0; i < m_texcoords.size(); i++)
	{
		m_texcoordsVBO->addVertex(m_texcoords.at(i));
	}

	m_texcoordsVBO->upload();

    // - - - - - - - - - - - - - - - - - - - - - Create VAO - - - - - - - - - - - - - - - - - - - - - //

    m_VAO = std::make_shared<VertexArray>();

    m_VAO->addBuffer(enums::ShaderAttribute::in_Position, m_positionsVBO);
	m_VAO->addBuffer(enums::ShaderAttribute::in_TexCoord, m_texcoordsVBO);

    m_VAO->upload();

    // - - - - - - - - - - - - - - - - - - - - - Create Shader Program - - - - - - - - - - - - - - - - - - - - - //

    m_shaderProg = std::make_shared<ShaderProgram>("../resources/GUI.vert", "../resources/textured.frag");

	// - - - - - - - - - - - - - - - - - - - - - Load Texture - - - - - - - - - - - - - - - - - - - - - //

	m_texture = std::make_shared<Texture>();
	m_texture->loadTexture("../resources/crosshair.png");

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

	glEnable(GL_BLEND);

    //tell OpenGL which shader program to use
    glUseProgram(m_shaderProg->getId());
    //bind the VAO
    glBindVertexArray(m_VAO->getId());

	m_texture->bindTexture();

    //draw the vertices in the VAO
    glDrawArrays(GL_TRIANGLES, 0, m_positions.size());

    //reset the state
	glBindTexture(GL_TEXTURE_2D, 0);
    glBindVertexArray(0);
    glUseProgram(0);

	glDisable(GL_BLEND);


  }

}