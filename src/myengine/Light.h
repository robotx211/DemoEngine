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
	//base class for light will represent a point light
	class Light : public Component
	{

	private:
	protected:

		glm::vec3 m_colour;
		float m_ambientStrength; //ambient light strength
		float m_specularStrength;

	public:

		virtual void setColour(glm::vec3 _colour) { m_colour = _colour; }
		virtual glm::vec3 getColour() { return m_colour; }

		void setAmbientStrength(float _strength) { m_ambientStrength = _strength; }
		float getAmbientStrength() { return m_ambientStrength; }

		void setSpecularStrength(float _strength) { m_specularStrength = _strength; }
		float getSpecularStrength() { return m_specularStrength; }

		void setShaderData(std::shared_ptr<ShaderProgram> _shader);

	};

}


#endif // !LIGHT_H
