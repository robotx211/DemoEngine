#define GLM_ENABLE_EXPERIMENTAL

#include <glm/ext.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

#include "Transform.h"


namespace myEngine {

	Transform::Transform()
	{
		m_localPosition = glm::vec3(0.0f);

		m_localOrientation = glm::quat(glm::vec3(0.0f));

		m_localScale = glm::vec3(1.0f);
	}

	Transform::Transform(glm::vec3 _pos, glm::vec3 _sca)
	{
		m_localPosition = _pos;

		m_localScale = _sca;
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

	//-------------ROTATION-------------

	glm::quat Transform::getLocalOrientation()
	{
		return m_localOrientation;
	}
	void Transform::setLocalOrientation(glm::quat _orient)
	{
		m_localOrientation = _orient;
	}

	void Transform::rotateQuaternion(glm::quat _quat)
	{
		m_localOrientation = _quat * m_localOrientation;
	}
	void Transform::rotateQuaternion(float _angle, glm::vec3 _axis)
	{
		rotateQuaternion(glm::angleAxis(_angle, _axis));
	}
	void Transform::rotateQuaternion(float _angle, float _x, float _y, float _z)
	{
		rotateQuaternion(_angle, glm::vec3(_x, _y, _z));
	}

	void Transform::rotateEulerRadians(glm::vec3 radians)
	{
		rotateQuaternion(glm::quat(radians));
	}
	void Transform::rotateEulerDegrees(glm::vec3 degrees)
	{
		glm::vec3 radians = glm::radians(degrees);
		rotateQuaternion(glm::quat(radians));
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
		m_localScale += _vec;
	}
	void Transform::scale(float _x, float _y, float _z)
	{
		scale(glm::vec3(_x, _y, _z));
	}

	//-------------SCALE-------------

	glm::mat4 Transform::getTransformMat()
	{

		glm::mat4 scaleMat = glm::scale(glm::mat4(1.0), m_localScale);

		glm::mat4 rotationMat = glm::toMat4(m_localOrientation);

		glm::mat4 translationMat = glm::translate(glm::mat4(1.0), m_localPosition);

		return translationMat  * rotationMat  * scaleMat;

	}

  void Transform::debug()
  {
    std::cout << "    Transform" << std::endl;
  }



}