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
	void Camera::setAspectRatioToWindowSize()
	{
		m_aspectRatio = getCore()->getWindowObject()->getWidth() / getCore()->getWindowObject()->getHeight();
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
		if (m_aspectRatio <= 0)
		{
			return (float)getCore()->getWindowObject()->getWidth() / (float)getCore()->getWindowObject()->getHeight();
		}

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
		//std::cout << "    Camera" << std::endl;
	}


}