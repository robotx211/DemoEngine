#include "Mesh.h"

namespace myEngine
{

	std::shared_ptr<std::vector<glm::vec3>> Mesh::getVertexPositions()
	{
		std::shared_ptr<std::vector<glm::vec3>> returnVector = std::make_shared<std::vector<glm::vec3>>();

		for (int i = 0; i < m_vertices.size(); i++)
		{
			returnVector->push_back(m_vertices.at(i).m_positon);
		}

		return returnVector;
	}

	std::shared_ptr<std::vector<glm::vec3>> Mesh::getVertexNormals()
	{
		std::shared_ptr<std::vector<glm::vec3>> returnVector = std::make_shared<std::vector<glm::vec3>>();

		for (int i = 0; i < m_vertices.size(); i++)
		{
			returnVector->push_back(m_vertices.at(i).m_normal);
		}

		return returnVector;
	}

	std::shared_ptr<std::vector<glm::vec3>> Mesh::getVertexTexCoords()
	{
		std::shared_ptr<std::vector<glm::vec3>> returnVector = std::make_shared<std::vector<glm::vec3>>();

		for (int i = 0; i < m_vertices.size(); i++)
		{
			returnVector->push_back(m_vertices.at(i).m_texCoords);
		}

		return returnVector;
	}

}