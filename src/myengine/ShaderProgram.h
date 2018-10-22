#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <exception>
#include <iostream>

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

  public:
    ShaderProgram();
	ShaderProgram(std::string _vertShad, std::string _fragShad);
	~ShaderProgram();

    void attachVertexShader(std::string _vertShad);
    void attachFragmentShader(std::string _fragShad);
    void link();

	GLuint getId() { return m_id; }




  };

}

#endif //!SHADER_PROGRAM_H