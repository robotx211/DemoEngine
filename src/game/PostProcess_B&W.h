#include <myengine/myengine.h>

#include <memory>
#include <vector>

class PostProcess_BandW : public myEngine::PostProcess
{

private:

	std::shared_ptr<myEngine::ShaderProgram> m_nullShader;
	std::shared_ptr<myEngine::ShaderProgram> m_BandWShader;

	std::shared_ptr<myEngine::RenderTexture> m_tmp1;

	PostProcess_BandW();
public:

	PostProcess_BandW(int _width, int _height);
	~PostProcess_BandW();

	void apply(std::shared_ptr<myEngine::RenderTexture> _targetTex);

};