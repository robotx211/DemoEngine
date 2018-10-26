#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <exception>
#include <iostream>
#include <vector>

#include "enums.h"
#include "VertexBuffer.h"

namespace myEngine
{

	class VertexArray
	{

	private:
		GLuint m_id;
		std::vector<std::shared_ptr<VertexBuffer>> m_buffers;
		bool m_dirty;
	
	public:
		VertexArray();

		void addBuffer(enums::ShaderAttribute _attribute, std::weak_ptr<VertexBuffer> _buffer);

        GLuint getId() { if (m_dirty == true) { upload(); } return m_id; }

        void upload();

        bool getDirty() { return m_dirty; }
		

	};

}

#endif // !VERTEX_ARRAY_H