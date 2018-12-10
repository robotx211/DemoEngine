#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <exception>
#include <iostream>
#include <fstream>
#include <string>

#include <memory>
#include <vector>

#include "Texture.h"

namespace myEngine
{

	/**
	*	Stores the ID and Source of a shader
	*/
	struct Shader
	{
		GLuint m_id;
		GLchar *m_source;
	};

	/**
	*	Loads and stores a vertex shader and a fragment shader
	*	Responsible for linking them
	* Sets the Model, View and Projection matrices
	*/
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

		GLuint getId() {
			if (m_dirty == true) { link(); } 
			return m_id;
		}

		bool getDirty() { return m_dirty; }

		void setModelMatrix(glm::mat4 _mat);
		void setViewMatrix(glm::mat4 _mat);
		void setProjectionMatrix(glm::mat4 _mat);

		void setUniform(std::string _uniform, glm::vec4 _value);
		void setUniform(std::string _uniform, float _value);
		void setUniform(std::string _uniform, int _value);
		void setUniform(std::string _uniform, glm::mat4 _value);
	};

}

#endif //!SHADER_PROGRAM_H