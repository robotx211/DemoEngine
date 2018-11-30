#include "Mesh.h"
#include "Utilities.h"
#include "enums.h"

namespace myEngine
{

	Mesh::Mesh()
	{

	}
	Mesh::Mesh(std::string _modelAddress)
	{
		loadModel(_modelAddress);
	}

	void Mesh::loadRect(glm::vec2 _size)
	{
		//doesn't actually need _size, that needs removing
		//a rect is a set 1 by 1 square, which gets scaled by the transform/GUIRect component

		m_posVBO = std::make_shared<VertexBuffer>();

		//(0,0) at centre

		m_posVBO->addVertex(glm::vec3(-0.5f, -0.5f, 0.0f)); //bot left
		m_posVBO->addVertex(glm::vec3(0.5f, 0.5f, 0.0f)); //top right
		m_posVBO->addVertex(glm::vec3(-0.5f, 0.5f, 0.0f)); //top left

		m_posVBO->addVertex(glm::vec3(-0.5f, -0.5f, 0.0f)); //bot left
		m_posVBO->addVertex(glm::vec3(0.5f, -0.5f, 0.0f)); //bot right
		m_posVBO->addVertex(glm::vec3(0.5f, 0.5f, 0.0f)); // top right

		//flips image, idk why
		m_texCoordsVBO = std::make_shared<VertexBuffer>();

		m_texCoordsVBO->addVertex(glm::vec2(0.0f, 0.0f));
		m_texCoordsVBO->addVertex(glm::vec2(1.0f, 1.0f));
		m_texCoordsVBO->addVertex(glm::vec2(0.0f, 1.0f));

		m_texCoordsVBO->addVertex(glm::vec2(0.0f, 0.0f));
		m_texCoordsVBO->addVertex(glm::vec2(1.0f, 0.0f));
		m_texCoordsVBO->addVertex(glm::vec2(1.0f, 1.0f));

		m_VAO = std::make_shared<VertexArray>();

		m_VAO->addBuffer(enums::ShaderAttribute::in_Position, m_posVBO);
		m_VAO->addBuffer(enums::ShaderAttribute::in_TexCoord, m_texCoordsVBO);

		upload();

	}
	void Mesh::loadModel(std::string _modelAddress)
	{

		/**
		* read each line
		* split each line into a vector of strings by white space
		* if line is useful, store it
		* if "v", store as vertex position
		* if "vt", store as texture coordinate
		* if "vn", store as normal
		* if "f" store as face
		* format: "f 1/1/1 2/2/1 3/3/1" - first number is the position index, second is the tex coord index, third is the normal index
		*/

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
						std::stof(seperatedCurrLine.at(1)),
						std::stof(seperatedCurrLine.at(2)),
						std::stof(seperatedCurrLine.at(3))
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
							vertexIData.push_back(std::stoi(vertexSData.at(j)));
						}
					}

					//create new VertexData, populate and push to verticesData
					VertexData currVertexData;
					if (vertexIData.at(0) != -1)
					{
						currVertexData.m_posCheck = true;
						currVertexData.m_pos = m_positions.at(vertexIData.at(0) - 1); //need to -1, as obj indexes are 1 indexed, not 0 indexed
					}
					if (vertexIData.at(1) != -1)
					{
						currVertexData.m_texCheck = true;
						currVertexData.m_texCoord = m_texCoords.at(vertexIData.at(1) - 1);
					}
					if (vertexIData.at(2) != -1)
					{
						currVertexData.m_normCheck = true;
						currVertexData.m_norm = m_normals.at(vertexIData.at(2) - 1);
					}
					verticesData.push_back(currVertexData);
				}

				//triangulation check
				Face currFace;
				if (verticesData.size() == 3)
				{
					//already triangulated :D

					currFace.m_verticesData[0] = verticesData.at(0);
					currFace.m_verticesData[1] = verticesData.at(1);
					currFace.m_verticesData[2] = verticesData.at(2);

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

		//put data into VBOs and VAO

		m_posCheck = m_faces.at(0).m_verticesData[0].m_posCheck;
		m_texCheck = m_faces.at(0).m_verticesData[0].m_texCheck;
		m_normCheck = m_faces.at(0).m_verticesData[0].m_normCheck;

		if (m_posCheck == true)
		{
			m_posVBO = std::make_shared<VertexBuffer>();

		}
		if (m_texCheck == true)
		{
			m_texCoordsVBO = std::make_shared<VertexBuffer>();

		}
		if (m_normCheck == true)
		{
			m_normsVBO = std::make_shared<VertexBuffer>();
		}

		m_VAO = std::make_shared<VertexArray>();

		for (size_t i = 0; i < m_faces.size(); i++)
		{

			Face &thisFace = m_faces.at(i);

			for (int j = 0; j < 3; j++)
			{

				if (m_posCheck == true)
				{
					m_posVBO->addVertex(thisFace.m_verticesData[j].m_pos);
				}
				if (m_texCheck == true)
				{
					m_texCoordsVBO->addVertex(thisFace.m_verticesData[j].m_texCoord);
				}
				if (m_normCheck == true)
				{
					m_normsVBO->addVertex(thisFace.m_verticesData[j].m_norm);
				}

			}

		}

		if (m_posCheck == true)
		{
			m_VAO->addBuffer(enums::ShaderAttribute::in_Position, m_posVBO);
		}
		if (m_texCheck == true)
		{
			m_VAO->addBuffer(enums::ShaderAttribute::in_TexCoord, m_texCoordsVBO);
		}
		if (m_normCheck == true)
		{
			m_VAO->addBuffer(enums::ShaderAttribute::in_Normal, m_normsVBO);
		}

		upload();

	}

	void Mesh::upload()
	{
		if (m_posCheck == true)
		{
			m_posVBO->upload();
		}
		if (m_texCheck == true)
		{
			m_texCoordsVBO->upload();
		}
		if (m_normCheck == true)
		{
			m_normsVBO->upload();
		}

		m_VAO->upload();
	}

	int Mesh::getVertexcount()
	{
		int vertexCount = m_posVBO->getDataSize() / m_posVBO->getComponents();

		return vertexCount;
	}


}