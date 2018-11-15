#include "Texture.h"

#include <stb_image/stb_image.h>

namespace myEngine
{
	Texture::Texture()
	{
		m_width = 0;
		m_height = 0;
	}

	Texture::Texture(std::string _path)
	{
		m_width = 0;
		m_height = 0;

		loadTexture(_path);
	}

	void Texture::loadTexture(std::string _path)
	{
		int width = 0;
		int height = 0;
		int channels = 0;

		unsigned char *data = stbi_load(_path.c_str(), &width, &height, &channels, 4);
		//path, width, height, num of channels, desired num of channels
		//does desired channels add an empty alpha if one is not included?

		if (data == false)
		{
			throw std::exception();
		}

		m_width = width;
		m_height = height;

		glGenTextures(1, &m_id);

		if (m_id == false)
		{
			throw std::exception();
		}

		glBindTexture(GL_TEXTURE_2D, m_id);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		free(data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, 0);
	}

}