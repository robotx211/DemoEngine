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
	*	Stores the data of the 3 vertices which make up the face of a mesh
	*/
	struct Face
	{
		VertexData m_verticesData[3];
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

		void loadRect(glm::vec2 _size);
		void loadModel(std::string _modelAddress); //load model data into m_vertices

		int getVertexcount();
		std::shared_ptr<VertexArray> getModelVAO() { return m_VAO; }

		void upload();

	};

}

#endif // !MESH_H