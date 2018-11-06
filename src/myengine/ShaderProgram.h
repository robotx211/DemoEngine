#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <exception>
#include <iostream>
#include <fstream>
#include <string>

#include "enums.h"

namespace myEngine
{

	struct Shader
	{
		GLuint m_id;
		GLchar *m_source;
	};

	//stores shaders
	class ShaderProgram
	{

	private:
		GLuint m_id;

		std::shared_ptr<Shader> m_vertShad;
		std::shared_ptr<Shader> m_fragShad;

		bool m_dirty;

	public:
		ShaderProgram();
		ShaderProgram(std::string _vertShadAddress, std::string _fragShadAddress);
		~ShaderProgram();

		void setVertexShader(std::string _vertShadAddress);
		void setFragmentShader(std::string _fragShadAddress);
		void link();

		GLuint getId() { return m_id; }

		bool getDirty() { return m_dirty; }




	};

}

#endif //!SHADER_PROGRAM_H