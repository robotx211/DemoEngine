#include <glm/glm.hpp>
#include <GL/glew.h>
#include <exception>
#include <iostream>
#include <vector>

#include "VertexBuffer.h"

namespace myEngine
{

	class VertexArray
	{

	private:
		GLuint m_id;
		std::vector<VertexBuffer *> m_buffers;
		bool m_dirty;
	
	public:
		VertexArray();
		~VertexArray();

		void addBuffer(std::string _attribute, VertexBuffer *_buffer);

		int getVertexCount() { return m_buffers.at(0)->getVertexCount(); }
		int getId() { return m_id; };
		}
		

	};

}