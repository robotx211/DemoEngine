#include <glm/ext.hpp>

#include "MeshRenderer.h"
#include "Transform.h"
#include "Camera.h"
#include "Light.h"

namespace myEngine
{

	void MeshRenderer::draw()
	{
		//tell OpenGL which shader program to use
		glUseProgram(m_shaderProg->getId());

		m_shaderProg->setModelMatrix(getTransform()->getTransformMat());
		m_shaderProg->setViewMatrix(getCore()->getCurrentCamera()->getViewMatrix());
		m_shaderProg->setProjectionMatrix(glm::perspective(getCore()->getCurrentCamera()->getRadFOV(),
			getCore()->getCurrentCamera()->getAspectRatio(), 0.1f, 100.0f));


		getCore()->getCurrentLights().at(0)->setShaderData(m_shaderProg);

		//bind the texure
		if (m_texture != nullptr)
		{
			m_texture->bindTexture();
		}

		for (size_t i = 0; i < m_meshes.size(); i++)
		{
			//bind the VAO
			glBindVertexArray(m_meshes.at(i)->getModelVAO()->getId());

			//draw the vertices in the VAO
			glDrawArrays(GL_TRIANGLES, 0, m_meshes.at(i)->getVertexcount());

			glBindVertexArray(0);
		}

		//reset the state
		glBindTexture(GL_TEXTURE_2D, 0);
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
		//m_mesh = _mesh;

		m_meshes.clear();

		m_meshes.push_back(_mesh);
	}
	void MeshRenderer::setMesh(std::vector<std::shared_ptr<Mesh>> *_meshes)
	{
		m_meshes.clear();

		for (size_t i = 0; i < _meshes->size(); i++)
		{
			m_meshes.push_back(_meshes->at(i));
		}
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