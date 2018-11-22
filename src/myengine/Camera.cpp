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

	void Camera::setAspectRatio(float _aspect)
	{
		m_aspectRatio = _aspect;
	}
	void Camera::setAspectRatio(float _width, float _height)
	{
		m_aspectRatio = _width / _height;
	}
	void Camera::setAspectRatio(int _width, int _height)
	{
		m_aspectRatio = (float)(_width / _height);
	}

	glm::mat4 Camera::getViewMatrix()
	{
		return glm::inverse(getTransform()->getTransformMat());
	}
	float Camera::getRadFOV()
	{
		return glm::radians(m_DegFOV);
	}
	float Camera::getAspectRatio()
	{
		return m_aspectRatio;
	}

	void Camera::setRenderTexture(std::shared_ptr<RenderTexture> _renderTex)
	{
		m_renderTex = _renderTex;
	}
	void Camera::bindRenderTexFramebuffer()
	{
		if (isRenderTexCamera())
		{
			m_renderTex->bindFrameBuffer();
		}
	}

	void Camera::debug()
	{
		std::cout << "    Camera" << std::endl;
	}


}