#include "PostProcess_Blur.h"

#include <glm/glm.hpp>

PostProcess_Blur::PostProcess_Blur()
{
	//should never be called
	throw std::exception();
}
PostProcess_Blur::PostProcess_Blur(int _width, int _height)
{
	setRenderTextureSize(_width, _height);

	m_nullShader = std::make_shared<myEngine::ShaderProgram>("../resources/nullpass.vert", "../resources/nullpass.frag");
	m_lightShader = std::make_shared<myEngine::ShaderProgram>("../resources/lightkeypass.vert", "../resources/lightkeypass.frag");
	m_blurShader = std::make_shared<myEngine::ShaderProgram>("../resources/blur.vert", "../resources/blur.frag");

	m_tmp1 = std::make_shared<myEngine::RenderTexture>();
	m_tmp1->setSize(m_renderTextureSize);
	m_tmp1->init();

	m_tmp2 = std::make_shared<myEngine::RenderTexture>();
	m_tmp2->setSize(m_renderTextureSize);
	m_tmp2->init();
}
PostProcess_Blur::~PostProcess_Blur()
{

}

void PostProcess_Blur::apply(std::shared_ptr<myEngine::RenderTexture> _targetTex)
{
	//draws the light fragments from the screen to tmp1 (produces the light key)
	draw(_targetTex, m_tmp1, m_lightShader);

	//blurs the light key between tmp1 and tmp2, 8 times in total
	draw(m_tmp1, m_tmp2, m_blurShader);
	draw(m_tmp2, m_tmp1, m_blurShader);
	draw(m_tmp1, m_tmp2, m_blurShader);
	draw(m_tmp2, m_tmp1, m_blurShader);
	draw(m_tmp1, m_tmp2, m_blurShader);
	draw(m_tmp2, m_tmp1, m_blurShader);
	draw(m_tmp1, m_tmp2, m_blurShader);
	draw(m_tmp2, m_tmp1, m_blurShader);

	//draws the blurred light key to the target render texture
	draw(m_tmp1, _targetTex, m_nullShader);
	return;

}