#include "VertexArray.h"

namespace myEngine
{

	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &m_id);

		if (!m_id)
		{
			throw std::exception();
		}

		m_buffers.resize(10);

		m_dirty = true;
	}

	void VertexArray::addBuffer(enums::ShaderAttribute _attribute, std::weak_ptr<VertexBuffer> _buffer)
	{
		/*
		  Attribute       Position

		  in_Position     0
				  in_TexCoord			1
				  in_Normal				2

		*/

		switch (_attribute)
		{
		case enums::ShaderAttribute::in_Position:
			m_buffers.at(0) = _buffer.lock();
			break;
		case enums::ShaderAttribute::in_TexCoord:
			m_buffers.at(1) = _buffer.lock();
			break;
		case enums::ShaderAttribute::in_Normal:
			m_buffers.at(2) = _buffer.lock();
			break;
		}

		m_dirty = true;
	}

	void VertexArray::upload()
	{
		if (m_dirty == false)
		{
			//not dirty, return
			return;
		}

		glBindVertexArray(m_id);

		for (size_t i = 0; i < m_buffers.size(); i++)
		{
			if (m_buffers.at(i)) //if the buffer exists
			{
				glBindBuffer(GL_ARRAY_BUFFER, m_buffers.at(i)->getId());

				std::shared_ptr<VertexBuffer> currentBuffer = m_buffers.at(i);

				glVertexAttribPointer(i, currentBuffer->getComponents(), GL_FLOAT, GL_FALSE, currentBuffer->getComponents() * sizeof(GLfloat), (void *)0);
				glEnableVertexAttribArray(i);
			}
			else
			{
				glDisableVertexAttribArray(i);
			}
		}

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		m_dirty = false;
	}


}