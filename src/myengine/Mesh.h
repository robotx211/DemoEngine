#include <glm/glm.hpp>
#include <vector>
#include <memory>


namespace myEngine
{


	class Mesh
	{

		struct Vertex
		{
			glm::vec3 m_positon;
			glm::vec3 m_normal;
			glm::vec3 m_texCoords;
		};

		struct Texture
		{
			int m_id;
			std::string m_type; //diffuse, specular etc.
		};

	private:
		std::vector<Vertex> m_vertices;
		std::vector<int> m_indices;
		Texture m_textures;

	public:
		std::shared_ptr<std::vector<Vertex>> getVertices() { return std::make_shared<std::vector<Vertex>>(m_vertices); }

		std::shared_ptr<std::vector<glm::vec3>> getVertexPositions();
		std::shared_ptr<std::vector<glm::vec3>> getVertexNormals();
		std::shared_ptr<std::vector<glm::vec3>> getVertexTexCoords();

		std::shared_ptr<std::vector<int>> getIndices() { return std::make_shared<std::vector<int>>(m_indices); }

	};

}