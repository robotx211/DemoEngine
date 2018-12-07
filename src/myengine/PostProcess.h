#ifndef POST_PROCESS
#define POST_PROCESS

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <memory>
#include <vector>

#include "Mesh.h"
#include "RenderTexture.h"
#include "ShaderProgram.h"

namespace myEngine
{

	class PostProcess
	{

	private:
		

	protected:
		std::shared_ptr<Mesh> m_screenMesh;
		glm::ivec2 m_renderTextureSize;

		PostProcess();

	public:

		
		PostProcess(int _width, int _height);
		~PostProcess();

		void setRenderTextureSize(int _width, int _height)
		{
			m_renderTextureSize.x = _width;
			m_renderTextureSize.y = _height;
		};

		std::shared_ptr<RenderTexture> createRenderTexture();

		void draw(std::shared_ptr<RenderTexture> _subject, 
							std::shared_ptr<RenderTexture> _target, 
							std::shared_ptr<ShaderProgram> _shader); //subject is what is being drawn, target is what it's beong drawn to

		void draw(std::shared_ptr<RenderTexture> _subject,
							std::shared_ptr<RenderTexture> _subject2,
							std::shared_ptr<RenderTexture> _target,
							std::shared_ptr<ShaderProgram> _shader);


		virtual void apply(std::shared_ptr<RenderTexture> _targetTex); //takes a render texture, and modifys it with a post process
	

	};

}



#endif // !POST_PROCESS
