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
	/**
	* Post Process base class.
	* Post Processes are not individually part of the engine, ie they can be created by the user.
	* This base class is used to draw textures to other render textures using specified shaders.
	*/
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

		/**
		* Renders the _subject texture onto the _target render texture using the _shader shader
		* Allows the use of regular textures as well as render textures to be subjects
		*/
		void draw(std::shared_ptr<Texture> _subject,
							std::shared_ptr<RenderTexture> _target, 
							std::shared_ptr<ShaderProgram> _shader); //subject is what is being drawn, target is what it's being drawn to

		/**
		* Renders the _subject and _subject2 textures onto the _target render texture using the _shader shader
		* Used for Post-Processing effects which require 2 input textures, such as merging, where the fragment colours of the 2 textures are combined
		*/
		void draw(std::shared_ptr<Texture> _subject,
							std::shared_ptr<Texture> _subject2,
							std::shared_ptr<RenderTexture> _target,
							std::shared_ptr<ShaderProgram> _shader);

		/// The virtual function for post-processing effects, which are applied to the _targetTex
		virtual void apply(std::shared_ptr<RenderTexture> _targetTex); 
	

	};

}



#endif // !POST_PROCESS
