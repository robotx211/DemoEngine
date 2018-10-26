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
		std::shared_ptr<Mesh> m_mesh;

		std::string m_vertexShaderSrc =
			"attribute vec3 in_Position;            " \
			"                                       " \
			"void main()                            " \
			"{                                      " \
			" gl_Position = vec4(in_Position, 1.0); " \
			"}                                      ";

		std::string m_fragmentShaderSrc =
			"void main()                        " \
			"{                                  " \
			" gl_FragColor = vec4(0, 0, 0, 1);  " \
			"}                                  ";

	public:

		void draw();

		void awake();
		void start();
		void update();
		void display();

		void debug();



	};

}



