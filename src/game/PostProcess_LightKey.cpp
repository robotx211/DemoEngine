#include "PostProcess_LightKey.h"

#include <glm/glm.hpp>

PostProcess_LightKey::PostProcess_LightKey()
{
	//should never be called
	throw std::exception();
}
PostProcess_LightKey::PostProcess_LightKey(int _width, int _height)
{
	setRenderTextureSize(_width, _height);

	m_nullShader = std::make_shared<myEngine::ShaderProgram>("../resources/nullpass.vert", "../resources/nullpass.frag");
	m_lightShader = std::make_shared<myEngine::ShaderProgram>("../resources/lightkeypass.vert", "../resources/lightkeypass.frag");

	m_tmp1 = std::make_shared<myEngine::RenderTexture>();
	m_tmp1->setSize(m_renderTextureSize);
	m_tmp1->init();
}
PostProcess_LightKey::~PostProcess_LightKey()
{

}

void PostProcess_LightKey::apply(std::shared_ptr<myEngine::RenderTexture> _targetTex)
{
	//draws the light fragments from the screen to tmp1 (produces the light key)
	draw(_targetTex, m_tmp1, m_lightShader);

	//draws the light key to the target render texture
	draw(m_tmp1, _targetTex, m_nullShader);
	return;
}