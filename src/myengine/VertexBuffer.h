#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <exception>
#include <iostream>
#include <vector>

namespace myEngine
{

	class VertexBuffer
	{

	private:
		GLuint m_id;
		std::vector<GLfloat> m_data;
		int m_components;
		bool m_dirty;

	public:
		VertexBuffer();

		void addVertex(glm::vec2 _value);
		void addVertex(glm::vec3 _value);
		void addVertex(glm::vec4 _value);

		int getDataSize() { return m_data.size(); }
		GLuint getId() { if (m_dirty == true) { upload(); } return m_id; }
		bool getDirty() { return m_dirty; }
		int getComponents() { if (!m_components) { throw std::exception(); } return m_components; } //vec3 or vec4?

		void upload();

	};

}

#endif // !VERTEX_BUFFER_H