#include <myengine/myengine.h>

#include <memory>
#include <vector>

class PostProcess_Blur : public myEngine::PostProcess
{

private:

	std::shared_ptr<myEngine::ShaderProgram> m_blurShader;

	int m_currentRenderTexIndex;
	std::shared_ptr<myEngine::RenderTexture> m_currentRenderTex;

public:

	PostProcess_Blur();
	~PostProcess_Blur();

	void apply(std::shared_ptr<myEngine::RenderTexture> _targetTex);

};