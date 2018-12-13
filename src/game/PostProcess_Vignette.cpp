#include "PostProcess_Vignette.h"

#include <glm/glm.hpp>

PostProcess_Vignette::PostProcess_Vignette()
{
	//should never be called
	throw std::exception();
}
PostProcess_Vignette::PostProcess_Vignette(int _width, int _height)
{
	setRenderTextureSize(_width, _height);

	m_nullShader = std::make_shared<myEngine::ShaderProgram>("../resources/nullpass.vert", "../resources/nullpass.frag");
	m_vignetteShader = std::make_shared<myEngine::ShaderProgram>("../resources/vignettepass.vert", "../resources/vignettepass.frag");

	m_vignetteTex = std::make_shared<myEngine::Texture>("../resources/Vignette.png");

	m_tmp1 = std::make_shared<myEngine::RenderTexture>();
	m_tmp1->setSize(m_renderTextureSize);
	m_tmp1->init();
}
PostProcess_Vignette::~PostProcess_Vignette()
{

}

void PostProcess_Vignette::apply(std::shared_ptr<myEngine::RenderTexture> _targetTex)
{
	
	//multiplies the screen fragment colour by the vingette fragment colour
	draw(_targetTex, m_vignetteTex, m_tmp1, m_vignetteShader);

	draw(m_tmp1, _targetTex, m_nullShader);
	return;
}