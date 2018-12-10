#include <myengine/myengine.h>

#include <memory>
#include <vector>

class PostProcess_Bloom : public myEngine::PostProcess
{

private:

	std::shared_ptr<myEngine::ShaderProgram> m_nullShader;
	std::shared_ptr<myEngine::ShaderProgram> m_lightShader;
	std::shared_ptr<myEngine::ShaderProgram> m_blurShader;
	std::shared_ptr<myEngine::ShaderProgram> m_mergeShader;


	std::shared_ptr<myEngine::RenderTexture> m_cleanCopy;
	std::shared_ptr<myEngine::RenderTexture> m_lightKey;
	std::shared_ptr<myEngine::RenderTexture> m_blur1;
	std::shared_ptr<myEngine::RenderTexture> m_blur2;
	std::shared_ptr<myEngine::RenderTexture> m_merge;

	PostProcess_Bloom();
public:

	PostProcess_Bloom(int _width, int _height);
	~PostProcess_Bloom();

	void apply(std::shared_ptr<myEngine::RenderTexture> _targetTex);

};