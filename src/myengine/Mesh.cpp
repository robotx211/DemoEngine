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

      if (seperatedCurrLine.size() == 0)
      {
        continue;
      }

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
          //therefore needs triangulating (externally)

        //note: relys on "f v/t/n v/t/n ..." format
        //or "f v//n v//n"

        //create vector of VertexDatas to store each vertex data
        std::vector<VertexData> verticesData;

        //go through each string (vertex data) after the first "f" string and push the VertexData to verticesData
        for (size_t i = 1; i < seperatedCurrLine.size(); i++)
        {
          //split vertex data into vector of strings
          std::vector<std::string> vertexSData;
          splitStringByChar(seperatedCurrLine.at(i), '/', vertexSData, true);

          //turn vector of strings into vector of ints (vertex data indices)
          std::vector<int> vertexIData;
          for (size_t j = 0; j < vertexSData.size(); j++)
          {
            if (vertexSData.at(j) == " ")
            {
              vertexIData.push_back(-1);
            }
            else
            {
              vertexIData.push_back( std::stoi( vertexSData.at(j) ) );
            }
          }

          //create new VertexData, populate and push to verticesData
          VertexData currVertexData;
          if (vertexIData.at(0) != -1)
          {
            currVertexData.m_pos = m_positions.at(vertexIData.at(0) - 1); //need to -1, as obj indexes are 1 indexed, not 0 indexed
          }
          if (vertexIData.at(1) != -1)
          {
            currVertexData.m_texCoord = m_positions.at(vertexIData.at(1) - 1);
          }
          if (vertexIData.at(2) != -1)
          {
            currVertexData.m_norm = m_positions.at(vertexIData.at(2) - 1);
          }
          verticesData.push_back(currVertexData);
        }

        //triangulation check
        Face currFace;
        if (verticesData.size() == 3)
        {
          //already triangulated :D

          currFace.m_v1 = verticesData.at(0);
          currFace.m_v2 = verticesData.at(1);
          currFace.m_v3 = verticesData.at(2);

          m_faces.push_back(currFace);
        }
        else 
        {
          //not triangulated, throw exception

          std::cout << "Error: Model contains N-Gons!";
          std::exception();

        }

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