#include <iostream>
#include <iomanip>

#include "RenderTexture.h"


namespace myEngine
{

	RenderTexture::RenderTexture()
	{

	}
	RenderTexture::RenderTexture(int _width, int _height)
	{
		setSize(_width, _height);
	}
	RenderTexture::RenderTexture(glm::ivec2 _size)
	{
		setSize(_size);
	}

	RenderTexture::~RenderTexture()
	{

	}

	void RenderTexture::init()
	{
		m_frameBufferId = 0;
		m_textureId = 0;
		m_renderBufferId = 0;

		//create frame buffer object
		glGenFramebuffers(1, &m_frameBufferId);
		if (!m_frameBufferId)
		{
			throw std::exception();
		}
		glBindFramebuffer(GL_FRAMEBUFFER, m_frameBufferId); //stays bound, as it needs texture and render buffer to be attached

																												//create texture
		glGenTextures(1, &m_textureId);
		if (!m_frameBufferId)
		{
			throw std::exception();
		}
		glBindTexture(GL_TEXTURE_2D, m_textureId);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_size.x, m_size.y, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBindTexture(GL_TEXTURE_2D, 0);

		//attach texture to frame buffer
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_textureId, 0);

		//create render buffer object
		glGenRenderbuffers(1, &m_renderBufferId);
		if (!m_renderBufferId)
		{
			throw std::exception();
		}
		glBindRenderbuffer(GL_RENDERBUFFER, m_renderBufferId);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, m_size.x, m_size.y);
		glBindRenderbuffer(GL_RENDERBUFFER, 0);

		//attach render buffer to frame buffer
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, m_renderBufferId);

		//check if frame buffer is complete
		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		{
			std::cout << std::hex << glCheckFramebufferStatus(GL_FRAMEBUFFER) << std::endl;
			throw std::exception();
		}

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	void RenderTexture::setSize(int _width, int _height) 
	{
		m_size.x = _width;
		m_size.y = _height;
	}
	void RenderTexture::setSize(glm::ivec2 _size)
	{
		m_size = _size; 
	}

	void RenderTexture::bindFrameBuffer()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_frameBufferId);
	}
}