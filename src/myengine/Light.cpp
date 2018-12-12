#include "Light.h"

namespace myEngine
{

	void Light::setShaderData(std::shared_ptr<ShaderProgram> _shader)
	{


		_shader->setUniform("in_AmbientLightCol", m_colour);
		_shader->setUniform("in_AmbientLightStrength", m_strength);

		//glUseProgram(0);

	}

}