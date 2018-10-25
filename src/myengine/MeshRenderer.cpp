#include "MeshRenderer.h"

namespace myEngine
{

	void MeshRenderer::draw()
	{

	}

	void MeshRenderer::awake()
	{

	}
	void MeshRenderer::start()
	{
		std::cout << "GL_Triangle Start" << std::endl;

		// - - - - - - - - - - - - - - - - - - - - - Create VBO - - - - - - - - - - - - - - - - - - - - - //

		m_positionsVBO = std::make_shared<VertexBuffer>();

		std::shared_ptr<std::vector<glm::vec3>> positions = m_mesh->getVertexPositions();

		for (size_t i = 0; i < positions->size(); i++)
		{
			m_positionsVBO->addVertex(positions->at(i));
		}

		m_positionsVBO->upload();

		// - - - - - - - - - - - - - - - - - - - - - Create VAO - - - - - - - - - - - - - - - - - - - - - //

		m_VAO = std::make_shared<VertexArray>();

		m_VAO->addBuffer(ShaderAttribute::in_Position, m_positionsVBO);

		m_VAO->upload();

		// - - - - - - - - - - - - - - - - - - - - - Create Shader Program - - - - - - - - - - - - - - - - - - - - - //

		m_shaderProg = std::make_shared<ShaderProgram>(m_vertexShaderSrc, m_fragmentShaderSrc);

	}
	void MeshRenderer::update()
	{

	}
	void MeshRenderer::display()
	{

	}

	void MeshRenderer::debug()
	{

	}

}