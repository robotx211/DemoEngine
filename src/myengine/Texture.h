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
		GLuint m_id;

		int m_width;
		int m_height;

	public:
		Texture();
		Texture(std::string _path);
		void loadTexture(std::string _path);
		glm::ivec2 getSize() { return glm::ivec2(m_width, m_height); }
		GLuint getId() { return m_id; }
	};

}

#endif // !TEXTURE_H
