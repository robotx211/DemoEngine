#ifndef MESH_RENDERER_H
#define MESH_RENDERER_H

#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <exception>
#include <iostream>
#include <vector>

#include "Mesh.h"
#include "Component.h"

#include "VertexArray.h"
#include "ShaderProgram.h"

namespace myEngine
{

	//https://learnopengl.com/Model-Loading/Mesh

	class MeshRenderer : public Component
	{

	private:
		std::weak_ptr<Mesh> m_mesh; //meshes should be stored in a resources array (or something like that)

		//texture

		std::shared_ptr<ShaderProgram> m_shaderProg; //shader programs are stored in the mesh renderer

	public:

		void draw();

		void awake();
		void start();
		void update();
		void display();

		void debug();

		void setMesh(std::shared_ptr<Mesh> _mesh);
		void setTexture();
		void setShaders(std::string _vertShadAddress, std::string _fragShadAddress);


	};

}

#endif // !MESH_RENDERER_H



