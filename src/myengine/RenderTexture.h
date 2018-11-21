#ifndef RENDER_TEXTURE_H
#define RENDER_TEXTURE_H

#include "Texture.h"

namespace myEngine
{

	class RenderTexture : public Texture
	{

	private:

		GLuint m_frameBufferId;
		GLuint m_renderBufferId;

	public:

		RenderTexture();
		RenderTexture(int _width, int _height);
		RenderTexture(glm::ivec2 _size);
		~RenderTexture();

		void init();

		void setSize(int _width, int _height);
		void setSize(glm::ivec2 _size);

		GLuint getId() { return m_textureId; }

		void bindFrameBuffer();
	};

}

#endif // !RENDER_TEXTURE_H
