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

		glm::ivec2 m_size;

	public:
		Texture();
		Texture(std::string _path);
		void loadTexture(std::string _path);
		glm::ivec2 getSize() { return m_size; }
		GLuint getId() { return m_id; }
	};

}

#endif // !TEXTURE_H
