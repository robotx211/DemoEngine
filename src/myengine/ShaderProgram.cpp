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
		std::cout << sourceString << std::endl;

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
		std::cout << sourceString << std::endl;

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
		//glBindAttribLocation(m_id, 1, "in_TexCoord");
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
		m_modelMat = _mat;

		GLuint id = glGetUniformLocation(m_id, "in_ModelMat");

		if (id == -1)
		{
			throw std::exception();
		}

		glUseProgram(m_id);
		glUniformMatrix4fv(id, 1, GL_FALSE, glm::value_ptr(_mat));
		glUseProgram(0);
	}
	void ShaderProgram::setViewMatrix(glm::mat4 _mat)
	{
		m_viewMat = _mat;

		GLuint id = glGetUniformLocation(m_id, "in_ViewMat");

		if (id == -1)
		{
			throw std::exception();
		}

		glUseProgram(m_id);
		glUniformMatrix4fv(id, 1, GL_FALSE, glm::value_ptr(_mat));
		glUseProgram(0);
	}
	void ShaderProgram::setProjectionMatrix(glm::mat4 _mat)
	{
		m_projMat = _mat;

		GLuint id = glGetUniformLocation(m_id, "in_ProjMat");

		if (id == -1)
		{
			throw std::exception();
		}

		glUseProgram(m_id);
		glUniformMatrix4fv(id, 1, GL_FALSE, glm::value_ptr(_mat));
		glUseProgram(0);
	}

	void ShaderProgram::setTexture(std::shared_ptr<Texture> _texture)
	{
		GLuint id = glGetUniformLocation(m_id, "in_Texture");

		if (id == -1)
		{
			throw std::exception();
		}

		Sampler sampler;
		sampler.m_id = id;
		sampler.m_source = _texture;

		m_texture = sampler;

		glUseProgram(m_id);
		glUniform1i(id, 0);
		glUseProgram(0);
	}

}