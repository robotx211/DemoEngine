#include <iostream>

#include "PostProcess.h"

namespace myEngine
{

	PostProcess::PostProcess()
	{
	}
	PostProcess::PostProcess(int _width, int _height)
	{
		setRenderTextureSize(_width, _height);
	}
	PostProcess::~PostProcess()
	{

	}

	std::shared_ptr<RenderTexture> PostProcess::createRenderTexture()
	{

		std::shared_ptr<RenderTexture> newRT = std::make_shared<RenderTexture>();
		
		newRT->setSize(m_renderTextureSize);
		newRT->init();

		return newRT;
	}

	void PostProcess::draw(	std::shared_ptr<Texture> _subject, std::shared_ptr<RenderTexture> _target, std::shared_ptr<ShaderProgram> _shader)
	{
		if (m_screenMesh == nullptr)
		{
			m_screenMesh = std::make_shared<Mesh>();
			m_screenMesh->loadRect();
		}


		//bind target frame buffer
		_target->bindFrameBuffer();

		//glBindFramebuffer(GL_FRAMEBUFFER, _target->getId());

		glUseProgram(_shader->getId());

		glBindVertexArray(m_screenMesh->getModelVAO()->getId());

		_shader->setUniform("in_Texture", 0);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, _subject->getId());

		glDrawArrays(GL_TRIANGLES, 0, m_screenMesh->getVertexcount());

		glBindFramebuffer(GL_FRAMEBUFFER, 0);

		glBindTexture(GL_TEXTURE_2D, 0);
		glBindVertexArray(0);
		glUseProgram(0);
	}

	void PostProcess::draw(std::shared_ptr<Texture> _subject, std::shared_ptr<Texture> _subject2, std::shared_ptr<RenderTexture> _target, std::shared_ptr<ShaderProgram> _shader)
	{
		if (m_screenMesh == nullptr)
		{
			m_screenMesh = std::make_shared<Mesh>();
			m_screenMesh->loadRect();
		}


		//bind target frame buffer
		_target->bindFrameBuffer();

		glUseProgram(_shader->getId());

		glBindVertexArray(m_screenMesh->getModelVAO()->getId());

		_shader->setUniform("in_TextureA", 0);
		_shader->setUniform("in_TextureB", 1);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, _subject->getId());
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, _subject2->getId());

		glDrawArrays(GL_TRIANGLES, 0, m_screenMesh->getVertexcount());

		glBindFramebuffer(GL_FRAMEBUFFER, 0);

		glBindTexture(GL_TEXTURE_2D, 0);
		glBindVertexArray(0);
		glUseProgram(0);
	}

	void PostProcess::apply(std::shared_ptr<RenderTexture> _targetTex)
	{
		//base function, do nothing
	}

}