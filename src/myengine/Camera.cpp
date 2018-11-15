#include <glm/ext.hpp>

#include "Camera.h"
#include "Transform.h"

namespace myEngine
{
	Camera::Camera()
	{
		setDegFOV(90.0f);
	}
	Camera::~Camera()
	{

	}

	void Camera::setDegFOV(float _value)
	{
		m_DegFOV = _value;
	}

	glm::mat4 Camera::getViewMatrix()
	{
		return glm::inverse(getTransform()->getTransformMat());
	}
	float Camera::getRadFOV()
	{
		return glm::radians(m_DegFOV);
	}

	void Camera::debug()
	{
		std::cout << "    Camera" << std::endl;
	}


}