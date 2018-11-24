#include <glm/ext.hpp>

#include "MeshRenderer.h"
#include "Transform.h"
#include "Camera.h"

namespace myEngine
{

	void MeshRenderer::draw()
	{
		m_shaderProg->setModelMatrix(getTransform()->getTransformMat());
		m_shaderProg->setViewMatrix(getCore()->getCurrentCamera()->getViewMatrix());
		m_shaderProg->setProjectionMatrix(glm::perspective(getCore()->getCurrentCamera()->getRadFOV(),
			getCore()->getCurrentCamera()->getAspectRatio(), 0.1f, 100.0f));

		//tell OpenGL which shader program to use
		glUseProgram(m_shaderProg->getId());

		//bind the VAO
		glBindVertexArray(m_mesh->getModelVAO()->getId());

		m_texture->bindTexture();

		//draw the vertices in the VAO
		glDrawArrays(GL_TRIANGLES, 0, m_mesh->getVertexcount());

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
		m_texture = _texture;
	}
	void MeshRenderer::setTexture(std::shared_ptr<RenderTexture> _renderTex)
	{
		m_texture = std::static_pointer_cast<Texture, RenderTexture>(_renderTex);
	}

	void MeshRenderer::setShaders(std::string _vertShadAddress, std::string _fragShadAddress)
	{
		m_shaderProg = std::make_shared<ShaderProgram>(_vertShadAddress, _fragShadAddress);
	}

	

}