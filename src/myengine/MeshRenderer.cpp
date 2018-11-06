#include "MeshRenderer.h"

namespace myEngine
{

	void MeshRenderer::draw()
	{
		//tell OpenGL which shader program to use
		glUseProgram(m_shaderProg->getId());
		//bind the VAO
		glBindVertexArray(m_mesh.lock()->getModelVAO()->getId());

		//draw the vertices in the VAO
		glDrawArrays(GL_TRIANGLES, 0, m_mesh.lock()->getVertexcount());

		//reset the state
		glBindVertexArray(0);
		glUseProgram(0);
	}

	void MeshRenderer::awake()
	{

	}
	void MeshRenderer::start()
	{
		std::cout << "MeshRenderer Start" << std::endl;

	}
	void MeshRenderer::update()
	{
	}
	void MeshRenderer::display()
	{
		draw();
	}

	void MeshRenderer::debug()
	{

	}

	void MeshRenderer::setMesh(std::shared_ptr<Mesh> _mesh)
	{
		m_mesh = _mesh;
	}
	void MeshRenderer::setTexture()
	{

	}
	void MeshRenderer::setShaders(std::string _vertShadAddress, std::string _fragShadAddress)
	{
		m_shaderProg = std::make_shared<ShaderProgram>(_vertShadAddress, _fragShadAddress);
	}

	

}