#ifndef LIGHT_H
#define LIGHT_H

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <glm/ext.hpp>
#include <memory>

#include "Component.h"
#include "ShaderProgram.h"
#include "Core.h"

namespace myEngine
{
	/**
	* Base light class, acts as a point light (requires a transform component to work)
	*/
	class Light : public Component
	{

	private:
	protected:

		glm::vec3 m_colour; ///Colour of the light
		float m_ambientStrength; ///Strength of the ambient light (how much light is ambient)
		float m_specularStrength; ///Intensity of the specular light

	public:

		virtual void setColour(glm::vec3 _colour) { m_colour = _colour; }
		virtual glm::vec3 getColour() { return m_colour; }

		void setAmbientStrength(float _strength) { m_ambientStrength = _strength; }
		float getAmbientStrength() { return m_ambientStrength; }

		void setSpecularStrength(float _strength) { m_specularStrength = _strength; }
		float getSpecularStrength() { return m_specularStrength; }

		/**
		* Sets the uniforms needed to calculate ambient, diffuse and specular lighting
		*/
		void setShaderData(std::shared_ptr<ShaderProgram> _shader, std::shared_ptr<Core> _core);

	};

}


#endif // !LIGHT_H
