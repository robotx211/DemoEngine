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

	/**
	*	Stores the position, texture coordinate and normal of a vertex
	*/
	struct VertexData
	{
		bool m_posCheck = false;
		bool m_texCheck = false;
		bool m_normCheck = false;

		glm::vec3 m_pos;
		glm::vec2 m_texCoord;
		glm::vec3 m_norm;
	};

	/**
	*	Stores the data of the vertices which make up the face of a mesh
	*/
	struct Face
	{
		std::vector<VertexData> m_verticesData;
	};

	/**
	*	Loads model data from an OBJ file
	*	Stores Vertex positions, Tex coordinates, and Normals and Mesh faces
	* Creates and fills the VBOs and VAO with the Model data
	*/
	class Mesh
	{

	private:

		std::vector<glm::vec3> m_positions;
		std::vector<glm::vec2> m_texCoords;
		std::vector<glm::vec3> m_normals;

		std::vector<Face> m_faces;

		bool m_posCheck = false;
		bool m_texCheck = false;
		bool m_normCheck = false;

		std::shared_ptr<VertexBuffer> m_posVBO;
		std::shared_ptr<VertexBuffer> m_texCoordsVBO;
		std::shared_ptr<VertexBuffer> m_normsVBO;

		std::shared_ptr<VertexArray> m_VAO;

	public:

		Mesh();
		Mesh(std::string _modelAddress);

		void loadRect();
		//load model data into m_vertices *NO LONGER WORKS*
		void loadModel(std::string _modelAddress); 

		/**
		* Fills a vector of shared pointers to Meshes, with meshes loaded from an OBJ
		*/
		static void loadModel(std::string _modelAddress, std::vector<std::shared_ptr<Mesh>> *_meshList);

		int getVertexcount();
		std::shared_ptr<VertexArray> getModelVAO() { return m_VAO; }

		glm::vec4 getVertexPositionMax() { return m_posVBO->getMax(); }
		glm::vec4 getVertexPositionMin() { return m_posVBO->getMin(); }
		glm::vec4 getVertexPositionRange() { return m_posVBO->getRange(); }

		static glm::vec4 getVertexPositionMaxFromMeshes(std::vector<std::shared_ptr<Mesh>> *_meshList);
		static glm::vec4 getVertexPositionMinFromMeshes(std::vector<std::shared_ptr<Mesh>> *_meshList);
		static glm::vec4 getVertexPositionRangeFromMeshes(std::vector<std::shared_ptr<Mesh>> *_meshList);
		static glm::vec4 getCentreFromMeshes(std::vector<std::shared_ptr<Mesh>> *_meshList);

		//void offsetVertexPositions(glm::vec4 _offset) { m_posVBO->offset(_offset); }
		//static void resetMeshCentre(std::vector<std::shared_ptr<Mesh>> *_meshList);

		void upload();

	};

}

#endif // !MESH_H