#include "PostProcess_Bloom.h"

#include <glm/glm.hpp>

PostProcess_Bloom::PostProcess_Bloom()
{
	//should never be called
	throw std::exception();
}
PostProcess_Bloom::PostProcess_Bloom(int _width, int _height)
{
	setRenderTextureSize(_width, _height);

	m_nullShader = std::make_shared<myEngine::ShaderProgram>("../resources/nullpass.vert", "../resources/nullpass.frag");
	m_lightShader = std::make_shared<myEngine::ShaderProgram>("../resources/lightkeypass.vert", "../resources/lightkeypass.frag");
	m_blurShader = std::make_shared<myEngine::ShaderProgram>("../resources/blur.vert", "../resources/blur.frag");
	m_mergeShader = std::make_shared<myEngine::ShaderProgram>("../resources/mergepass.vert", "../resources/mergepass.frag");

	m_cleanCopy = std::make_shared<myEngine::RenderTexture>();
	m_cleanCopy->setSize(m_renderTextureSize);
	m_cleanCopy->init();

	m_lightKey = std::make_shared<myEngine::RenderTexture>();
	m_lightKey->setSize(m_renderTextureSize);
	m_lightKey->init();

	m_blur1 = std::make_shared<myEngine::RenderTexture>();
	m_blur1->setSize(m_renderTextureSize);
	m_blur1->init();

	m_blur2 = std::make_shared<myEngine::RenderTexture>();
	m_blur2->setSize(m_renderTextureSize);
	m_blur2->init();

	m_merge = std::make_shared<myEngine::RenderTexture>();
	m_merge->setSize(m_renderTextureSize);
	m_merge->init();
}
PostProcess_Bloom::~PostProcess_Bloom()
{

}

void PostProcess_Bloom::apply(std::shared_ptr<myEngine::RenderTexture> _targetTex)
{
	draw(_targetTex, m_cleanCopy, m_nullShader);

	//draws the light fragments from the screen to m_lightKey (produces the light key)
	draw(_targetTex, m_lightKey, m_lightShader);

	//blurs the light key between tmp1 and tmp2, 8 times in total
	draw(m_lightKey, m_blur1, m_blurShader);
	draw(m_blur1, m_blur2, m_blurShader);
	draw(m_blur2, m_blur1, m_blurShader);
	draw(m_blur1, m_blur2, m_blurShader);
	draw(m_blur2, m_blur1, m_blurShader);
	draw(m_blur1, m_blur2, m_blurShader);
	draw(m_blur2, m_blur1, m_blurShader);
	draw(m_blur1, m_blur2, m_blurShader);

	//merges the copy of the screen texture with the blurred light key to apply bloom
	draw(m_cleanCopy, m_blur2, m_merge, m_mergeShader);

	//draws the bloomed scene to the target render texture
	draw(m_merge, _targetTex, m_nullShader);

	return;
}