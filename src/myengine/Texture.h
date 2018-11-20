#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>

namespace myEngine
{

	class Texture
	{

	private:

	protected:
		glm::ivec2 m_size;
		GLuint m_textureId;

	public:
		Texture();
		Texture(std::string _path);
		void loadTexture(std::string _path);
		glm::ivec2 getSize() { return m_size; }
		virtual GLuint getId() { return m_textureId; }

		void bindTexture();
	};

}

#endif // !TEXTURE_H
