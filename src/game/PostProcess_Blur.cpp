#include "PostProcess_Blur.h"

#include <glm/glm.hpp>

PostProcess_Blur::PostProcess_Blur()
{
	createRenderTextures(2);

	m_blurShader = std::make_shared<myEngine::ShaderProgram>("../resources/blur.vert", "../resources/blur.frag");

	m_currentRenderTexIndex = 0;
	m_currentRenderTex = m_workingRenderTextures.at(m_currentRenderTexIndex);

	PostProcess();
}
PostProcess_Blur::~PostProcess_Blur()
{

}

void PostProcess_Blur::apply(std::shared_ptr<myEngine::RenderTexture> _targetTex)
{

	glDisable(GL_DEPTH_TEST);

	draw(_targetTex, m_currentRenderTex, m_blurShader);

	draw(m_currentRenderTex, _targetTex, m_blurShader);
}