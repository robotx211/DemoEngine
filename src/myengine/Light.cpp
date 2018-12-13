#include "Light.h"
#include "Transform.h"
#include "Camera.h"

namespace myEngine
{

	void Light::setShaderData(std::shared_ptr<ShaderProgram> _shader)
	{


		_shader->setUniform("in_LightCol", m_colour);
		_shader->setUniform("in_AmbientLightStrength", m_ambientStrength);

		_shader->setUniform("in_LightPos", getTransform()->getLocalPosition());

		_shader->setUniform("in_ViewPos", getCore()->getCurrentCamera()->getTransform()->getLocalPosition());
		_shader->setUniform("in_SpecularStrength", m_specularStrength);

	}

}