#include <myengine/myengine.h>

#include <memory>
#include <vector>

class PostProcess_Vignette : public myEngine::PostProcess
{

private:

	std::shared_ptr<myEngine::ShaderProgram> m_nullShader;
	std::shared_ptr<myEngine::ShaderProgram> m_vignetteShader;

	std::shared_ptr<myEngine::Texture> m_vignetteTex;

	std::shared_ptr<myEngine::RenderTexture> m_tmp1;

	PostProcess_Vignette();
public:

	PostProcess_Vignette(int _width, int _height);
	~PostProcess_Vignette();

	void apply(std::shared_ptr<myEngine::RenderTexture> _targetTex);

};