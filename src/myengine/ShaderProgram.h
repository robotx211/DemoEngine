#include <glm/glm.hpp>
#include <GL/glew.h>
#include <exception>
#include <iostream>

namespace myEngine
{

	//stores shaders
	class ShaderProgram
	{

	private:
		GLuint m_id;
		GLchar *m_vertShad;
		GLchar *m_fragShad;

	public:
		ShaderProgram(std::string _vertShad, std::string _fragShad);
		~ShaderProgram();

		GLuint getId() { return m_id; }


	};

}