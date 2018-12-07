#include <myengine/myengine.h>

#include <memory>
#include <vector>

class PostProcess_Blur : public myEngine::PostProcess
{

private:

	std::shared_ptr<myEngine::ShaderProgram> m_nullShader;
	std::shared_ptr<myEngine::ShaderProgram> m_lightShader;
	std::shared_ptr<myEngine::ShaderProgram> m_blurShader;
	std::shared_ptr<myEngine::ShaderProgram> m_mergeShader;

	std::shared_ptr<myEngine::RenderTexture> m_tmp1;
	std::shared_ptr<myEngine::RenderTexture> m_tmp2;

	PostProcess_Blur();
public:

	PostProcess_Blur(int _width, int _height);
	~PostProcess_Blur();

	void apply(std::shared_ptr<myEngine::RenderTexture> _targetTex);

};