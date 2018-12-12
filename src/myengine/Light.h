#ifndef LIGHT_H
#define LIGHT_H

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <glm/ext.hpp>
#include <memory>

#include "Component.h"
#include "ShaderProgram.h"

namespace myEngine
{
	//base class for light will represent ambient light
	class Light : public Component
	{

	private:
	protected:

		glm::vec3 m_colour;
		float m_strength; //ambient light strength

	public:

		virtual void setColour(glm::vec3 _colour) { m_colour = _colour; }
		virtual glm::vec3 getColour() { return m_colour; }

		void setStrength(float _strength) { m_strength = _strength; }
		float getStrength() { return m_strength; }

		void setShaderData(std::shared_ptr<ShaderProgram> _shader);

	};

}


#endif // !LIGHT_H
