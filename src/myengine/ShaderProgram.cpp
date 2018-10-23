#include "ShaderProgram.h"

namespace myEngine
{

  ShaderProgram::ShaderProgram()
  {
    //create new shader program
    m_id = glCreateProgram();

    m_dirty = true;
  }

  ShaderProgram::ShaderProgram(std::string _vertShad, std::string _fragShad)
  {
    setVertexShader(_vertShad);

    setFragmentShader(_fragShad);

    //create new shader program
    m_id = glCreateProgram();

    link();
  }

  ShaderProgram::~ShaderProgram()
  {
  }

  void ShaderProgram::setVertexShader(std::string _vertShad)
  {
    //create new vertex shader
    m_vertShad = std::make_shared<Shader>();
    m_vertShad->m_id = glCreateShader(GL_VERTEX_SHADER);

    //attach source code
    m_vertShad->m_source = (GLchar *)_vertShad.c_str();
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
  void ShaderProgram::setFragmentShader(std::string _fragShad)
  {
    //create new fragment shader
    m_fragShad = std::make_shared<Shader>();
    m_fragShad->m_id = glCreateShader(GL_FRAGMENT_SHADER);

    //attach soucre code
    m_fragShad->m_source = (GLchar *)_fragShad.c_str();
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
    glBindAttribLocation(m_id, 1, "in_Colour");

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

}