#include <glm/ext.hpp>

#include "MeshRenderer.h"
#include "Transform.h"
#include "Camera.h"

namespace myEngine
{

	void MeshRenderer::draw()
	{
		m_shaderProg->setModelMatrix(getTransform()->getTransformMat());
		m_shaderProg->setViewMatrix(getCore()->getcurrentCamera()->getViewMatrix());
		m_shaderProg->setProjectionMatrix(glm::perspective(getCore()->getcurrentCamera()->getRadFOV(),
			getCore()->getWindowObject()->getWidth() / getCore()->getWindowObject()->getHeight(), 0.1f, 100.0f));

		//tell OpenGL which shader program to use
		glUseProgram(m_shaderProg->getId());

		//bind the VAO
		glBindVertexArray(m_mesh.lock()->getModelVAO()->getId());

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, m_shaderProg->getTexId());

		//draw the vertices in the VAO
		glDrawArrays(GL_TRIANGLES, 0, m_mesh.lock()->getVertexcount());

		//reset the state
		glBindTexture(GL_TEXTURE_2D, 0);
		glBindVertexArray(0);
		glUseProgram(0);
	}

	void MeshRenderer::awake()
	{

	}
	void MeshRenderer::start()
	{
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
		std::cout << "    Mesh Renderer" << std::endl;
	}

	void MeshRenderer::setMesh(std::shared_ptr<Mesh> _mesh)
	{
		m_mesh = _mesh;
	}
	void MeshRenderer::setTexture(std::shared_ptr<Texture> _texture)
	{
		m_shaderProg->setTexture(_texture);
	}
	void MeshRenderer::setShaders(std::string _vertShadAddress, std::string _fragShadAddress)
	{
		m_shaderProg = std::make_shared<ShaderProgram>(_vertShadAddress, _fragShadAddress);
	}

	

}