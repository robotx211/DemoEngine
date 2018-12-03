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

		glm::vec4 VertexBuffer::getMax()
		{

			if (m_components == 0)
			{
				std::cout << "Vertex Buffer Needs Populating Before Range Calculation" << std::endl;
				return glm::vec4(0);
			}

			glm::vec4 max = glm::vec4(-INFINITY);

			//find x range

			for (size_t i = 0; i < m_data.size(); i += m_components)
			{
				if (m_data.at(i) > max.x)
				{
					max.x = m_data.at(i);
				}
			}

			//find y range

			for (size_t i = 1; i < m_data.size(); i += m_components)
			{
				if (m_data.at(i) > max.y)
				{
					max.y = m_data.at(i);
				}
			}

			//find z range (if applicable)

			if (m_components > 2)
			{
				for (size_t i = 2; i < m_data.size(); i += m_components)
				{
					if (m_data.at(i) > max.z)
					{
						max.z = m_data.at(i);
					}
				}
			}
			else
			{
				max.z = 0.0f;
			}

			//find w range (if applicable)

			if (m_components > 3)
			{
				for (size_t i = 3; i < m_data.size(); i += m_components)
				{
					if (m_data.at(i) > max.w)
					{
						max.w = m_data.at(i);
					}
				}
			}
			else
			{
				max.w = 0.0f;
			}

			return max;

		}

		glm::vec4 VertexBuffer::getMin()
		{

			if (m_components == 0)
			{
				std::cout << "Vertex Buffer Needs Populating Before Range Calculation" << std::endl;
				return glm::vec4(0);
			}

			glm::vec4 min = glm::vec4(INFINITY);

			//find x range

			for (size_t i = 0; i < m_data.size(); i += m_components)
			{
				if (m_data.at(i) < min.x)
				{
					min.x = m_data.at(i);
				}
			}

			//find y range

			for (size_t i = 1; i < m_data.size(); i += m_components)
			{
				if (m_data.at(i) < min.y)
				{
					min.y = m_data.at(i);
				}
			}

			//find z range (if applicable)

			if (m_components > 2)
			{
				for (size_t i = 2; i < m_data.size(); i += m_components)
				{
					if (m_data.at(i) < min.z)
					{
						min.z = m_data.at(i);
					}
				}
			}
			else
			{
				min.z = 0.0f;
			}

			//find w range (if applicable)

			if (m_components > 3)
			{
				for (size_t i = 3; i < m_data.size(); i += m_components)
				{
					if (m_data.at(i) < min.w)
					{
						min.w = m_data.at(i);
					}
				}
			}
			else
			{
				min.w = 0.0f;
			}

			return min;

		}

		void VertexBuffer::offset(glm::vec4 _offset)
		{
			if (m_components == 0)
			{
				std::cout << "Vertex Buffer Needs Populating Before Offsetting" << std::endl;
			}

			//find x range

			for (size_t i = 0; i < m_data.size(); i += m_components)
			{
				m_data.at(i) += _offset.x;
			}

			//find y range

			for (size_t i = 1; i < m_data.size(); i += m_components)
			{
				m_data.at(i) += _offset.y;
			}

			//find z range (if applicable)

			if (m_components > 2)
			{
				for (size_t i = 2; i < m_data.size(); i += m_components)
				{
					m_data.at(i) += _offset.z;
				}
			}

			//find w range (if applicable)

			if (m_components > 3)
			{
				for (size_t i = 3; i < m_data.size(); i += m_components)
				{
					m_data.at(i) += _offset.w;
				}
			}
		}


}