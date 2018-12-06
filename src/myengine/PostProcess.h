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

	protected:
		std::vector<std::shared_ptr<RenderTexture>> m_workingRenderTextures; //render textures created for and used during post processing
		std::shared_ptr<Mesh> m_screenMesh;

	public:

		PostProcess();
		~PostProcess();

		void createRenderTextures(int _amount);

		void draw(std::shared_ptr<RenderTexture> _subject, 
							std::shared_ptr<RenderTexture> _target, 
							std::shared_ptr<ShaderProgram> _shader); //subject is what is being drawn, target is what it's beong drawn to

		virtual void apply(std::shared_ptr<RenderTexture> _targetTex); //takes a render texture, and modifys it with a post process


	};

}



#endif // !POST_PROCESS
