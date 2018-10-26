#include "Mesh.h"
#include "Utilities.h"

namespace myEngine
{

  Mesh::Mesh()
  {

  }
  Mesh::Mesh(std::string _modelAddress)
  {
    loadModel(_modelAddress);
  }

  void Mesh::loadModel(std::string _modelAddress)
  {

    //read each line
    //split each line into a vector of strings by white space
    //if line is useful, store it
      //if "v", store as vertex position
      //if "vt", store as texture coordinate
      //if "vn", store as normal
      //if "f" store as face
        //format: "f 1/1/1 2/2/1 3/3/1" - first number is the position index, second is the tex coord index, third is the normal index

    std::ifstream objfile(_modelAddress);
    std::string currLine;
    std::vector<std::string> seperatedCurrLine;

    while (std::getline(objfile, currLine))
    {

      splitStringByWhitespace(currLine, seperatedCurrLine);

      if (seperatedCurrLine.at(0) == "v") 
      {
        //vertex position
        //should be 4 long {v, x, y, z}

        m_positions.push_back(
          glm::vec3(
            std::stof( seperatedCurrLine.at(1) ), 
            std::stof( seperatedCurrLine.at(2) ),
            std::stof( seperatedCurrLine.at(3) )
            ) 
          );
      }
      else if (seperatedCurrLine.at(0) == "vt")
      {
        //tex coord
        //should be 3 long {v, s, t}

        m_texCoords.push_back(
          glm::vec2(
            std::stof(seperatedCurrLine.at(1)),
            std::stof(seperatedCurrLine.at(2))
          )
        );
      }
      else if (seperatedCurrLine.at(0) == "vn")
      {
        //normal
        //should be 4 long {v, x, y, z}

        m_normals.push_back(
          glm::vec3(
            std::stof(seperatedCurrLine.at(1)),
            std::stof(seperatedCurrLine.at(2)),
            std::stof(seperatedCurrLine.at(3))
          )
        );
      }
      else if (seperatedCurrLine.at(0) == "f")
      {
        //face
        //if 3 long, is already triangulated
        //if longer, is not (eg. 4 is a quad)
          //therefore need to triangulate it

        //TODO
      }

    }

  }

  void Mesh::upload()
  {
    m_posVBO->upload();
    m_texCoordsVBO->upload();
    m_normsVBO->upload();

    m_VAO->upload();
  }

}