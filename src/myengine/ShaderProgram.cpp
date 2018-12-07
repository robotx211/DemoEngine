#include <glm/ext.hpp>

#include "ShaderProgram.h"
#include "enums.h"

namespace myEngine
{

	ShaderProgram::ShaderProgram()
	{
		//create new shader program
		m_id = glCreateProgram();

		m_dirty = true;
	}

	ShaderProgram::ShaderProgram(std::string _vertShadAddress, std::string _fragShadAddress)
	{
		setVertexShader(_vertShadAddress);

		setFragmentShader(_fragShadAddress);

		//create new shader program
		m_id = glCreateProgram();

		link();
	}

	ShaderProgram::~ShaderProgram()
	{
	}

	void ShaderProgram::setVertexShader(std::string _vertShadAddress)
	{
		//create new vertex shader
		m_vertShad = std::make_shared<Shader>();
		m_vertShad->m_id = glCreateShader(GL_VERTEX_SHADER);

		//get source code from file
		std::ifstream shaderFilestream(_vertShadAddress);
		std::string sourceString(
			(std::istreambuf_iterator<char>(shaderFilestream)),
			(std::istreambuf_iterator<char>())
		);

		//attach source code
		m_vertShad->m_source = (GLchar *)sourceString.c_str();
		glShaderSource(m_vertShad->m_id, 1, &m_vertShad->m_source, NULL);

		//compile it
		glCompileShader(m_vertShad->m_id);
		//check for errors
		GLint success = 0;
		glGetShaderiv(m_vertShad->m_id, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			//vert shader did not compile
			throw std::exception();
		}

		m_dirty = true;
	}
	void ShaderProgram::setFragmentShader(std::string _fragShadAddress)
	{
		//create new fragment shader
		m_fragShad = std::make_shared<Shader>();
		m_fragShad->m_id = glCreateShader(GL_FRAGMENT_SHADER);

//get source code from file
		std::ifstream shaderFilestream(_fragShadAddress);
		std::string sourceString(
			(std::istreambuf_iterator<char>(shaderFilestream)),
			(std::istreambuf_iterator<char>())
		);

		//attach source code
		m_fragShad->m_source = (GLchar *)sourceString.c_str();
		glShaderSource(m_fragShad->m_id, 1, &m_fragShad->m_source, NULL);

		//compile it
		glCompileShader(m_fragShad->m_id);
		GLint success = 0;
		glGetShaderiv(m_fragShad->m_id, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			throw std::exception();
		}

		m_dirty = true;
	}
	void ShaderProgram::link()
	{
		if (m_dirty == false)
		{
			//not dirty, return
			return;
		}

		//attach shader objects
		glAttachShader(m_id, m_vertShad->m_id);
		glAttachShader(m_id, m_fragShad->m_id);

		//ensure VAO "position" attrib stream gets set as the first position during link
		glBindAttribLocation(m_id, 0, "in_Position");
		glBindAttribLocation(m_id, 1, "in_TexCoord");
		//glBindAttribLocation(m_id, 2, "in_Normal");

		//perform the link
		glLinkProgram(m_id);
		//check for failure
		GLint success = 0;
		glGetProgramiv(m_id, GL_LINK_STATUS, &success);
		if (!success)
		{
			throw std::exception();
		}

		//detach and destroy shader objects, only the shader program is now needed
		glDetachShader(m_id, m_vertShad->m_id);
		glDeleteShader(m_vertShad->m_id);

		glDetachShader(m_id, m_fragShad->m_id);
		glDeleteShader(m_fragShad->m_id);

		m_dirty = false;
	}

	void ShaderProgram::setModelMatrix(glm::mat4 _mat)
	{
		GLuint modelMatId = glGetUniformLocation(m_id, "in_ModelMat");

		if (modelMatId == -1)
		{
			throw std::exception();
		}

		glUseProgram(m_id);
		glUniformMatrix4fv(modelMatId, 1, GL_FALSE, glm::value_ptr(_mat));
		glUseProgram(0);
	}
	void ShaderProgram::setViewMatrix(glm::mat4 _mat)
	{
		GLuint viewMatId = glGetUniformLocation(m_id, "in_ViewMat");

		if (viewMatId == -1)
		{
			throw std::exception();
		}

		glUseProgram(m_id);
		glUniformMatrix4fv(viewMatId, 1, GL_FALSE, glm::value_ptr(_mat));
		glUseProgram(0);
	}
	void ShaderProgram::setProjectionMatrix(glm::mat4 _mat)
	{
		GLuint projMatId = glGetUniformLocation(m_id, "in_ProjMat");

		if (projMatId == -1)
		{
			throw std::exception();
		}

		glUseProgram(m_id);
		glUniformMatrix4fv(projMatId, 1, GL_FALSE, glm::value_ptr(_mat));
		glUseProgram(0);
	}

	//----------------------------------generic uniform setting-------------------------------

	void ShaderProgram::setUniform(std::string _uniform, glm::vec4 _value)
	{
		GLint uniformId = glGetUniformLocation(m_id, _uniform.c_str());

		if (uniformId == -1)
		{
			throw std::exception();
		}

		glUseProgram(m_id);
		glUniform4f(uniformId, _value.x, _value.y, _value.z, _value.w);
		glUseProgram(0);
	}

	void ShaderProgram::setUniform(std::string _uniform, float _value)
	{
		GLint uniformId = glGetUniformLocation(m_id, _uniform.c_str());

		if (uniformId == -1)
		{
			throw std::exception();
		}

		glUseProgram(m_id);
		glUniform1f(uniformId, _value);
		glUseProgram(0);
	}

	void ShaderProgram::setUniform(std::string _uniform, int _value)
	{
		GLint uniformId = glGetUniformLocation(m_id, _uniform.c_str());

		if (uniformId == -1)
		{
			throw std::exception();
		}

		glUseProgram(m_id);
		glUniform1i(uniformId, _value);
		glUseProgram(0);
	}

	void ShaderProgram::setUniform(std::string _uniform, glm::mat4 _value)
	{
		GLint uniformId = glGetUniformLocation(m_id, _uniform.c_str());

		if (uniformId == -1)
		{
			throw std::exception();
		}

		glUseProgram(m_id);
		glUniformMatrix4fv(uniformId, 1, GL_FALSE, glm::value_ptr(_value));
		glUseProgram(0);
	}

}