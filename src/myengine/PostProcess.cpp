#include "PostProcess.h"

namespace myEngine
{

	PostProcess::PostProcess()
	{

	}
	PostProcess::~PostProcess()
	{

	}

	void PostProcess::createRenderTextures(int _amount)
	{
		for (int i = 0; i < _amount; i++)
		{
			m_workingRenderTextures.push_back(std::make_shared<RenderTexture>());
		}
	}

	void PostProcess::draw(	std::shared_ptr<RenderTexture> _subject, 
													std::shared_ptr<RenderTexture> _target, 
													std::shared_ptr<ShaderProgram> _shader)
	{
		if (m_screenMesh == nullptr)
		{
			m_screenMesh = std::make_shared<Mesh>();
			m_screenMesh->loadRect();
		}


		//bind target frame buffer
		_target->bindFrameBuffer();

		glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glm::mat4 modelMat = glm::mat4(1.0f);

		_shader->setModelMatrix(modelMat);

		glUseProgram(_shader->getId());

		glBindVertexArray(m_screenMesh->getModelVAO()->getId());

		//bind subject texture
		_subject->bindTexture();

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