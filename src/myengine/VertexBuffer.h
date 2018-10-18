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
		int m_vertexCount;
		std::vector<GLfloat> m_data;
		int vertexVecSize;
		bool m_dirty;

	public:
		VertexBuffer();
		~VertexBuffer();

		void add(glm::vec3 _value);
		void add(glm::vec4 _value);

		int getVertexCount() { return m_vertexCount; }
		int getDataSize() { return m_data.size(); }
		int getId() { return m_id; }

	};

}