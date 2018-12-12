#include "Light.h"
#include "Transform.h"

namespace myEngine
{

	void Light::setShaderData(std::shared_ptr<ShaderProgram> _shader)
	{


		_shader->setUniform("in_LightCol", m_colour);
		_shader->setUniform("in_AmbientLightStrength", m_ambientStrength);

		_shader->setUniform("in_LightPos", getTransform()->getLocalPosition());

	}

}