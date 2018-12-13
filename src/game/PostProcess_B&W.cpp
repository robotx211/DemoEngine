#include "PostProcess_B&W.h"

#include <glm/glm.hpp>

PostProcess_BandW::PostProcess_BandW()
{
	//should never be called
	throw std::exception();
}
PostProcess_BandW::PostProcess_BandW(int _width, int _height)
{
	setRenderTextureSize(_width, _height);

	m_nullShader = std::make_shared<myEngine::ShaderProgram>("../resources/nullpass.vert", "../resources/nullpass.frag");
	m_BandWShader = std::make_shared<myEngine::ShaderProgram>("../resources/nullpass.vert", "../resources/textured_B&W.frag");
  
	m_tmp1 = std::make_shared<myEngine::RenderTexture>();
	m_tmp1->setSize(m_renderTextureSize);
	m_tmp1->init();
}
PostProcess_BandW::~PostProcess_BandW()
{

}

void PostProcess_BandW::apply(std::shared_ptr<myEngine::RenderTexture> _targetTex)
{
	//draws the target texture to tmp1, averaging out the colour into a greyscale image
	draw(_targetTex, m_tmp1, m_BandWShader);

	draw(m_tmp1, _targetTex, m_nullShader);
	return;
}