#include <myengine/myengine.h>

#include <memory>
#include <vector>

class PostProcess_Noise : public myEngine::PostProcess
{

private:

	std::shared_ptr<myEngine::ShaderProgram> m_nullShader;
	std::shared_ptr<myEngine::ShaderProgram> m_noiseshader;

	std::shared_ptr<myEngine::RenderTexture> m_tmp1;

	PostProcess_Noise();
public:

	PostProcess_Noise(int _width, int _height);
	~PostProcess_Noise();

	void apply(std::shared_ptr<myEngine::RenderTexture> _targetTex);

};