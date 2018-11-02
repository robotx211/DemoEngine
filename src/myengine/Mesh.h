#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
#include <vector>
#include <memory>
#include <fstream>
#include <iostream>
#include <string>

#include "VertexBuffer.h"
#include "VertexArray.h"
#include "ShaderProgram.h"

namespace myEngine
{

  struct VertexData
  {
    glm::vec3 m_pos;
    glm::vec2 m_texCoord;
    glm::vec3 m_norm;
  };

  struct Face
  {
    VertexData m_v1;
    VertexData m_v2;
    VertexData m_v3;
  };

  class Mesh
  {

  private:

    std::vector<glm::vec3> m_positions;
    std::vector<glm::vec2> m_texCoords;
    std::vector<glm::vec3> m_normals;

    std::vector<Face> m_faces;

    std::shared_ptr<VertexBuffer> m_posVBO;
    std::shared_ptr<VertexBuffer> m_texCoordsVBO;
    std::shared_ptr<VertexBuffer> m_normsVBO;

    std::shared_ptr<VertexArray> m_VAO;

    std::shared_ptr<ShaderProgram> m_shaderProg;

  public:

    Mesh();
    Mesh(std::string _modelAddress);

    void loadModel(std::string _modelAddress); //load model data into m_vertices

    void upload();

  };

}

#endif // !MESH_H