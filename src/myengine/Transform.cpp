#define GLM_ENABLE_EXPERIMENTAL

#include <glm/ext.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/string_cast.hpp>

#include <iostream>

#include "Transform.h"


namespace myEngine {

	Transform::Transform()
	{
		m_localPosition = glm::vec3(0.0f);

		m_forward = glm::vec3(0.0f, 0.0f, -1.0f);
		m_up = glm::vec3(0.0f, 1.0f, 0.0f);
		m_left = glm::vec3(-1.0f, 0.0f, 0.0f);

		m_localOrientation = glm::quat(0, m_forward);

		m_localScale = glm::vec3(1.0f);
	}

	Transform::~Transform()
	{

	}

	//-------------TRANSLATION-------------

	glm::vec3 Transform::getLocalPosition()
	{
		return m_localPosition;
	}
	void Transform::setLocalPosition(glm::vec3 _pos)
	{
		m_localPosition = _pos;
	}

	void Transform::translate(glm::vec3 _vec)
	{
		m_localPosition += _vec;
	}
	void Transform::translate(float _x, float _y, float _z)
	{
		translate(glm::vec3(_x, _y, _z));
	}

	//-------------TRANSLATION-------------

	//-------------ROTATION-LOCAL-AXIS------------

	glm::quat Transform::getLocalOrientation()
	{
		return glm::normalize(m_localOrientation);
	}
	void Transform::setLocalOrientation(glm::quat _orient)
	{
		m_localOrientation = glm::normalize(_orient);

		glm::mat4 rotationMat = glm::mat4_cast(glm::normalize(m_localOrientation));
		m_forward = glm::normalize(rotationMat * glm::vec4(0, 0, -1, 0));
		m_up = glm::normalize(rotationMat * glm::vec4(0, 1, 0, 0));
		m_left = glm::normalize(rotationMat * glm::vec4(-1, 0, 0, 0));
	}

	void Transform::localAxisRotateQuaternion(glm::quat _quat)
	{
		m_localOrientation = glm::normalize(m_localOrientation * _quat);

		glm::mat4 rotationMat = glm::mat4_cast(glm::normalize(m_localOrientation));
		m_forward = glm::normalize(rotationMat * glm::vec4(0, 0, -1, 0));
		m_up = glm::normalize(rotationMat * glm::vec4(0, 1, 0, 0));
		m_left = glm::normalize(rotationMat * glm::vec4(-1, 0, 0, 0));

	}
	void Transform::localAxisRotateQuaternion(float _angle, glm::vec3 _axis)
	{
		localAxisRotateQuaternion(glm::angleAxis(_angle, _axis));
	}
	void Transform::localAxisRotateQuaternion(float _angle, float _x, float _y, float _z)
	{
		localAxisRotateQuaternion(_angle, glm::vec3(_x, _y, _z));
	}

	void Transform::localAxisRotateEulerRadians(glm::vec3 radians)
	{
		localAxisRotateQuaternion(glm::quat(radians));
	}
	void Transform::localAxisRotateEulerRadians(float _x, float _y, float _z)
	{
		localAxisRotateEulerRadians(glm::vec3(_x, _y, _z));
	}

	void Transform::localAxisRotateEulerDegrees(glm::vec3 degrees)
	{
		glm::vec3 radians = glm::radians(degrees);
		localAxisRotateQuaternion(glm::quat(radians));
	}
	void Transform::localAxisRotateEulerDegrees(float _x, float _y, float _z)
	{
		localAxisRotateEulerDegrees(glm::vec3(_x, _y, _z));
	}

	//-------------ROTATION-WORLD-AXIS------------

	void Transform::worldAxisRotateQuaternion(glm::quat _quat)
	{
		m_localOrientation = glm::normalize(_quat * m_localOrientation);

		glm::mat4 rotationMat = glm::mat4_cast(glm::normalize(m_localOrientation));
		m_forward = glm::normalize(rotationMat * glm::vec4(0, 0, -1, 0));
		m_up = glm::normalize(rotationMat * glm::vec4(0, 1, 0, 0));
		m_left = glm::normalize(rotationMat * glm::vec4(-1, 0, 0, 0));

	}
	void Transform::worldAxisRotateQuaternion(float _angle, glm::vec3 _axis)
	{
		worldAxisRotateQuaternion(glm::angleAxis(_angle, _axis));
	}
	void Transform::worldAxisRotateQuaternion(float _angle, float _x, float _y, float _z)
	{
		worldAxisRotateQuaternion(_angle, glm::vec3(_x, _y, _z));
	}

	void Transform::worldAxisRotateEulerRadians(glm::vec3 radians)
	{
		worldAxisRotateQuaternion(glm::quat(radians));
	}
	void Transform::worldAxisRotateEulerRadians(float _x, float _y, float _z)
	{
		worldAxisRotateEulerRadians(glm::vec3(_x, _y, _z));
	}


	void Transform::worldAxisRotateEulerDegrees(glm::vec3 degrees)
	{
		glm::vec3 radians = glm::radians(degrees);
		worldAxisRotateQuaternion(glm::quat(radians));
	}
	void Transform::worldAxisRotateEulerDegrees(float _x, float _y, float _z)
	{
		worldAxisRotateEulerDegrees(glm::vec3(_x, _y, _z));
	}

	//-------------ROTATION-------------

	//-------------SCALE-------------

	glm::vec3 Transform::getLocalScale()
	{
		return m_localScale;
	}
	void Transform::setLocalScale(glm::vec3 _sca)
	{
		m_localScale = _sca;
	}

	void Transform::scale(glm::vec3 _vec)
	{
		m_localScale *= _vec;
	}
	void Transform::scale(float _x, float _y, float _z)
	{
		scale(glm::vec3(_x, _y, _z));
	}

	//-------------SCALE-------------

	glm::mat4 Transform::getTransformMat()
	{

		glm::mat4 scaleMat = glm::scale(glm::mat4(1.0), m_localScale);

		glm::mat4 rotationMat = glm::mat4_cast(glm::normalize(m_localOrientation));
		m_forward = glm::normalize(rotationMat * glm::vec4(0, 0, -1, 0));

		glm::mat4 translationMat = glm::translate(glm::mat4(1.0), m_localPosition);

		return translationMat * rotationMat * scaleMat;

	}

  void Transform::debug()
  {
    std::cout << "    Transform" << std::endl;
  }

  void Transform::checkDirections()
  {
	  std::cout << "Fwd: " << glm::to_string(m_forward) << std::endl;
	  std::cout << "Orientation: " << glm::to_string(m_localOrientation) << std::endl;
  }
}