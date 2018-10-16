#include "GL_Triangle.h"

namespace myEngine
{

  void GL_Triangle::draw(std::shared_ptr<Window> _windowObject)
  {
    SDL_Window *window = _windowObject->getWindow();

    const GLfloat m_positions[] = {
      0.0f, 0.5f, 0.0f,
      -0.5f, -0.5f, 0.0f,
      0.5f, -0.5f, 0.0f
    };

    const GLchar *m_vertexShaderSrc =
      "attribute vec3 in_Position;            " \
      "                                       " \
      "void main()                            " \
      "{                                      " \
      " gl_Position = vec4(in_Position, 1.0); " \
      "}                                      ";

    const GLchar *m_fragmentShaderSrc =
      "void main()                        " \
      "{                                  " \
      " gl_FragColor = vec4(0, 0, 1, 1);  " \
      "}                                  ";

    //create SDL GL Context
    if (!SDL_GL_CreateContext(window))
    {
      std::cout << "GLContext is null" << std::endl;
      throw std::exception();
    }

    //init glew
    if (glewInit() != GLEW_OK)
    {
      std::cout << "glewInit failed" << std::endl;
      throw std::exception();
    }

    //set clear colour of _window
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapWindow(window);

    // - - - - - - - - - - - - - - - - - - - - - Create VBO - - - - - - - - - - - - - - - - - - - - - //

    //create VBO with ID 1
    GLuint VboId = 0;
    glGenBuffers(1, &VboId);
    if (!VboId)
    {
      throw std::exception();
    }

    //bind VBO
    glBindBuffer(GL_ARRAY_BUFFER, VboId);

    //upload copy of VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(m_positions), m_positions, GL_STATIC_DRAW);

    //reset state
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // - - - - - - - - - - - - - - - - - - - - - Create VAO - - - - - - - - - - - - - - - - - - - - - //

    //create VAO with ID 1
    GLuint VaoId = 0;
    glGenVertexArrays(1, &VaoId);
    if (!VaoId)
    {
      throw std::exception();
    }

    //bind VAO
    glBindVertexArray(VaoId);

    //bind the VBO
    glBindBuffer(GL_ARRAY_BUFFER, VboId);
    //assign it to position 0 in the bound VBO
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (void *)0);
    //enable the VBO at position 0
    glEnableVertexAttribArray(0);

    //reset the state
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // - - - - - - - - - - - - - - - - - - - - - Load Vertex Shader - - - - - - - - - - - - - - - - - - - - - //

    //create new vertex shader
    GLuint vertShaderId = glCreateShader(GL_VERTEX_SHADER);
    //attach source code
    glShaderSource(vertShaderId, 1, &m_vertexShaderSrc, NULL);
    //compile it
    glCompileShader(vertShaderId);
    //check for errors
    GLint success = 0;
    glGetShaderiv(vertShaderId, GL_COMPILE_STATUS, &success);
    if (!success)
    {
      throw std::exception();
    }

    // - - - - - - - - - - - - - - - - - - - - - Load Fragment Shader - - - - - - - - - - - - - - - - - - - - - //

    //create new fragment shader
    GLuint fragShaderId = glCreateShader(GL_FRAGMENT_SHADER);
    //attach soucre code
    glShaderSource(fragShaderId, 1, &m_fragmentShaderSrc, NULL);
    //compile it
    glCompileShader(fragShaderId);
    success = 0;
    glGetShaderiv(fragShaderId, GL_COMPILE_STATUS, &success);
    if (!success)
    {
      throw std::exception();
    }

    // - - - - - - - - - - - - - - - - - - - - - Create Shader Program - - - - - - - - - - - - - - - - - - - - - //

    //create new shader program
    GLuint programId = glCreateProgram();
    //attach shader objects
    glAttachShader(programId, vertShaderId);
    glAttachShader(programId, fragShaderId);

    //ensure VAO "position" attrib stream gets set as the first position during link
    glBindAttribLocation(programId, 0, "in_Position");
    //would set any other attrib stream positions here

    //perform the link
    glLinkProgram(programId);
    //check for failure
    success = 0;
    glGetProgramiv(programId, GL_LINK_STATUS, &success);
    if (!success)
    {
      throw std::exception();
    }

    //detach and destroy shader objects, only the shader program is now needed
    glDetachShader(programId, vertShaderId);
    glDeleteShader(vertShaderId);
    
    glDetachShader(programId, fragShaderId);
    glDeleteShader(fragShaderId);

    // - - - - - - - - - - - - - - - - - - - - - Draw Triangle - - - - - - - - - - - - - - - - - - - - - //

    //tell OpenGL which shader program to use
    glUseProgram(programId);
    //bind the VAO
    glBindVertexArray(VaoId);

    //draw the vertices in the VAO
    glDrawArrays(GL_TRIANGLES, 0, 3);

    //reset the state
    glBindVertexArray(0);
    glUseProgram(0);

    SDL_GL_SwapWindow(window);



  }

}