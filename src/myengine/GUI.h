#ifndef GUI_H
#define GUI_H

#include <glm/glm.hpp>
#include <memory>

#include "Component.h"
#include "ShaderProgram.h"
#include "VertexArray.h"
#include "Texture.h"
#include "RenderTexture.h"
#include "Mesh.h"

namespace myEngine
{
	class GUIRect : public Component
	{

	private:

		glm::vec2 m_size;
		glm::vec2 m_pos;

		glm::mat4 m_modelMat;

		std::shared_ptr<Mesh> m_mesh;
		std::shared_ptr<Texture> m_texture;
		std::shared_ptr<ShaderProgram> m_shaderProg;

	public:

		GUIRect();
		~GUIRect();

		void draw();

		void GUI();

		void setRect(glm::vec2 _pos, glm::vec2 _size);
		void setRect(float _x, float _y, float _w, float _h);

		void setTexture(std::shared_ptr<Texture> _texture);
		void setTexture(std::shared_ptr<RenderTexture> _renderTex);

		void setShaders(std::string _vertShadAddress, std::string _fragShadAddress);

	};

}

#endif // !GUI_H
