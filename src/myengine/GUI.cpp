#include <glm/ext.hpp>

#include "GUI.h"

namespace myEngine
{

	GUIRect::GUIRect()
	{

	}
	GUIRect::~GUIRect()
	{

	}

	void GUIRect::GUI()
	{
		draw();
	}

	void GUIRect::draw()
	{
		m_shaderProg->setModelMatrix(glm::translate(glm::mat4(1.0), glm::vec3(m_size, 1.0f)));
		m_shaderProg->setProjectionMatrix(glm::ortho(0.0f, (float)getCore()->getWindowObject()->getWidth(), 0.0f, (float)getCore()->getWindowObject()->getHeight()));

		glUseProgram(m_shaderProg->getId());

		glBindVertexArray(m_mesh->getModelVAO()->getId());

		m_texture->bindTexture();

		glDrawArrays(GL_TRIANGLES, 0, m_mesh->getVertexcount());

		//reset the state
		glBindTexture(GL_TEXTURE_2D, 0);
		glBindVertexArray(0);
		glUseProgram(0);
	}

	void GUIRect::setRect(glm::vec2 _pos, glm::vec2 _size)
	{

		m_pos = _pos;
		m_size = _size;

		m_mesh = std::make_shared<Mesh>();
		m_mesh->loadRect(_size);

	}
	void GUIRect::setRect(float _x, float _y, float _w, float _h)
	{
		setRect(glm::vec2(_x, _y), glm::vec2(_w, _h));
	}

	void GUIRect::setTexture(std::shared_ptr<Texture> _texture)
	{
		m_texture = _texture;
	}
	void GUIRect::setTexture(std::shared_ptr<RenderTexture> _renderTex)
	{
		m_texture = std::static_pointer_cast<Texture, RenderTexture>(_renderTex);
	}

	void GUIRect::setShaders(std::string _vertShadAddress, std::string _fragShadAddress)
	{
		m_shaderProg = std::make_shared<ShaderProgram>(_vertShadAddress, _fragShadAddress);
	}

}