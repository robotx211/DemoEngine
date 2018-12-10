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
	std::cout << "RenderTex, id: 2, Name: CleanCopy" << std::endl;

	m_lightKey = std::make_shared<myEngine::RenderTexture>();
	m_lightKey->setSize(m_renderTextureSize);
	m_lightKey->init();
	std::cout << "RenderTex, id: 3, Name: LightKey" << std::endl;

	m_blur1 = std::make_shared<myEngine::RenderTexture>();
	m_blur1->setSize(m_renderTextureSize);
	m_blur1->init();
	std::cout << "RenderTex, id: 4, Name: Blur1" << std::endl;

	m_blur2 = std::make_shared<myEngine::RenderTexture>();
	m_blur2->setSize(m_renderTextureSize);
	m_blur2->init();
	std::cout << "RenderTex, id: 5, Name: Blur2" << std::endl;

	m_merge = std::make_shared<myEngine::RenderTexture>();
	m_merge->setSize(m_renderTextureSize);
	m_merge->init();
	std::cout << "RenderTex, id: 6, Name: Merge" << std::endl;
}
PostProcess_Bloom::~PostProcess_Bloom()
{

}

void PostProcess_Bloom::apply(std::shared_ptr<myEngine::RenderTexture> _targetTex)
{
	draw(_targetTex, m_cleanCopy, m_nullShader);

	//draw light from target to tmp1
	draw(_targetTex, m_lightKey, m_lightShader);

	//draw blur from tmp1 to tmp2
	draw(m_lightKey, m_blur1, m_blurShader);
	//draw blur from tmp2 to tmp1
	draw(m_blur1, m_blur2, m_blurShader);
	//draw blur from tmp1 to tmp2
	draw(m_blur2, m_blur1, m_blurShader);
	//draw blur from tmp2 to tmp1
	draw(m_blur1, m_blur2, m_blurShader);
	//draw blur from tmp1 to tmp2
	draw(m_blur2, m_blur1, m_blurShader);
	//draw blur from tmp2 to tmp1
	draw(m_blur1, m_blur2, m_blurShader);
	//draw blur from tmp1 to tmp2
	draw(m_blur2, m_blur1, m_blurShader);
	//draw blur from tmp2 to tmp1
	draw(m_blur1, m_blur2, m_blurShader);

	//draw merge from tmp1 and target to tmp 2
	draw(m_cleanCopy, m_blur2, m_merge, m_mergeShader); //Scene -> TexB, Light -> TexA, draws bright scene, no blur
	//draw(m_tmp1, _targetTex, m_tmp2, m_mergeShader); //Scene -> TexA, Light -> TexB, draws white blue

	//draw null from tmp2 to target 
	draw(m_merge, _targetTex, m_nullShader);
	return;
}