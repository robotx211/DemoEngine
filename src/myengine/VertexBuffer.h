#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <exception>
#include <iostream>
#include <vector>

namespace myEngine
{

	/**
	*	Stores per vertex data (Position, TexCoord, Normal etc.), can either be store vec2s, vec3s or vec4s
	*	Responsible for uploading the data into a VertexBufferObject
	*/
	class VertexBuffer
	{

	private:
		GLuint m_id;
		std::vector<GLfloat> m_data;
		int m_components;
		bool m_dirty;

	public:
		VertexBuffer();

		void addVertex(glm::vec2 _value); ///< Once a vec3 or vec4 has been added, will throw an exception
		void addVertex(glm::vec3 _value); ///< Once a vec2 or vec4 has been added, will throw an exception
		void addVertex(glm::vec4 _value); ///< Once a vec2 or vec3 has been added, will throw an exception

		int getDataSize() { return m_data.size(); }
		GLuint getId() { if (m_dirty == true) { upload(); } return m_id; }
		bool getDirty() { return m_dirty; }
		int getComponents() { if (!m_components) { throw std::exception(); } return m_components; } //vec3 or vec4?

		void upload();

		//mostly used just for vertex position buffer
		glm::vec4 getMax();
		glm::vec4 getMin();
		glm::vec4 getRange() { return getMax() - getMin(); };

		void offset(glm::vec4 _offset);

	};

}

#endif // !VERTEX_BUFFER_H