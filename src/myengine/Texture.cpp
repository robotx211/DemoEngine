#include "Texture.h"

#include <stb_image/stb_image.h>

namespace myEngine
{
	Texture::Texture()
	{
		m_size = glm::ivec2(0);
	}

	Texture::Texture(std::string _path)
	{
		m_size = glm::ivec2(0);

		loadTexture(_path);
	}

	void Texture::loadTexture(std::string _path)
	{
		int width = 0;
		int height = 0;
		int channels = 0;

		stbi_set_flip_vertically_on_load(true);

		unsigned char *data = stbi_load(_path.c_str(), &width, &height, &channels, 4);
		//path, width, height, num of channels, desired num of channels
		//does desired channels add an empty alpha if one is not included?

		if (data == false)
		{
			throw std::exception();
		}

		m_size.x = width;
		m_size.y = height;

		glGenTextures(1, &m_textureId);

		if (m_textureId == false)
		{
			throw std::exception();
		}

		glBindTexture(GL_TEXTURE_2D, m_textureId);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

		free(data);

		glGenerateMipmap(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void Texture::bindTexture()
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, m_textureId);
	}

}