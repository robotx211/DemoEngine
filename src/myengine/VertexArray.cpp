#include "VertexArray.h"

namespace myEngine
{

	VertexArray::VertexArray()
	{
		GLuint newId = 0;

		glGenVertexArrays(1, &newId);

		if (!newId)
		{
			throw std::exception();
		}

		m_id = newId;
	}

	void VertexArray::addBuffer(std::string _attribute, VertexBuffer *_buffer)
	{

	}

}