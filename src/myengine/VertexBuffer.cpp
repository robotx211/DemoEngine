#include "VertexBuffer.h"

namespace myEngine
{

	VertexBuffer::VertexBuffer()
	{

		GLuint newId = 0;

		glGenBuffers(1, &newId);

		if (!newId)
		{
			throw std::exception();
		}

		m_id = newId;

		vertexVecSize = 0;

	}

	void VertexBuffer::add(glm::vec3 _value)
	{
		if (vertexVecSize == 4)
		{
			std::cout << "Already added a vec4" << std::endl;
			throw std::exception();
		}

		vertexVecSize = 3;

		m_data.push_back(_value.x);
		m_data.push_back(_value.y);
		m_data.push_back(_value.z);
	}

	void VertexBuffer::add(glm::vec4 _value)
	{
		if (vertexVecSize == 3)
		{
			std::cout << "Already added a vec3" << std::endl;
			throw std::exception();
		}

		vertexVecSize = 4;

		m_data.push_back(_value.x);
		m_data.push_back(_value.y);
		m_data.push_back(_value.z);
		m_data.push_back(_value.w);
	}



}