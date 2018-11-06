#include "VertexBuffer.h"

namespace myEngine
{

	VertexBuffer::VertexBuffer()
	{

      glGenBuffers(1, &m_id);

		if (!m_id)
		{
			throw std::exception();
		}

        m_components = 0;

        m_dirty = true;

	}

	void VertexBuffer::addVertex(glm::vec2 _value)
	{
		if (m_components != 0 && m_components != 2) //if m_components has been set and is not 2, a non vec2 has already been added
		{
			throw std::exception();
		}

		m_components = 2;

		m_data.push_back(_value.x);
		m_data.push_back(_value.y);

		m_dirty = true;
	}

	void VertexBuffer::addVertex(glm::vec3 _value)
	{
		if (m_components != 0 && m_components != 3) //if m_components has been set and is not 2, a non vec2 has already been added
		{
			throw std::exception();
		}

      m_components = 3;

	  m_data.push_back(_value.x);
	  m_data.push_back(_value.y);
	  m_data.push_back(_value.z);

      m_dirty = true;
	}

    void VertexBuffer::addVertex(glm::vec4 _value)
    {
			if (m_components != 0 && m_components != 4) //if m_components has been set and is not 2, a non vec2 has already been added
			{
				throw std::exception();
			}

      m_components = 4;

      m_data.push_back(_value.x);
      m_data.push_back(_value.y);
      m_data.push_back(_value.z);
      m_data.push_back(_value.w);

      m_dirty = true;
    }

    void VertexBuffer::upload()
    {
      if (m_dirty == false)
      {
        //not dirty, return
        return;
      }

      glBindBuffer(GL_ARRAY_BUFFER, m_id);
      glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * m_data.size(), &m_data.at(0), GL_STATIC_DRAW);
      glBindBuffer(GL_ARRAY_BUFFER, 0);

      m_dirty = false;
    }



}