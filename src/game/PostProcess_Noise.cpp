#include "PostProcess_Noise.h"

#include <glm/glm.hpp>

#include <stdlib.h>
#include <time.h> 

PostProcess_Noise::PostProcess_Noise()
{
	//should never be called
	throw std::exception();
}
PostProcess_Noise::PostProcess_Noise(int _width, int _height)
{
	setRenderTextureSize(_width, _height);

	m_nullShader = std::make_shared<myEngine::ShaderProgram>("../resources/nullpass.vert", "../resources/nullpass.frag");
	m_noiseshader = std::make_shared<myEngine::ShaderProgram>("../resources/noisepass.vert", "../resources/noisepass.frag");

	m_noiseTex = std::make_shared<myEngine::Texture>("../resources/white.png");

	m_tmp1 = std::make_shared<myEngine::RenderTexture>();
	m_tmp1->setSize(m_renderTextureSize);
	m_tmp1->init();

	srand(time(NULL));
}
PostProcess_Noise::~PostProcess_Noise()
{

}

void PostProcess_Noise::apply(std::shared_ptr<myEngine::RenderTexture> _targetTex)
{
	glUseProgram(m_noiseshader->getId());
	m_noiseshader->setUniform("in_Rand", (float)rand());
	glUseProgram(0);

	//draw light from target to tmp1
	draw(_targetTex, m_tmp1, m_noiseshader);

	draw(m_tmp1, _targetTex, m_nullShader);
	return;
}